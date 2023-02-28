/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 15:07:42

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
#include "PurCompareService.h"
#include "../../dao/pur-compare/PurCompareDAO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

#include "../../dao/pur-compare/PurCompareDAO.h"
#include "../../domain/do/pur-compare/AddPurComDO.h"
#include "../../domain/do/pur-compare/ModPurComDO.h"
#include "../../domain/do/pur-compare/DelPurComDO.h"
#include "../../domain/do/pur-compare/PurComModBillStatusDO.h"



// ��ҳ��ѯ�ȼ۵������б�
PageVO<PurComFindBillVO> PurCompareService::listPurComFindBill(const PurComFindBillQuery& query)
{
	//�������ض���
	PageVO<PurComFindBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	PurCompareDO obj;
	obj.setBillNo(query.getBillNo());
	obj.setSubject(query.getSubject());
	obj.setBillDateBegin(query.getBillDateBegin());
	obj.setBillDateEnd(query.getBillDateEnd());
	obj.setBillStage(query.getBillStage());
	obj.setIsEffective(query.getIsEffective());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsVoided(query.getIsVoided());
	PurCompareDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<PurCompareDO> result = dao.selectPurComFindBill(obj, query.getPageIndex(), query.getPageSize());
	list<PurComFindBillVO> vr;
	for (PurCompareDO sub : result)
	{
		PurComFindBillVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrcNo());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setDeliveryTime(sub.getDeliveryTime());
		vo.setBillStage(sub.getBillStage());
		vo.setIsEffective(sub.getIsEffective());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setDeliveryPlace(sub.getDeliveryPlace());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIsAuto());
		vo.setIsRubric(sub.getIsRubric());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setApprover(sub.getApprover());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
