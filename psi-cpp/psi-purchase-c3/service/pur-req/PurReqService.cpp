/*
 Copyright Zero One Star. All rights reserved.

 @Author: Adam
 @Date: 2023/2/22 9:08

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
#include "PurReqService.h"
#include "../../dao/pur-req/PurReqDAO.h"

//����һ������������Ĭ��ֵ���޸�
#define MODIFY_DEFAULT(name) if (dto.get##name() != data.get##name()) {data.set##name(dto.get##name());}

//����һ������������ֵ���޸�
#define MODIFY(name) data.set##name(dto.get##name());

//����һ������������ֵѹ�뵼�����ݱ���
#define PUSH_VALUE(value) row.emplace_back(CharsetConvertHepler::ansiToUtf8(value));

//����һ������������ֵ�ӵ����������ݱ����DO��
#define GET_VALUE1(name, stox) data.set##name(stox(CharsetConvertHepler::utf8ToAnsi(r1[i++])));

//����һ������������ֵ�ӵ����������ݱ����DO��
#define GET_VALUE2(name, stox) data.set##name(stox(CharsetConvertHepler::utf8ToAnsi(r2[i++])));

string getTime()
{
	time_t now = time(0);
	struct tm t;

	localtime_s(&t, &now);

	// ����Ϣ������ַ�����
	stringstream ss;
	ss << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec;
	return ss.str();
}

uint64_t PurReqService::saveData(const AddPurReqDTO& dto,  const PayloadDTO& payload)
{
	//���Ƚ�����������ӽ����ݿ�
	//��װ��������
	PurReqAdamDO data;
	SnowFlake sf(1, 3);
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();
	string time = getTime();
	//�����ǽ���id����ʹ��ѩ���㷨
	data.setId(id);
	//��ȡ������Ϣ
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(RequestDept);
	MODIFY(Requester);
	MODIFY(RequestTime);
	MODIFY(BillStage);
	//��ȡ�û�����Ϣ���˴�Ϊ��Ӷ�������Ϣ
	data.setSysOrgCode(payload.getDepartment());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(time);
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(time);
	//���⴦����
	MODIFY_DEFAULT(Attachment);
	//����Ĭ��ֵʱ�Ĵ���
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(PurType);
	MODIFY_DEFAULT(Qty);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(OrderedQty);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	//ִ�������޸�
	PurReqDAO dao;
	//Ȼ�󽫶�����ϸ��ӽ����ݿ�
	for (PurReqEntryDTO &dto : dto.getDetail()) {
		PurReqEntryAdamDO data;
		//�����ǽ���id����ʹ��ѩ���㷨
		data.setId(to_string(sf.nextId()));
		//���ú���������Ӽ�
		data.setMid(id);
		data.setBillNo(BillNo);
		//���б���ֵ�Ĳ���
		MODIFY(EntryNo);
		MODIFY(MaterialId);
		MODIFY(UnitId);
		MODIFY(Qty);
		MODIFY(OrderedQty);
		//Ĭ��ֵ����
		MODIFY_DEFAULT(SrcBillType);
		MODIFY_DEFAULT(SrcEntryId);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(TaxRate);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(Price);
		MODIFY_DEFAULT(Amt);
		MODIFY_DEFAULT(SuggestSupplierId);
		MODIFY_DEFAULT(Remark);
		MODIFY_DEFAULT(Custom1);
		MODIFY_DEFAULT(Custom2);
		MODIFY_DEFAULT(Version);
		dao.insertEntry(data);
	}
	return dao.insert(data);
}

uint64_t PurReqService::updateData(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	//���Ƚ�����������ӽ����ݿ�
	//��װ��������
	PurReqAdamDO data;
	PurReqDAO dao;
	SnowFlake sf(1, 3);
	//ʹ��ѩ���㷨����id
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();

	//����id����
	data.setId(id);
	//��ȡ������Ϣ
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(RequestDept);
	MODIFY(Requester);
	MODIFY(RequestTime);
	MODIFY(BillStage);
	MODIFY(SysOrgCode);
	MODIFY(CreateBy);
	MODIFY(CreateTime);
	//��ȡ�޸��û�����Ϣ���˴�Ϊ��Ӷ�������Ϣ
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(getTime());
	//����Ĭ��ֵʱ�Ĵ���
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(PurType);
	MODIFY_DEFAULT(Qty);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(OrderedQty);
	MODIFY_DEFAULT(Attachment);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	//ִ�������޸�

	//Ȼ�󽫶�����ϸ��ӽ����ݿ�
	for (PurReqEntryDTO& dto : dto.getDetail()) {
		PurReqEntryAdamDO data;
		//�����ǽ���id����,��ѩ���㷨
		data.setId(to_string(sf.nextId()));
		//���ú���������
		data.setMid(id);
		data.setBillNo(BillNo);
		//���б���ֵ�Ĳ���
		MODIFY(EntryNo);
		MODIFY(MaterialId);
		MODIFY(UnitId);
		MODIFY(Qty);
		MODIFY(OrderedQty);
		//Ĭ��ֵ����
		MODIFY_DEFAULT(SrcBillType);
		MODIFY_DEFAULT(SrcEntryId);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(TaxRate);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(Price);
		MODIFY_DEFAULT(Amt);
		MODIFY_DEFAULT(SuggestSupplierId);
		MODIFY_DEFAULT(Remark);
		MODIFY_DEFAULT(Custom1);
		MODIFY_DEFAULT(Custom2);
		MODIFY_DEFAULT(Version);
		dao.insertEntry(data);
	}
	return dao.insert(data);
}

uint64_t PurReqService::updateBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload)
{
	//��װ��������
	PurReqAdamDO data;
	//���봫ֵ����
	MODIFY(IsEffective);
	MODIFY(EffectiveTime);
	MODIFY(IsClosed);
	MODIFY(IsVoided);
	MODIFY(BillNo);

	//��ȡ�޸��˵���Ϣ��ʱ��
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(getTime());

	//ִ�������޸�
	PurReqDAO dao;
	return dao.update(data) == 1;
}

bool PurReqService::removeData(string billNo)
{
	PurReqDAO dao;
	//���Ȼ�ȡ������Ϣ
	list<PurReqAdamDO> getdata = dao.selectByBillNo(billNo);
	if (getdata.size() == 1)
	{
		PurReqAdamDO data = getdata.front();
		if (data.getAttachment() != "")
		{
#ifdef LINUX
			//����ͻ��˶���
			FastDfsClient client("conf/client.conf", 3);
#else
			//����ͻ��˶���
			FastDfsClient client("1.15.240.108");
#endif
			string fieldName = data.getAttachment();
			//ɾ���ļ�
			if (!fieldName.empty())
			{
				client.deleteFile(fieldName);
			}
		}
	}
	return dao.deleteByBillNo(billNo);
}

uint64_t PurReqService::getFromExecl(string fileName, const PayloadDTO& payload)
{
	//��һЩֵ���г�ʼ��
		//excel����
	ExcelComponent excel;
		//ѩ��������
	SnowFlake sf(1, 3);
		//������
	int i = 0;
	PurReqDAO dao;
	//���ȼ�����������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ����뵥");
	auto readData = excel.readIntoVector(fileName, sheetName);
	//Ȼ�������ϸ����
	sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ����뵥��ϸ");
	auto readEntryData = excel.readIntoVector(fileName, sheetName);
	int row1 = 1, row2 = 1;//row1���������кţ� row2������ϸ���к�
	for (; row1 < readData.size(); ++row1)
	{
		//ÿ�������ݵ�����
		vector<string> r1 = readData[row1];
		PurReqAdamDO data;
		i = 0;
		//��������id
		string id = to_string(sf.nextId());
		data.setId(id);
		//��ȡʱ��
		string time = getTime();
		//��ȡ���
		data.setSysOrgCode(payload.getDepartment());
		data.setCreateBy(payload.getUsername());
		data.setCreateTime(time);
		data.setUpdateBy(payload.getUsername());
		data.setUpdateTime(time);
		//��ȡ���ݱ����Ϣ
		GET_VALUE1(BillNo, );
		GET_VALUE1(BillDate, );
		GET_VALUE1(SrcBillType, );
		GET_VALUE1(SrcBillId, );
		GET_VALUE1(SrcNo, );
		GET_VALUE1(Subject, );
		GET_VALUE1(IsRubric, stoi);
		GET_VALUE1(PurType, );
		GET_VALUE1(RequestDept, );
		GET_VALUE1(Requester, );
		GET_VALUE1(RequestTime, );
		GET_VALUE1(Qty, stod);
		GET_VALUE1(Amt, stod);
		GET_VALUE1(OrderedQty, stod);
		GET_VALUE1(Attachment, );
		GET_VALUE1(Remark, );
		GET_VALUE1(IsAuto, stoi);
		GET_VALUE1(BillStage, );
		GET_VALUE1(Approver, );
		GET_VALUE1(BpmiInstanceId, );
		GET_VALUE1(ApprovalResultType, );
		GET_VALUE1(ApprovalRemark, );
		GET_VALUE1(IsEffective, stoi);
		GET_VALUE1(EffectiveTime, );
		GET_VALUE1(IsClosed, stoi);
		GET_VALUE1(IsVoided, stoi);
		GET_VALUE1(Version, stoi);
		//����������֤
		//���б����������
		if (data.getBillNo() == "" || data.getBillDate() == "" || data.getRequestDept() == ""
			|| data.getRequester() == "" || data.getRequestTime() == "" || data.getBillStage() == "") {
			return 0;
		}
		//������ؽ����ݿ�
		if (dao.insert(data) == 0)
		{
			return  0;
		}
		string billNo = data.getBillNo();
		for (; row2 < readEntryData.size() && readEntryData[row2][0] == billNo; ++row2)
		{
			PurReqEntryAdamDO data;
			//ÿ�������ݵ�����
			vector<string> r2 = readEntryData[row2];
			i = 0;
			//��������id
			string id1 = to_string(sf.nextId());
			data.setId(id1);
			data.setMid(id);
			//��ȡ���ݱ����Ϣ
			GET_VALUE2(BillNo, );
			GET_VALUE2(EntryNo, stoi);
			GET_VALUE2(SrcBillType, );
			GET_VALUE2(SrcBillId, );
			GET_VALUE2(SrcEntryId, );
			GET_VALUE2(SrcNo, );
			GET_VALUE2(MaterialId, );
			GET_VALUE2(UnitId, );
			GET_VALUE2(Qty, stod);
			GET_VALUE2(TaxRate, stod);
			GET_VALUE2(Price, stod);
			GET_VALUE2(Amt, stod);
			GET_VALUE2(SuggestSupplierId, );
			GET_VALUE2(OrderedQty, stod);
			GET_VALUE2(Remark, );
			GET_VALUE2(Custom1, );
			GET_VALUE2(Custom2, );
			GET_VALUE2(Version, stoi);

			//���ݼ���
			//������ϸ����
			if (data.getEntryNo() < 0 || data.getMaterialId() == "" || data.getUnitId() == ""
				|| data.getQty() < 0 || data.getOrderedQty() < 0) {
				return 0;
			}
			//������ؽ����ݿ�
			if (dao.insertEntry(data) == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

string PurReqService::getToExecl(list<string> billNoList)
{
	PurReqDAO dao;
	//���������ȡ���� ���õ���ֵ����data��
	vector<vector<std::string>> data;
	vector<std::string> row;
	ExcelComponent excel;
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("1.15.240.108");
#endif
	//���Ƚ��������ؽ�ȥ
	vector<std::string> name = {
		CharsetConvertHepler::ansiToUtf8("���ݱ��"),
		CharsetConvertHepler::ansiToUtf8("��������"),
		CharsetConvertHepler::ansiToUtf8("Դ������"),
		CharsetConvertHepler::ansiToUtf8("Դ��id"),
		CharsetConvertHepler::ansiToUtf8("Դ����"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ����"),
		CharsetConvertHepler::ansiToUtf8("�ɹ�����"),
		CharsetConvertHepler::ansiToUtf8("������"),
		CharsetConvertHepler::ansiToUtf8("������"),
		CharsetConvertHepler::ansiToUtf8("����ʱ��"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("�ο����"),
		CharsetConvertHepler::ansiToUtf8("�Ѷ�����"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("��ע"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ��Զ�����"),
		CharsetConvertHepler::ansiToUtf8("���ݽ׶�"),
		CharsetConvertHepler::ansiToUtf8("�����"),
		CharsetConvertHepler::ansiToUtf8("����ʵ��id"),
		CharsetConvertHepler::ansiToUtf8("�����������"),
		CharsetConvertHepler::ansiToUtf8("�������"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ���Ч"),
		CharsetConvertHepler::ansiToUtf8("��Чʱ��"),
		CharsetConvertHepler::ansiToUtf8("�ѹر�"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ�����"),
		CharsetConvertHepler::ansiToUtf8("��������"),
		CharsetConvertHepler::ansiToUtf8("������"),
		CharsetConvertHepler::ansiToUtf8("����ʱ��"),
		CharsetConvertHepler::ansiToUtf8("�޸���"),
		CharsetConvertHepler::ansiToUtf8("�޸�ʱ��"),
		CharsetConvertHepler::ansiToUtf8("�汾")
	};
	data.emplace_back(name);
	//����ȡ��billNo��ȡ����Ӧֵ 
	for (auto billNo : billNoList)
	{
		row.clear();
		list<PurReqAdamDO> dat = dao.selectByBillNo(billNo);
		//������صĲ���ֻ��һ�����ݵĻ��ͱ���
		if (dat.size() != 1) {
			return "";
		}
		PurReqAdamDO dt = dat.front();
		//����Ϣ���뵽row��
		PUSH_VALUE(dt.getBillNo());
		PUSH_VALUE(dt.getBillDate());
		PUSH_VALUE(dt.getSrcBillType());
		PUSH_VALUE(dt.getSrcBillId());
		PUSH_VALUE(dt.getSrcNo());
		PUSH_VALUE(dt.getSubject());
		PUSH_VALUE(to_string(dt.getIsRubric()));
		PUSH_VALUE(dt.getPurType());
		PUSH_VALUE(dt.getRequestDept());
		PUSH_VALUE(dt.getRequester());
		PUSH_VALUE(dt.getRequestTime());

		PUSH_VALUE(to_string(dt.getQty()));
		PUSH_VALUE(to_string(dt.getAmt()));
		PUSH_VALUE(to_string(dt.getOrderedQty()));

		PUSH_VALUE(dt.getAttachment());
		PUSH_VALUE(dt.getRemark());
		PUSH_VALUE(to_string(dt.getIsAuto()));

		PUSH_VALUE(dt.getBillStage());
		PUSH_VALUE(dt.getApprover());
		PUSH_VALUE(dt.getBpmiInstanceId());

		PUSH_VALUE(dt.getApprovalResultType());
		PUSH_VALUE(dt.getApprovalRemark());
		PUSH_VALUE(to_string(dt.getIsEffective()));

		PUSH_VALUE(dt.getEffectiveTime());
		PUSH_VALUE(to_string(dt.getIsClosed()));
		PUSH_VALUE(to_string(dt.getIsVoided()));

		PUSH_VALUE(dt.getSysOrgCode());
		PUSH_VALUE(dt.getCreateBy());
		PUSH_VALUE(dt.getCreateTime());

		PUSH_VALUE(dt.getUpdateBy());
		PUSH_VALUE(dt.getUpdateTime());
		PUSH_VALUE(to_string(dt.getVersion()));
		//����������ѹ��
		data.emplace_back(row);
	}
	//��ֵ���뵽execl��
	//���屣������λ�ú�ҳǩ����
	std::string fileName = "./public/excel/pur_req.xlsx";//������ֲ�֪����ô��ֵ�����ǲ���Ҫ

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ����뵥");
	//���浽�ļ�
	excel.writeVectorToFile(fileName, sheetName, data);

	//Ȼ������ϸ��
	data.clear();
	name.clear();
	//���Ƚ��������ؽ�ȥ
	name = {
	CharsetConvertHepler::ansiToUtf8("���ݺ�"),
	CharsetConvertHepler::ansiToUtf8("��¼��"),
	CharsetConvertHepler::ansiToUtf8("Դ������"),
	CharsetConvertHepler::ansiToUtf8("Դ��id"),
	CharsetConvertHepler::ansiToUtf8("Դ����¼id"),
	CharsetConvertHepler::ansiToUtf8("Դ����¼��"),
	CharsetConvertHepler::ansiToUtf8("����"),
	CharsetConvertHepler::ansiToUtf8("������λ"),
	CharsetConvertHepler::ansiToUtf8("����"),
	CharsetConvertHepler::ansiToUtf8("˰��%"),
	CharsetConvertHepler::ansiToUtf8("�ο���˰����"),
	CharsetConvertHepler::ansiToUtf8("�ο���˰���"),
	CharsetConvertHepler::ansiToUtf8("���鹩Ӧ��"),
	CharsetConvertHepler::ansiToUtf8("�Ѷ�������"),
	CharsetConvertHepler::ansiToUtf8("��ע"),
	CharsetConvertHepler::ansiToUtf8("�Զ���1"),
	CharsetConvertHepler::ansiToUtf8("�Զ���2"),
	CharsetConvertHepler::ansiToUtf8("�汾") };
	data.emplace_back(name);
	//����ȡ��billNo��ȡ����Ӧֵ 
	for (auto billNo : billNoList)
	{
		row.clear();
		list<PurReqEntryAdamDO> dat = dao.selectEntryByBillNo(billNo);
		for (PurReqEntryAdamDO dt : dat)
		{
			//����Ϣ���뵽row��
			PUSH_VALUE(dt.getBillNo());
			PUSH_VALUE(to_string(dt.getEntryNo()));
			PUSH_VALUE(dt.getSrcBillType());
			PUSH_VALUE(dt.getSrcBillId());
			PUSH_VALUE(dt.getSrcEntryId());
			PUSH_VALUE(dt.getSrcNo());
			PUSH_VALUE(dt.getMaterialId());
			PUSH_VALUE(dt.getUnitId());
			PUSH_VALUE(to_string(dt.getQty()));
			PUSH_VALUE(to_string(dt.getTaxRate()));
			PUSH_VALUE(to_string(dt.getPrice()));
			PUSH_VALUE(to_string(dt.getAmt()));
			PUSH_VALUE(dt.getSuggestSupplierId());
			PUSH_VALUE(to_string(dt.getOrderedQty()));
			PUSH_VALUE(dt.getRemark());
			PUSH_VALUE(dt.getCustom1());
			PUSH_VALUE(dt.getCustom2());
			PUSH_VALUE(to_string(dt.getVersion()));
			//����������ѹ��
			data.emplace_back(row);
		}
	}
	//��ֵ���뵽execl��
	//���屣������λ�ú�ҳǩ����
	sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ����뵥��ϸ'");
	//�����ļ�
	excel.writeVectorToFile(fileName, sheetName, data);

	//���ļ��ϴ���fastdfs
	//�ϴ�
	std::string fieldName = client.uploadFile(fileName);

	//ɾ�������ļ�
	remove(fileName.c_str());

	//��װ���ص�ַ
	fieldName = "http://1.15.240.108:8888/" + fieldName;

	return  fieldName;
}


// ��ҳ��ѯ��������
PageVO<PurReqFindBillVO> PurReqService::listAll(const PurReqFindBillQuery& query) {
	//�������ض���
	PageVO<PurReqFindBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	PurReqDO obj;
	obj.setBill_no(query.getBillNo());
	obj.setBill_date(query.getBillDate());
	obj.setSubject(query.getSubject());
	obj.setBill_stage(query.getBillStage());
	obj.setIs_effective(query.getIsEffective());
	obj.setIs_closed(query.getIsClose());
	obj.setIs_voided(query.getIsVoided());
	PurReqDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<PurReqDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PurReqFindBillVO> vr;
	for (PurReqDO sub : result)
	{
		PurReqFindBillVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSubject(sub.getSubject());
		vo.setSrc_no(sub.getSrc_no());
		vo.setPur_type(sub.getPur_type());
		vo.setRequest_dept(sub.getRequest_dept());
		vo.setRequester(sub.getRequester());
		vo.setRequest_time(sub.getRequest_time());
		vo.setQty(sub.getQty());
		vo.setOrdered_qty(sub.getOrdered_qty());
		vo.setAmt(sub.getAmt());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setEffective_time(sub.getEffective_time());
		vo.setapprover(sub.getApprover());
		vo.setCreate_time(sub.getCreate_time());
		vo.setCreate_by(sub.getCreate_by());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
//��ѯָ��������ϸ��Ϣ
PurReqFindDetailBillVO PurReqService::detailsOne(const PurReqFindDetailBillQuery& query) {
	PurReqDAO dao;
	list<PurReqDO> pus = dao.selectByNo(query.getBill_no());
	PurReqFindDetailBillVO po;
	if (!pus.empty()) {
		PurReqDO pu = *pus.begin();
		po.setBill_no(pu.getBill_no());
		po.setBill_date(pu.getBill_date());
		po.setIs_effective(pu.getIs_effective());
		po.setIs_closed(pu.getIs_closed());
		po.setIs_voided(pu.getIs_voided());
		po.setSubject(pu.getSubject());
		po.setPur_type(pu.getPur_type());
		po.setRequester(pu.getRequester());
		po.setRequest_dept(pu.getRequest_dept());
		po.setRequest_time(pu.getRequest_time());
		po.setOrdered_qty(pu.getOrdered_qty());

		list<PurReqEntryDO> detailsResult = pu.getDetail();
		list<PurReqDetailBillVO> pbVO;
		for (PurReqEntryDO re : detailsResult)
		{
			PurReqDetailBillVO tep;
			tep.setSrc_no(re.getSrc_no());
			tep.setMaterial_id(re.getMaterial_id());
			tep.setSrc_bill_type(re.getSrc_bill_type());
			tep.setUnit_id(re.getUnit_id());
			tep.setQty(re.getQty());
			tep.setOrdered_qty(re.getOrdered_qty());
			tep.setTax_rate(re.getTax_rate());
			tep.setPrice(re.getPrice());
			tep.setAmt(re.getAmt());
			tep.setSuggest_supplier_id(re.getSuggest_supplier_id());
			tep.setRemark(re.getRemark());
			tep.setCustom1(re.getCustom1());
			tep.setCustom2(re.getCustom2());
			pbVO.push_back(tep);
		}
		po.setDetailBillsVO(pbVO);
	}
	return po;
}