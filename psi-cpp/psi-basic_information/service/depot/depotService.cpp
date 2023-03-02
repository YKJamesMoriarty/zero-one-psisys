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
#include "DepotService.h"
#include "../../../lib-common/include/SnowFlake.h"

const int datacenterId = 1;
const int machineId = 2;

PageVO<DepotVO> DepotService::listAll(const DepotQuery& query)
{
	//�������ض���
	PageVO<DepotVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	DepotDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	
	DepotDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	obj.setPid("0");
	pages.setTotal(dao.count(obj));
	pages.calcPages();
	//��Ϊ�û�δ�����κ���Ϣ����������һ����Ϣ�Ĳ���
	if (obj.getName() == "" && obj.getCode() == "")
	{
		obj.setPid("0");
		//DO���ս����
		list<DepotDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
		list<DepotVO> vr;
		for (DepotDO sub : result)
		{
			DepotVO vo;
			vo.setName(sub.getName());
			vo.setCode(sub.getCode());
			vo.setAuxName(sub.getAuxName());
			vo.setCreationPeo(sub.getCreationPeo());
			vo.setCreationTime(sub.getCreationTime());
			vo.setId(sub.getId());
			vo.setModiPeo(sub.getModiPeo());
			vo.setModiTime(sub.getModiTime());
			vo.setRemarks(sub.getRemarks());
			vo.setStart(sub.getStart());
			vo.setPhone(sub.getPhone());
			vr.push_back(vo);
		}
		pages.setRows(vr);
	}
	else
	{
		//DO���ս����
		obj.setPid("");
		list<DepotDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
		//VO���ؽ����
		list<DepotVO> vr;
		//������ӽڵ㣬�ҵ����ĸ��ڵ�
		DepotDO sub = result.front();
		while (sub.getPid() != "0")
		{
			obj.setId(sub.getPid());
			obj.setPid("");
			obj.setCode("");
			obj.setName("");
			result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
			sub = result.front();
			obj.setPid(sub.getPid());
		}
		//ת����vo
		DepotVO vo;
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setAuxName(sub.getAuxName());
		vo.setCreationPeo(sub.getCreationPeo());
		vo.setCreationTime(sub.getCreationTime());
		vo.setId(sub.getId());
		vo.setModiPeo(sub.getModiPeo());
		vo.setModiTime(sub.getModiTime());
		vo.setRemarks(sub.getRemarks());
		vo.setStart(sub.getStart());
		vo.setPhone(sub.getPhone());
		vr.push_back(vo);
		
		pages.setRows(vr);
	}
	return pages;
}

list<DepotVO> DepotService::getKid(const OnlyValueQuery& query)
{
	// ��ȡ����id
	DepotDO obj;
	obj.setPid(query.getId());
	// ��ȡ�Ӽ��ֿ�DO
	DepotDAO dao;
	list<DepotDO> result =  dao.selectKid(obj);
	list<DepotVO> vr;
	for (DepotDO sub : result)
	{
		DepotVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setAuxName(sub.getAuxName());
		vo.setPhone(sub.getPhone());
		vo.setStart(sub.getStart());
		vo.setRemarks(sub.getRemarks());
		vo.setCreationPeo(sub.getCreationPeo());
		vo.setCreationTime(sub.getCreationTime());
		vo.setModiPeo(sub.getModiPeo());
		vo.setModiTime(sub.getModiTime());
		// ʣ�µ�����
		vr.push_back(vo);
	}
	return vr;
}

DepotDetailVO DepotService::listDetail(const OnlyValueQuery& query)
{
	//������ѯ����
	DepotDO obj;
	obj.setName("");
	obj.setCode(query.getCode());

	DepotDAO dao;
	std::list<DepotDO> result = dao.selectDetail(obj);
	//��ѯ���ڵ�����
	DepotDO sub = result.front();
	obj.setCode("");
	DepotDetailVO vo;
	if (sub.getPid() != "0")
	{
		obj.setId(sub.getPid());
		result = dao.selectDetail(obj);
		DepotDO psub = result.front();
		vo.setPid(psub.getName());
	}
	//ת��Ϊvo
	vo.setNext(sub.getHasChild());
	vo.setCode(sub.getCode());
	vo.setName(sub.getName());
	vo.setAuxName(sub.getAuxName());
	vo.setPhone(sub.getPhone());
	vo.setStart(sub.getStart());
	vo.setRemarks(sub.getRemarks());
	return vo;
}

