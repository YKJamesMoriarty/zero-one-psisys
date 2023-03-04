/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "../../domain/do/Measurement/MeasurementDO.h"
#include "MeasurementService.h"
#include "../../dao/Measurement/MeasurementDAO.h"
#include "SnowFlake.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../../lib-common/include/FastDfsClient.h"
#include "../../../lib-common/include/CharsetConvertHepler.h"
#include "../../lib-common/include/ExcelComponent.h"
#include <map>
using namespace std;

const int datacenterId = 1;
const int machineId = 2;

//��ҳ��ѯ��������
PageVO<MeasurementVO> MeasurementService::listAll(const MeasurementQuery& query)
{
	//�������ض���
	PageVO<MeasurementVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	MeasurementDO obj;
	obj.setName(query.getName());
	MeasurementDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<MeasurementDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MeasurementVO> vr;
	for (MeasurementDO sub : result)
	{
		MeasurementVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setSymbol(sub.getSymbol());
		vo.setFactor(sub.getFactor());
		vo.setIs_enabled(sub.getIs_enabled() == 1 ? CharsetConvertHepler::ansiToUtf8("��") : CharsetConvertHepler::ansiToUtf8("��"));
		vo.setCreate_time(sub.getCreate_time());
		vo.setCreate_by(sub.getCreate_by());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

//��ѯָ����λ���Ӽ��б�
std::list<MeasurementVO> MeasurementService::queryKidData(const MeasurementKidQuery& query)
{
	MeasurementVO vo;
	MeasurementDAO dao;
	list<MeasurementDO> result = dao.selectKidData(query.getId());
	list<MeasurementVO> vr;
	for (MeasurementDO sub : result)
	{
		vo.setName(sub.getName());
		vo.setSymbol(sub.getSymbol());
		vo.setFactor(sub.getFactor());
		vo.setIs_enabled(sub.getIs_enabled() == 1 ? CharsetConvertHepler::ansiToUtf8("��") : CharsetConvertHepler::ansiToUtf8("��"));
		vo.setCreate_time(sub.getCreate_time());
		vo.setCreate_by(sub.getCreate_by());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vr.push_back(vo);
	}
	return vr;
}

//��ѯָ����λ����ϸ��Ϣ
MeasurementVO MeasurementService::queryDetailData(const MeasurementAppQuery& query)
{
	MeasurementVO vo;
	MeasurementDAO dao;
	list<MeasurementDO> vr = dao.selectById(query.getId());
	if (vr.size() == 0) return vo;
	list<MeasurementDO>::iterator it = vr.begin();
	MeasurementDO data = vr.front();
	if (vr.size() > 0)
	{
		vo.setName(data.getName());
		vo.setSymbol(data.getSymbol());
		vo.setFactor(data.getFactor());
		vo.setIs_enabled(data.getIs_enabled() == 1 ? CharsetConvertHepler::ansiToUtf8("��") : CharsetConvertHepler::ansiToUtf8("��"));
		vo.setCreate_time(data.getCreate_time());
		vo.setCreate_by(data.getCreate_by());
		vo.setUpdate_time(data.getUpdate_time());
		vo.setUpdate_by(data.getUpdate_by());
	}
	else
	{
		return vo;
	}
	return vo;
}

//����������λsave
MeasurementVO MeasurementService::save(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	MeasurementVO vo;

	vo.setName(dto.getName());
	vo.setSymbol(dto.getSymbol());
	vo.setFactor(dto.getFactor());
	vo.setIs_enabled(dto.getIs_enabled());
	vo.setCreate_by(payload.getUsername());

	// ��Ӹ��ڵ�
	if (dto.getPid() == "")
	{
		vo.setCreate_time(saveData(dto, payload));
	}
	// ����ӽڵ�
	else
	{
		vo.setCreate_time(saveKidData(dto, payload));
	}
	return vo;
}

//����������λ
string MeasurementService::saveData(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	MeasurementDO data;
	SnowFlake sf(datacenterId, machineId);
	SimpleDateTimeFormat sdt;
	string nowTime = sdt.format();
	//��װ����
	data.setId(to_string(sf.nextId()));
	data.setName(dto.getName());
	data.setSymbol(dto.getSymbol());
	data.setHas_child(dto.getHas_child() == 1 ? 1 : 0);
	data.setPid("0");
	data.setFactor(dto.getFactor());
	data.setIs_enabled(dto.getIs_enabled() == CharsetConvertHepler::ansiToUtf8("��") ? 1 : 0);
	data.setCreate_time(nowTime);
	data.setCreate_by(payload.getUsername());
	//ִ���������
	MeasurementDAO dao;
	if (dao.insert(data) == 1)
	{
		return nowTime;
	}
	else
	{
		return "";
	}
}

// ����������λ���Ӽ�������λ
string MeasurementService::saveKidData(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	MeasurementDO data;
	MeasurementDAO dao;

	SnowFlake sf(datacenterId, machineId);
	SimpleDateTimeFormat sdt;
	string nowTime = sdt.format();
	//��װDO���ݸ�dao��
	MeasurementDO index;
	list<MeasurementDO> vr = dao.selectById(dto.getPid());
	if (vr.empty())
	{
		return "";
	}
	index = vr.front();
	data.setPid(index.getId());
	data.setId(to_string(sf.nextId()));
	data.setName(dto.getName());
	data.setSymbol(dto.getSymbol());
	data.setHas_child(0);
	data.setFactor(dto.getFactor());
	data.setIs_enabled(dto.getIs_enabled() == CharsetConvertHepler::ansiToUtf8("��") ? 1 : 0);
	data.setCreate_time(nowTime);
	data.setCreate_by(payload.getUsername());
	//����pname��has_child
	int a;
	if (index.getHas_child() != 1)
	{
		a = dao.updateHas_child(1, index.getId());
	}
	else
	{
		a = 1;
	}
	int b = dao.insert(data);
	//�ж���������Ƿ�ɹ�
	if (a && b)
	{
		return nowTime;
	}
	else
	{
		return "";
	}
}

//�޸ļ�����λ
MeasurementVO MeasurementService::updateData(const MeasurementModifyDTO& dto, const PayloadDTO& payload)
{
	SimpleDateTimeFormat sdt;
	string nowTime = sdt.format();
	//��װ��������
	MeasurementDO data;
	data.setId(dto.getId());
	data.setName(dto.getName());
	data.setSymbol(dto.getSymbol());
	data.setFactor(dto.getFactor());
	data.setIs_enabled(dto.getIs_enabled() == CharsetConvertHepler::ansiToUtf8("��") ? 1 : 0);
	data.setUpdate_time(nowTime);
	data.setUpdate_by(payload.getUsername());
	//ִ�������޸�
	MeasurementDAO dao;
	MeasurementVO vo;
	if (dao.update(data) == 1)
	{
		vo.setName(dto.getName());
		vo.setSymbol(dto.getSymbol());
		vo.setFactor(dto.getFactor());
		vo.setIs_enabled(dto.getIs_enabled());
		vo.setUpdate_time(nowTime);
		vo.setUpdate_by(payload.getUsername());
		vo.setCreate_time(dao.selectById(dto.getId()).front().getCreate_time());
		vo.setCreate_by(dao.selectById(dto.getId()).front().getCreate_by());
		return vo;
	}
	return vo;
}

//ɾ������
bool MeasurementService::removeData(const string& id)
{
	MeasurementDAO dao;
	list<MeasurementDO> vr;
	int row = 0;
	vr = dao.selectById(id);
	// ��������
	dao.getSqlSession()->beginTransaction();

	//���ɾ�����ǻ�׼��λ
	if (vr.front().getHas_child() == 1)
	{
		row = dao.deleteById(id);
		size_t num = dao.selectByPid(id).size();
		size_t count = num;
		while (count > 0)
		{
			row += dao.deleteByPid(id);
			count--;
		}
		//���ϻ�׼��λɾ��һ��
		num++;
		if (row == num)
		{
			// ɾ����׼��λ��������ύ
			dao.getSqlSession()->commitTransaction();
			return true;
		}
		else
		{
			// ɾ����׼��λʧ������ع�
			dao.getSqlSession()->rollbackTransaction();
			cout << "dao.deleteById fail" << endl;
			return false;
		}
	}
	//���ɾ���ǻ�׼��λ���Ӽ���λ
	else
	{
		if (dao.selectById(vr.front().getPid()).size() == 1)
		{
			row = dao.deleteById(id);
			row += dao.updateHas_child(0, vr.front().getPid());
			if (row == 2)
			{
				// ɾ����׼��λ�Ӽ���λ��������ύ
				dao.getSqlSession()->commitTransaction();
				return true;
			}
			else
			{
				// ɾ����׼��λ�Ӽ���λʧ������ع�
				dao.getSqlSession()->rollbackTransaction();
				cout << "dao.deleteById fail" << endl;
				return false;
			}
		}
		else
		{
			row = dao.deleteById(id);
			if (row == 1)
			{
				// ɾ����׼��λ�Ӽ���λ��������ύ
				dao.getSqlSession()->commitTransaction();
				return true;
			}
			else
			{
				// ɾ����׼��λ�Ӽ���λʧ������ع�
				dao.getSqlSession()->rollbackTransaction();
				cout << "dao.deleteById fail" << endl;
				return false;
			}
		}
	}
}

//�ļ�����
bool MeasurementService::saveFileData(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	SnowFlake sf(datacenterId, machineId);
	SimpleDateTimeFormat sdt;
	string nowTime = sdt.format();

	MeasurementDAO dao;
	MeasurementDO index;
	list<MeasurementDO> vt;

	MeasurementImportFileDO Fdo;
	map<string, string> Map;
	list<string> hasChildPid;
	ExcelComponent excel;

	// TODO������У��
	if (!dto.getFiles().size())
	{
		return false;
	}

	// ��ȡ�ļ���DO
	string fileName = dto.getFiles().front();
	string sheetName = CharsetConvertHepler::ansiToUtf8("Sheet1");
	auto readData = excel.readIntoVector(fileName, sheetName);
	int idx = 0;
	for (auto row : readData)
	{
		if (!idx) {
			idx++;
			continue;
		}
		MeasurementDO Do;
		Do.setId(to_string(sf.nextId()));
		Do.setName(row[0]);
		Do.setSymbol(row[1]);
		Do.setHas_child(row[2] == CharsetConvertHepler::ansiToUtf8("��") ? 1 : 0);
		Do.setFactor(stod(row[4]));
		Do.setIs_enabled(row[5] == CharsetConvertHepler::ansiToUtf8("��") ? 1 : 0);
		Do.setCreate_time(nowTime);
		Do.setCreate_by(payload.getUsername());
		// TODO:����У��
		if (row[3] == "")
		{
			Do.setPid("0");
		}
		else
		{
			vt = dao.selectByName(row[3]);
			if (vt.empty())
			{
				//�޷��ڵ�ǰ���ݿ�����鵽pid������Ϊ0��������map������
				Do.setPid("0");
				Map.insert(pair<string, string>(Do.getId(), row[3]));
			}
			else
			{
				index = vt.front();
				Do.setPid(index.getId());
				// TODO���ж��Ƿ���Ҫ�޸�
				if (index.getHas_child() != 1)
				{
					hasChildPid.push_back(index.getId());
				}
			}
		}
		Fdo.addImportItem(Do);
	}

	// ��������
	dao.getSqlSession()->beginTransaction();

	// 1 ��������
	uint64_t num1 = dao.ImportFile(Fdo);
	if (num1 != Fdo.getImport().size()) 
	{
		// ��������ʧ������ع�
		dao.getSqlSession()->rollbackTransaction();
		cout << "dao.ImportFile fail" << endl;
		return false;
	}
	else if (!Map.size() && !hasChildPid.size())
	{
		// ����������������ύ
		dao.getSqlSession()->commitTransaction();
		return true;
	}

	// 2 �����׼��λ���Ӽ���λ�Ĺ�ϵ ���ݽ���pid����
	uint64_t num2 = 0;
	for (auto Do : Map)
	{
		//���һ�׼��λ
		vt = dao.selectByName(Do.second);
		if (vt.empty()) break;
		index = vt.front();
		//����pid
		int row = 0;
		row = dao.updatePid(index.getId(), Do.first);
		
		if (row != 1) break;
		num2++;
	}

	if (num2 != Map.size())
	{
		// �����ӹ�ϵʧ������ع�
		dao.getSqlSession()->rollbackTransaction();
		cout << "pid update fail" << endl;
		return false;
	}
	else if(!hasChildPid.size())
	{
		// �����׼��λ֮��Ĺ�ϵ��������ύ
		dao.getSqlSession()->commitTransaction();
		return true;
	}

	// 3 ����Has_child
	int row = 0;
	for (auto pid : hasChildPid)
	{
		//����has_child
		row += dao.updateHas_child(1, pid);
	}

	if (row != hasChildPid.size())
	{
		// �������Has_childʧ������ع�
		dao.getSqlSession()->rollbackTransaction();
		cout << "hasChildPid update fail" << endl;
		return false;
	}
	else
	{
		// �������ݲ�����������ύ
		dao.getSqlSession()->commitTransaction();
		return true;
	}
}

//�ļ�����(�����ݿ��ȡ����)
bool MeasurementService::getData(const StringIDs& dto, vector<vector<string>>& data)
{
	//TODO:����У��
	if (dto.getId().empty())
	{
		return false;
	}
	MeasurementDAO dao;
	list<MeasurementDO> result;

	for (auto str : dto.getId())
	{
		list<MeasurementDO> index;
		index = dao.selectExportFile(str);
		if (index.empty())continue;
		result.push_back(index.front());
	}

	for (MeasurementDO sub : result)
	{
		vector<string> row;
		row.push_back(sub.getName());
		row.push_back(sub.getSymbol());
		row.push_back(sub.getHas_child() == 1 ? CharsetConvertHepler::ansiToUtf8("��") : CharsetConvertHepler::ansiToUtf8("��"));
		if (sub.getPid() == "0")
		{
			row.push_back(sub.getPid());
		}
		else
		{
			if (dao.selectById(sub.getPid()).empty())
			{
				return false;
			}
			row.push_back(dao.selectById(sub.getPid()).front().getName());
		}
		row.push_back(to_string(sub.getFactor()));
		row.push_back(sub.getIs_enabled() == 1 ? CharsetConvertHepler::ansiToUtf8("��") : CharsetConvertHepler::ansiToUtf8("��"));
		data.push_back(row);
	}
	return true;
}