// ��ѯָ���ȼ۵���ϸ��Ϣ
PurComFindDetailBillVO PurCompareService::getPurComFindDetailBill(const PurComFindDetailBillQuery& query)
{
	// ����ģ��ת��
	PurCompareDO obj;
	obj.setBillNo(query.getBillNo());
	PurCompareEntryDO obj2;
	obj2.setBillNo(query.getBillNo());
	// ��ѯ���ݣ��ȼ۵���Ϣ
	PurCompareDAO dao;
	list<PurCompareDO> result = dao.selectPurComFindDetailBill(obj);
	PurComFindDetailBillVO vo;
	if(!result.empty())
	{
		auto sub = result.front();
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setBillStage(sub.getBillStage());
		vo.setIsEffective(sub.getIsEffective());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setApprover(sub.getApprover());
		vo.setBpmiInstanceId(sub.getBpmiInstanceId());
		vo.setCreateTime(sub.getCreateTime());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setIsAuto(sub.getIsAuto());
		vo.setIsRubric(sub.getIsRubric());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrcNo());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setDeliveryTime(sub.getDeliveryTime());
		vo.setDeliveryPlace(sub.getDeliveryPlace());
		vo.setRemark(sub.getRemark());
		vo.setAttachment(sub.getAttachment());
		vo.setApprovalRemark(sub.getApprovalRemark());
		vo.setApprovalResultType(sub.getApprovalResultType());
	}
	// ��ѯ���ݣ���ϸ�б�
	list<PurCompareEntryDO> details = dao.selectPurComFindDetailBillEntry(obj2);
	PurComDetailsVO detailsvo;
	list<PurComDetailsVO> lvo;
	for (PurCompareEntryDO ones : details)
	{
		detailsvo.setEntryNo(ones.getEntryNo());
		detailsvo.setSupplierName(ones.getSupplierName());
		detailsvo.setSrcNo(ones.getSrcNo());
		detailsvo.setMaterialName(ones.getMaterialName());
		detailsvo.setSpecifications(ones.getSpecifications());
		detailsvo.setUnitName(ones.getUnitName());
		detailsvo.setQty(ones.getQty());
		detailsvo.setTaxRate(ones.getTaxRate());
		detailsvo.setPrice(ones.getPrice());
		detailsvo.setDiscountRate(ones.getDiscountRate());
		detailsvo.setAmt(ones.getAmt());
		detailsvo.setRanking(ones.getRanking());
		detailsvo.setRemark(ones.getRemark());
		detailsvo.setCustom1(ones.getCustom1());
		detailsvo.setCustom2(ones.getCustom2());
		lvo.push_back(detailsvo);
	}
	vo.setDetailsList(lvo);
	return vo;
}
// ���۵��б�
std::list<PurComListVO> PurCompareService::listPurComList(const PurComListQuery& query)
{
	// �������ض���
	list<PurComListVO> lvo;
	// ����ģ��ת��
	PurCompareDO obj,obj2;
	obj.setBillNo(query.getBillNo());
	// ��ѯ��ѡ���۵�ids
	PurCompareDAO dao;
	list<PurCompareDO> CanIds = dao.selectCandidateQuot(obj);
	if (CanIds.empty()) return lvo;
	else obj2.setCandidateQuotIds(CanIds.front().getCandidateQuotIds());
	// ��ѯ���۵��б�
	list<PurComQuotDO> result = dao.selectPurComList(obj2);
	PurComListVO vo;
	for (PurComQuotDO ones : result)
	{
		vo.setBillNo(ones.getBillNo());
		vo.setBillDate(ones.getBillDate());
		vo.setSubject(ones.getSubject());
		vo.setSupplierName(ones.getSupplierName());
		vo.setPaymentMethod(ones.getPaymentMethod());
		vo.setDeliveryTime(ones.getDeliveryTime());
		vo.setDeliveryPlace(ones.getDeliveryPlace());
		vo.setRemark(ones.getRemark());
		lvo.push_back(vo);
	}
	return lvo;
}
// ���۵���¼�б�
std::list<PurComDividedListVO> PurCompareService::listPurComDividedList(const PurComDividedListQuery& query)
{
	// �������ض���
	list<PurComDividedListVO> lvo;
	// ����ģ��ת��
	PurComQuotEntryDO obj;
	obj.setBillNo(query.getBillNo());
	// ��ѯ���۵���¼�б�
	PurCompareDAO dao;
	list<PurComQuotEntryDO> result = dao.selectPurComDividedList(obj);
	PurComDividedListVO vo;
	for (PurComQuotEntryDO ones : result)
	{
		vo.setBillNo(ones.getBillNo());
		vo.setEntryNo(ones.getEntryNo());
		vo.setMaterialName(ones.getMaterialName());
		vo.setSpecifications(ones.getSpecifications());
		vo.setUnitName(ones.getUnitName());
		vo.setQty(stod(ones.getQty()));
		vo.setTaxRate(stod(ones.getTaxRate()));
		vo.setPrice(stod(ones.getPrice()));
		vo.setDiscountRate(stod(ones.getDiscountRate()));
		vo.setAmt(stod(ones.getAmt()));
		vo.setRemark(ones.getRemark());
		vo.setCustom1(ones.getCustom1());
		vo.setCustom2(ones.getCustom2());
		lvo.push_back(vo);
	}
	return lvo;
}
// �����ȼ۵�����¼
string PurCompareService::getPurComExport(const PurComExportQuery& query)
{
	//����fastdfs�ͻ��˶���
	#ifdef LINUX
		FastDfsClient client("conf/client.conf", 3);
	#else
		FastDfsClient client("1.15.240.108");
	#endif
	// �ж��Ƿ����ϴ�����������lsAll��¼
	bool lsAll = false;
	if (query.getBillNo().size() == 0) lsAll = true;
	// ���屣������λ��
	ExcelComponent excel;
	std::string fileName = "./public/excel/export.xlsx";
	// �����ɹ��ȼ۵�����
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ��ȼ۵�");
	vector<vector<std::string>> data;
	vector<string> headers{
		CharsetConvertHepler::ansiToUtf8("���ݱ��"),
		CharsetConvertHepler::ansiToUtf8("��������"),
		CharsetConvertHepler::ansiToUtf8("Դ������"),
		CharsetConvertHepler::ansiToUtf8("Դ��id"),
		CharsetConvertHepler::ansiToUtf8("Դ����"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ����"),
		CharsetConvertHepler::ansiToUtf8("��ѡ���۵�ids"),
		CharsetConvertHepler::ansiToUtf8("���ʽ"),
		CharsetConvertHepler::ansiToUtf8("�����ص�"),
		CharsetConvertHepler::ansiToUtf8("����ʱ��"),
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
		//CharsetConvertHepler::ansiToUtf8("�޸�ʱ��")
	};
	data.push_back(headers);
	// �ж��Ƿ����ϴ���������û���򵼳����е��ݣ�������ݵ��ݱ�ŵ���
	if (lsAll) {
		PurCompareDO obj;
		PurCompareDAO dao;
		list<PurCompareDO> result = dao.selectPurComExport(obj,lsAll);
		vector<string> vec;
		for (PurCompareDO ls : result)
		{
			vec = ls.purCompareDOToVecStr();
			data.push_back(vec);
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	else {
		for (string ones : query.getBillNo())
		{
			// ����ģ��ת��
			PurCompareDO obj;
			obj.setBillNo(ones);
			// ��ѯ���
			PurCompareDAO dao;
			list<PurCompareDO> result = dao.selectPurComExport(obj,lsAll);
			vector<string> vec;
			if (!result.empty())
			{
				vec = result.front().purCompareDOToVecStr();
				data.push_back(vec);
			}
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	

	//�����ɹ��ȼ۵���¼
	sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ��ȼ۵���¼");
	data.clear();
	headers.clear();
	headers={
		CharsetConvertHepler::ansiToUtf8("���ݺ�"),
		CharsetConvertHepler::ansiToUtf8("��¼��"),
		CharsetConvertHepler::ansiToUtf8("Դ������"),
		CharsetConvertHepler::ansiToUtf8("Դ��id"),
		CharsetConvertHepler::ansiToUtf8("Դ����¼id"),
		CharsetConvertHepler::ansiToUtf8("Դ����¼��"),
		CharsetConvertHepler::ansiToUtf8("��Ӧ��"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("������λ"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("˰��%"),
		CharsetConvertHepler::ansiToUtf8("��˰����"),
		CharsetConvertHepler::ansiToUtf8("�ۿ���"),
		CharsetConvertHepler::ansiToUtf8("��˰���"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("��ע"),
		CharsetConvertHepler::ansiToUtf8("�Զ���1"),
		CharsetConvertHepler::ansiToUtf8("�Զ���2")
	};
	data.push_back(headers);
	// �ж��Ƿ����ϴ���������û���򵼳����е��ݣ�������ݵ��ݱ�ŵ���
	if (lsAll) {
		PurCompareEntryDO obj2;
		PurCompareDAO dao;
		list<PurCompareEntryDO> result = dao.selectPurComEntryExport(obj2, lsAll);
		vector<string> vec;
		for (PurCompareEntryDO ls : result)
		{
			vec = ls.purCompareEntryDOToVecStr();
			data.push_back(vec);
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	else {
		for (string ones : query.getBillNo())
		{
			// ����ģ��ת��
			PurCompareEntryDO obj2;
			obj2.setBillNo(ones);
			// ��ѯ���
			PurCompareDAO dao;
			list<PurCompareEntryDO> result = dao.selectPurComEntryExport(obj2,lsAll);
			vector<string> vec;
			for (PurCompareEntryDO ls : result)
			{
				vec = ls.purCompareEntryDOToVecStr();
				data.push_back(vec);
			}
		}
		excel.writeVectorToFile(fileName, sheetName, data);
	}
	//�ϴ���fastDfs��ɾ�������ļ�
	std::string fieldName = client.uploadFile(fileName);
	std::remove(fileName.c_str());
	//�������ص�ַ
	fieldName = "http://1.15.240.108:8888/" + fieldName;
	return fieldName;
}
// ����ȼ۵�����¼
uint64_t PurCompareService::savePurComInto(const PurComIntoDTO& dto,const PayloadDTO& payload)
{
	//ѩ��������
	SnowFlake sf(1, 13);
	PurCompareDAO dao;
	// ��ȡ����:�����������ݺͷ�¼����
	ExcelComponent excel;
	string fileName = dto.getFiles().front();
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ��ȼ۵�");
	vector<vector<string>> readData = excel.readIntoVector(fileName, sheetName);
	sheetName = CharsetConvertHepler::ansiToUtf8("�ɹ��ȼ۵���¼");
	vector<vector<string>> readEntryData = excel.readIntoVector(fileName, sheetName);
	// ��������
	int row1 = 1, row2 = 1;//row1���������кţ� row2������ϸ���к�
	for (; row1 < readData.size(); ++row1)
	{
		//ÿ�������ݵ�����
		vector<string> r1 = readData[row1];
		PurCompareDO data(r1);
		data.setId(to_string(sf.nextId())); //�������id
		//��ȡʱ��
		SimpleDateTimeFormat time;
		data.setCreateTime(time.format());
		data.setUpdateTime(time.format());
		//��ȡ���
		data.setSysOrgCode(payload.getDepartment());
		data.setCreateBy(payload.getUsername());
		data.setUpdateBy(payload.getUsername());
		// todo������Ȩ����֤
		// ����������֤
		//���б����������
		if (data.getBillNo() == "" || data.getBillDate() == "") {return 9999;}
		//������ؽ����ݿ�
		dao.insertPurCom(data);
	
		//��ʼ�����Ӧ�ķ�¼
		string billNo = data.getBillNo(); //������
		string mid = data.getId(); //����id
		for (; row2 < readEntryData.size() && readEntryData[row2][0] == billNo; ++row2)
		{
			//ÿ�������ݵ�����
			vector<string> r2 = readEntryData[row2];
			PurCompareEntryDO data(r2);
			data.setMid(mid);  
			data.setId(to_string(sf.nextId())); //�������id
			//���ݼ���
			if (data.getEntryNo() == -1 || data.getSupplierName() == ""|| data.getMaterialName() == "" || data.getUnitName() == ""
				|| data.getQty() == -1 || data.getTaxRate() == -1 || data.getPrice() == -1 || data.getAmt() == -1) 
			{
				return 9999;
			}
			//������ؽ����ݿ�
			dao.insertPurComEntry(data);
		}
	}
	return 10000;
}



uint64_t PurCompareService::savePurCom(const AddPurComDTO& dto, const PayloadDTO& payload)
{
	//��װ����
	AddPurComDO data;
	// ѩ���㷨����id
	SnowFlake randomId(1, 3);
	data.setId(to_string(randomId.nextId()));

	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());
	data.setSrcBillId(dto.getSrcBillId());

	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());
	data.setCandidateQuotIds(dto.getCandidateQuotIds());
	data.setPaymentMethod(dto.getPaymentMethod());

	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setDeliveryTime(dto.getDeliveryTime());
	data.setAttachment(dto.getAttachment());
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());

	data.setBillStage(dto.getBillStage());
	data.setApprover(dto.getApprover());
	data.setBpmiInstanceId(dto.getBpmiInstanceId());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());
	// �������ţ���payload��ȡ
	data.setSysOrgCode(payload.getUserDept());

	// �����ˣ���payload��ȡ
	data.setCreateBy(payload.getUsername());
	// ����ʱ�䣬�ɺ������
	data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	data.setVersion(dto.getVersion());

	list<PurComDetailDTO> Addlist;
	for (PurComDetailDTO i : dto.getDetail())
	{
		// bill_no��entry_no�������ظ�
		PurComDetailDTO detail;
		detail.setId(to_string(randomId.nextId()));
		detail.setMid("pur_compare");

		detail.setBill_no(i.getBill_no());
		detail.setEntry_no(i.getEntry_no());
		detail.setSrc_bill_type(i.getSrc_bill_type());
		detail.setSrc_bill_id(i.getSrc_bill_id());
		detail.setSrc_entry_id(i.getSrc_entry_id());
		detail.setSrc_no(i.getSrc_no());
		detail.setSupplier_id(i.getSupplier_id());
		detail.setMaterial_id(i.getMaterial_id());
		detail.setUnit_id(i.getUnit_id());
		detail.setQty(i.getQty());
		detail.setTax_rate(i.getTax_rate());
		detail.setPrice(i.getPrice());
		detail.setDiscount_rate(i.getDiscount_rate());
		detail.setAmt(i.getAmt());
		detail.setRanking(i.getRanking());
		detail.setRemark(i.getRemark());
		detail.setCustom1(i.getCustom1());
		detail.setCustom2(i.getCustom2());
		detail.setVersion(i.getVersion());

		Addlist.push_back(detail);
	}
	data.setDetail(Addlist);
	//ִ���������
	PurCompareDAO dao;
	return dao.insertPurCom(data);
}

bool PurCompareService::updatePurCom(const ModPurComDTO& dto, PayloadDTO payload)
{
	//��װ��������
	ModPurComDO data;

	// ѩ���㷨����id
	//SnowFlake randomId(1, 3);
	//data.setId(to_string(randomId.nextId()));

	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());
	data.setSrcBillId(dto.getSrcBillId());

	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());
	data.setCandidateQuotIds(dto.getCandidateQuotIds());
	data.setPaymentMethod(dto.getPaymentMethod());

	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setDeliveryTime(dto.getDeliveryTime());
	data.setAttachment(dto.getAttachment());
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());

	data.setBillStage(dto.getBillStage());
	data.setApprover(dto.getApprover());
	data.setBpmiInstanceId(dto.getBpmiInstanceId());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());
	// �������ţ�����
	//data.setSysOrgCode(payload.getUserDept());

	// �����ˣ�����
	//data.setCreateBy(payload.getUsername());
	// ����ʱ�䣬����
	//data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	data.setVersion(dto.getVersion());

	list<PurComDetailDTO> Addlist;
	for (PurComDetailDTO i : dto.getDetail())
	{
		// bill_no��entry_no�������ظ�
		PurComDetailDTO detail;
		//detail.setId(to_string(randomId.nextId()));
		//detail.setMid("pur_compare");

		detail.setBill_no(i.getBill_no());
		//detail.setEntry_no(i.getEntry_no());
		//detail.setSrc_bill_type(i.getSrc_bill_type());

		//detail.setSrc_bill_id(i.getSrc_bill_id());
		//detail.setSrc_entry_id(i.getSrc_entry_id());
		//detail.setSrc_no(i.getSrc_no());
		//detail.setSupplier_id(i.getSupplier_id());
		//detail.setMaterial_id(i.getMaterial_id());

		detail.setUnit_id(i.getUnit_id());
		//detail.setQty(i.getQty());
		//detail.setTax_rate(i.getTax_rate());
		//detail.setPrice(i.getPrice());
		//detail.setDiscount_rate(i.getDiscount_rate());

		//detail.setAmt(i.getAmt());
		detail.setRanking(i.getRanking());
		detail.setRemark(i.getRemark());
		detail.setCustom1(i.getCustom1());
		detail.setCustom2(i.getCustom2());
		detail.setVersion(i.getVersion());

		Addlist.push_back(detail);
	}
	data.setDetail(Addlist);

	//ִ�������޸�
	PurCompareDAO dao;
	return dao.updatePurCom(data) == 1;
}

bool PurCompareService::removePurCom(const DelPurComDTO& dto)
{
	DelPurComDO data;
	data.setBillId(dto.getBillId());

	PurCompareDAO dao;
	return dao.deletePurCom(data) == 1;
}

bool PurCompareService::updatePurComBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload)
{
	ModPurComBillStatusDO data;
	data.setBillId(dto.getBillId());
	data.setIsEffect(dto.getIsEffect());
	data.setIsClose(dto.getIsClose());
	data.setIsCancelled(dto.getIsCancelled());

	data.setUpdatePerson(payload.getUsername());

	PurCompareDAO dao;
	return dao.updatePurComBillStatus(data) == 1;
}