DepotActionInfoVO DepotService::listInfo(const OnlyValueQuery& query)
{
	//������ѯ����
	DepotDO obj;
	obj.setName("");
	obj.setCode(query.getCode());

	DepotDAO dao;
	std::list<DepotDO> result = dao.selectDetail(obj);

	DepotDO sub = result.front();
	obj.setCode("");
	DepotActionInfoVO vo;

	vo.setCreationTime(sub.getCreationTime());
	vo.setCreationPeo(sub.getCreationPeo());
	vo.setModiTime(sub.getModiTime());
	vo.setModiPeo(sub.getModiPeo());

	return vo;
}

bool DepotService::getData(const DepotQuery& query, vector<vector<string>>& data)
{
	//��ѯ����������
	DepotDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	DepotDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return false;
	}

	//����ҳ��ѯ����
	list<DepotDO> result = dao.selectWithPage(obj, 0, 0);
	for (DepotDO sub : result)
	{
		vector<string> row;
		row.emplace_back(sub.getName());
		row.emplace_back(sub.getCode());
		row.emplace_back(sub.getAuxName());
		row.emplace_back(sub.getPhone());
		row.emplace_back(to_string(sub.getStart()));
		row.emplace_back(sub.getRemarks());
		row.emplace_back(sub.getCreationPeo());
		row.emplace_back(sub.getCreationTime());
		row.emplace_back(sub.getModiPeo());
		row.emplace_back(sub.getModiTime());
		// ʣ�µ�����
		data.emplace_back(row);
	}
	return true;
}

bool DepotService::getDataById(const OnlyValueQuery& query, vector<vector<string>>& data)
{
	//��ѯ����������
	DepotDAO dao;
	// �ָ�ID
	string str = query.getId(), delimiters = " |";
	vector<string>Ids;
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos)
	{
		Ids.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
	//��ѯ����
	for(auto id:Ids){
		DepotDO obj;
		obj.setId(id);
		list<DepotDO> result = dao.getDataById(obj);
		DepotDO sub = result.front();
		vector<string> row;
		row.emplace_back(sub.getName());
		row.emplace_back(sub.getCode());
		row.emplace_back(sub.getAuxName());
		row.emplace_back(sub.getPhone());
		row.emplace_back(to_string(sub.getStart()));
		row.emplace_back(sub.getRemarks());
		row.emplace_back(sub.getCreationPeo());
		row.emplace_back(sub.getCreationTime());
		row.emplace_back(sub.getModiPeo());
		row.emplace_back(sub.getModiTime());
		// ʣ�µ�����
		data.emplace_back(row);
	}
	return true;
}

int DepotService::saveData(const DepotDTO& dto, const string Username)
{
	//��װ����
	DepotDO data;
	SnowFlake sf(datacenterId, machineId);
	data.setId(to_string(sf.nextId()));
	// ���pid��Ϊ�գ���Ҫ�޸ĸ�����has_child
	data.setPid(dto.getPid().empty() ? "0" : dto.getPid());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	data.setRemarks(dto.getRemarks());
	data.setCreationPeo(Username);
	data.setCreationTime(SimpleDateTimeFormat::format());
	//ִ���������
	DepotDAO dao;
	return dao.insertDepot(data);
}

int DepotService::saveKidData(const DepotDTO& dto, const string Username)
{
	//��װ����
	DepotDO data;
	SnowFlake sf(datacenterId, machineId);
	data.setId(to_string(sf.nextId()));
	data.setPid(dto.getPid());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	data.setRemarks(dto.getRemarks());
	data.setCreationPeo(Username);
	data.setCreationTime(SimpleDateTimeFormat::format());
	//ִ���������
	DepotDAO dao;
	return dao.insertKidDepot(data) && dao.updateParent(data);
}

bool DepotService::removeData(const OnlyValueQuery& query)
{
	DepotDO id;
	id.setId(query.getId());
	DepotDAO dao;

	return dao.deleteDepot(id);
}

int DepotService::modifyDepot(const DepotDTO& dto, const string Username)
{
	//��װ����
	DepotDO data;
	data.setId(dto.getId());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	data.setRemarks(dto.getRemarks());
	data.setModiPeo(Username);
	data.setModiTime(SimpleDateTimeFormat::format());
	//ִ���������
	DepotDAO dao;
	return dao.update(data);
}