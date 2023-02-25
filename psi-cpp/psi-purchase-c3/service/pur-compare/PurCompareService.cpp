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
#include "../../dao/pur-compare/PurCompareDAO.h"
#include "../../domain/do/pur-compare/AddPurComDO.h"
#include "../../domain/do/pur-compare/ModPurComDO.h"
#include "../../domain/do/pur-compare/DelPurComDO.h"
#include "../../domain/do/pur-compare/PurComModBillStatusDO.h"
#include "SnowFlake.h"


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
		detailsvo.setSupplierName(ones.getSupplierName());//tomodify:supplierId->suppliername
		detailsvo.setSrcNo(ones.getSrcNo());
		detailsvo.setMaterialName(ones.getMaterialName());
		detailsvo.setSpecifications(ones.getSpecifications());
		detailsvo.setUnitName(ones.getUnitName());//tomodify:unitId->unitname
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


uint64_t PurCompareService::savePurCom(const AddPurComDTO& dto, PayloadDTO payload)
{
	//��װ����
	AddPurComDO data;
	// ѩ���㷨����id
	SnowFlake randomId(21, 22);
	data.setId(randomId.nextId());

	data.setBillId(dto.getBillId());
	data.setBillDate(dto.getBillDate());
	data.setIsEffect(dto.getIsEffect());
	data.setIsClose(dto.getIsClose());
	data.setIsCancelled(dto.getIsCancelled());
	data.setEffectDate(dto.getEffectDate());
	data.setApprover(dto.getApprover());
	// ����ʱ���������ʱʹ��sql����now()
	//data.setMakeBillDate(dto.getMakeBillDate());
	data.setMakeBillDept(dto.getMakeBillDept());
	// ��payload�л�ȡ������
	data.setMakeBillPerson(payload.getUsername());

	data.setUdpateDate(dto.getUdpateDate());
	data.setUdpatePerson(dto.getUdpatePerson());
	data.setAutoBill(dto.getAutoBill());
	data.setRedBill(dto.getRedBill());
	data.setBillType(dto.getBillType());
	data.setBillTheme(dto.getBillTheme());
	data.setBillStatus(dto.getBillStatus());
	data.setInqueryBill(dto.getInqueryBill());
	data.setPayMethod(dto.getPayMethod());
	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setRemark(dto.getRemark());


	//ִ���������
	PurCompareDAO dao;
	return dao.insertPurCom(data);
}

bool PurCompareService::updatePurCom(const ModPurComDTO& dto, PayloadDTO payload)
{
	//��װ��������
	ModPurComDO data;
	data.setBillId(dto.getBillId());
	data.setBillDate(dto.getBillDate());
	data.setIsEffect(dto.getIsEffect());
	data.setIsClose(dto.getIsClose());
	data.setIsCancelled(dto.getIsCancelled());
	data.setEffectDate(dto.getEffectDate());
	data.setApprover(dto.getApprover());
	data.setMakeBillDate(dto.getMakeBillDate());
	data.setMakeBillDept(dto.getMakeBillDept());
	data.setMakeBillPerson(dto.getMakeBillPerson());
	// �޸�ʱ���������ʱ��sql����now()
	//data.setUdpateDate(dto.getUdpateDate());
	// ��payload�л�ȡ�޸���
	data.setUdpatePerson(payload.getUsername());

	data.setAutoBill(dto.getAutoBill());
	data.setRedBill(dto.getRedBill());
	data.setBillType(dto.getBillType());
	data.setBillTheme(dto.getBillTheme());
	data.setBillStatus(dto.getBillStatus());
	data.setInqueryBill(dto.getInqueryBill());
	data.setPayMethod(dto.getPayMethod());
	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryPlace(dto.getDeliveryPlace());
	data.setRemark(dto.getRemark());
	data.setAuditResult(dto.getAuditResult());
	data.setAuditRemark(dto.getAuditRemark());

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
