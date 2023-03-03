/*
 Copyright Zero One Star. All rights reserved.
 //
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
#include "CgrkService.h"
#include "../../dao/Cgrk/CgrkDAO.h"
#include "../../dao/CommonDAO.h"
#include <algorithm>
#include <ctime>
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include"../../domain/do/Cgrk/ModifyCgrkBillStatusDO.h"
//��ѯ�����б�
PageVO<QueryCgrkBillListVO> CgrkService::listCgrkBillList(const QueryCgrkBillListQuery& query)
{
	//�������ض���
	PageVO<QueryCgrkBillListVO> billList;

	CgrkDAO dao;



	list<StkIoDO> result = dao.selectBillList(query);
	list<QueryCgrkBillListVO> vr;
	for (StkIoDO sub : result)
	{
		QueryCgrkBillListVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcNo(sub.getSrcNo());
		vo.setSubject(sub.getSubject());
		vo.setIsRubric(sub.getIsRubric());
		vo.setStockIoType(sub.getStockIoType());
		vo.setOpDept(sub.getOpDept());
		vo.setOperator1(sub.getOperator1());
		vo.setHandler(sub.getHandler());
		vo.setHasRp(sub.getHasRp());
		vo.setHasSwell(sub.getHasSwell());
		vo.setSupplierId(sub.getSupplierId());
		vo.setCustomerId(sub.getCustomerId());
		vo.setInvoiceType(sub.getInvoiceType());
		vo.setCost(sub.getCost());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettledAmt(sub.getSettledAmt());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setAttachment(sub.getAttachment());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIsAuto());
		vo.setBillStage(sub.getBillStage());
		vo.setApprover(sub.getApprover());
		vo.setBpmiInstanceId(sub.getBpmiInstanceId());
		vo.setApprovalResultType(sub.getApprovalResultType());
		vo.setApprovalRemark(sub.getApprovalRemark());
		vo.setIsEffective(sub.getIsEffective());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateTime(sub.getCreateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	billList.setRows(vr);
	 
	return billList;
}

//�߼���ѯ�����б�
PageVO<QueryCgrkBillListVO>  CgrkService::listCgrkBillListAdvanced(const QueryCgrkBillListAdvancedQuery& query)
{
	//�������ض���
	PageVO<QueryCgrkBillListVO> billList;
	CgrkDAO dao;
	list<StkIoDO> result = dao.selectBillListAnvanced(query);
	list<QueryCgrkBillListVO> vr;
	for (StkIoDO sub : result)
	{
		QueryCgrkBillListVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcNo(sub.getSrcNo());
		vo.setSubject(sub.getSubject());
		vo.setIsRubric(sub.getIsRubric());
		vo.setStockIoType(sub.getStockIoType());
		vo.setOpDept(sub.getOpDept());
		vo.setOperator1(sub.getOperator1());
		vo.setHandler(sub.getHandler());
		vo.setHasRp(sub.getHasRp());
		vo.setHasSwell(sub.getHasSwell());
		vo.setSupplierId(sub.getSupplierId());
		vo.setCustomerId(sub.getCustomerId());
		vo.setInvoiceType(sub.getInvoiceType());
		vo.setCost(sub.getCost());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettledAmt(sub.getSettledAmt());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setAttachment(sub.getAttachment());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIsAuto());
		vo.setBillStage(sub.getBillStage());
		vo.setApprover(sub.getApprover());
		vo.setBpmiInstanceId(sub.getBpmiInstanceId());
		vo.setApprovalResultType(sub.getApprovalResultType());
		vo.setApprovalRemark(sub.getApprovalRemark());
		vo.setIsEffective(sub.getIsEffective());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateTime(sub.getCreateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	billList.setRows(vr);

	return billList;

}




//��ѯ������ϸ��Ϣ
QueryCgrkBillDetailsVO CgrkService::getCgrkBillDetails(const QueryCgrkBillDetailsQuery& query)
{
	//�������ض���
	QueryCgrkBillDetailsVO details;

	//
	StkIoDO SIDO;
	SIDO.setBillNo(query.getBillNo());
	StkIoEntryDO SIEDO;
	SIEDO.setBillNo(query. getBillNo());

	CgrkDAO dao;

	list<StkIoDO> result = dao.selectBillListByBillNo(query.getBillNo());

	for (StkIoDO sub : result)
	{
		details.setId(sub.getId());
		details.setBillNo(sub.getBillNo());
		details.setBillDate(sub.getBillDate());
		details.setSrcBillType(sub.getSrcBillType());
		details.setSrcBillId(sub.getSrcBillId());
		details.setSrcNo(sub.getSrcNo());
		details.setSubject(sub.getSubject());
		details.setIsRubric(sub.getIsRubric());
		details.setStockIoType(sub.getStockIoType());
		details.setOpDept(sub.getOpDept());
		details.setOperator1(sub.getOperator1());
		details.setHandler(sub.getHandler());
		details.setHasRp(sub.getHasRp());
		details.setHasSwell(sub.getHasSwell());
		details.setSupplierId(sub.getSupplierId());
		details.setCustomerId(sub.getCustomerId());
		details.setInvoiceType(sub.getInvoiceType());
		details.setCost(sub.getCost());
		details.setSettleAmt(sub.getSettleAmt());
		details.setSettledAmt(sub.getSettledAmt());
		details.setInvoicedAmt(sub.getInvoicedAmt());
		details.setAttachment(sub.getAttachment());
		details.setRemark(sub.getRemark());
		details.setIsAuto(sub.getIsAuto());
		details.setBillStage(sub.getBillStage());
		details.setApprover(sub.getApprover());
		details.setBpmiInstanceId(sub.getBpmiInstanceId());
		details.setApprovalResultType(sub.getApprovalResultType());
		details.setApprovalRemark(sub.getApprovalRemark());
		details.setIsEffective(sub.getIsEffective());
		details.setEffectiveTime(sub.getEffectiveTime());
		details.setIsClosed(sub.getIsClosed());
		details.setIsVoided(sub.getIsVoided());
		details.setSysOrgCode(sub.getSysOrgCode());
		details.setCreateBy(sub.getCreateBy());
		details.setCreateTime(sub.getCreateTime());
		details.setUpdateBy(sub.getUpdateBy());
		details.setUpdateTime(sub.getUpdateTime());
		details.setVersion(sub.getVersion());
	}
		

	list<StkIoEntryDO> result1 = dao.selectBillDetails(query.getBillNo());
	list<CgrkBillEntryVO> vr;
	for (StkIoEntryDO sub : result1)
	{
		CgrkBillEntryVO vo;
		vo.setBatchNo(sub.getBatchNo());
		vo.setBillNo(sub.getBillNo());
		vo.setCost(sub.getCost());
		vo.setCustom1(sub.getCustom1());
		vo.setCustom2(sub.getCustom2());
		vo.setDiscountRate(sub.getDiscountRate());
		vo.setEntryNo(sub.getEntryNo());
		vo.setExpense(sub.getExpense());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setInvoicedQty(sub.getInvoicedQty());
		vo.setMaterialId(sub.getMaterialId());
		vo.setMid(sub.getMid());
		vo.setPrice(sub.getPrice());
		vo.setQty(sub.getQty());
		vo.setRemark(sub.getRemark());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettleQty(sub.getSettleQty());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcNo(sub.getSrcNo());
		vo.setStockIoDirection(sub.getStockIoDirection());
		vo.setSupplierId(sub.getSupplierId());
		vo.setSwellQty(sub.getSwellQty());
		vo.setTax(sub.getTax());
		vo.setTaxRate(sub.getTaxRate());
		vo.setUnitId(sub.getUnitId());
		vo.setVersion(sub.getVersion());
		vo.setWarehouseId(sub.getWarehouseId());

		vr.push_back(vo);
	}
	details.setEntry(vr);

	CgrkDAO CDAO;

	return details;

}

//��ѯ�ɹ������б�
PageVO<QueryPurOrderListVO> CgrkService::listPurOrderList(const QueryPurOrderListQuery& query)
{
	//�������ض���
	PageVO<QueryPurOrderListVO> billList;
	PurOrderDO obj;
	obj.setBillNo(query.getBillNo());

	CgrkDAO dao; 




	list<PurOrderDO> result = dao.selectPurOrderList(query);
	list<QueryPurOrderListVO> vr;

	for (PurOrderDO sub : result)
	{
		QueryPurOrderListVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setPurType(sub.getPurType());
		vo.setPaymentMethod(sub.getPaymentMethod());
		vo.setPrePaymentBal(sub.getPrePaymentBal());
		vo.setSettleMethod(sub.getSettleMethod());
		vo.setDeliverTime(sub.getDeliveryMethod());
		vo.setDeliverPlace(sub.getDeliveryPlace());
		vo.setDeliverMethod(sub.getDeliveryMethod());
		vo.setInQty(sub.getInQty());
		vo.setInCost(sub.getInCost());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setInvoiceType(sub.getInvoiceType());
		vo.setAmt(sub.getAmt());
		vo.setIsClosed(sub.getIsClosed());
		vo.setOpDept(sub.getOpDept());
		vo.setOperator1(sub.getOperator1());
		vo.setQty(sub.getQty());
		vo.setRemark(sub.getRemark());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettledAmt(sub.getSettledAmt());
		vo.setSrcNo(sub.getSrcNo());
		vo.setSubject(sub.getSubject());
		vo.setSupplierId(sub.getSupplierId());

		vr.push_back(vo);
	}
	billList.setRows(vr);

	return billList;



}

//�ɹ�������¼�б�
PageVO<QueryPurOrderEntryVO> CgrkService::listPurOrderEntry(const QueryPurOrderEntryQuery& query)
{
	//�������ض���
	PageVO<QueryPurOrderEntryVO> billList;
	PurOrderEntryDO obj;
	obj.setBillNo(query.getBillNo());

	CgrkDAO dao;
	list<PurOrderEntryDO> result = dao.selectPurOrderEntry(query);
	list<QueryPurOrderEntryVO> vr;

	for (PurOrderEntryDO sub : result)
	{
		QueryPurOrderEntryVO vo;
		vo.setId(sub.getId());
		vo.setMid(sub.getMid());
		vo.setBillNo(sub.getBillNo());
		vo.setBillNo(sub.getBillNo());
		vo.setEntryNo(sub.getEntryNo());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcEntryId(sub.getSrcEntryId());
		vo.setSrcNo(sub.getSrcNo());
		vo.setMaterialId(sub.getMaterialId());
		vo.setUnitId(sub.getUnitId());
		vo.setQty(sub.getQty());
		vo.setTaxRate(sub.getTaxRate());
		vo.setPrice(sub.getPrice());
		vo.setDiscountRate(sub.getDiscountRate());
		vo.setTax(sub.getTax());
		vo.setAmt(sub.getAmt());
		vo.setInQty(sub.getInQty());
		vo.setInCost(sub.getInCost());
		vo.setSettleQty(sub.getSettleQty());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setInvoicedQty(sub.getInvoicedQty());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setRemark(sub.getRemark());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	billList.setRows(vr);

	return billList;
}

//��Ӳɹ���ⵥ
int CgrkService::saveCgrkBill(const AddCgrkBillDTO& dto, const PayloadDTO& payload)
{

	// ����DAO�����
	CgrkDAO dao;
	CommonDAO cDao;

	// �ϴ�����
	// ���崫�����ݿ��ڵĸ�������
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = cDao.insertAttachment(file);
		if (!fileName.empty()) {
			if (attachment.size() != 0) {
				attachment += ",";
			}
			attachment += fileName;
		}
		else {
			return -4;
		}
	}

	// ��װ����stk_io��
	StkIoDO data1;
	SnowFlake sf(1, 5);
	string mid = to_string(sf.nextId());
	data1.setId(mid);//����id
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSupplierId(dto.getSupplierId());
	data1.setSrcBillType(dao.selectSrcBillTypeBySrcNo(dto.getSrcNo()));
	data1.setSrcBillId(dao.selectSrcBillIdBySrcNo(dto.getSrcNo()));
	data1.setSrcNo(dto.getSrcNo());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("101"); // �ɹ����
	data1.setOpDept(dao.selectOpDeptById(dto.getOperator1()));
	data1.setOperator1(dto.getOperator1());
	data1.setHandler(dto.getHandler());
	data1.setHasRp(1);
	data1.setHasSwell(dto.getHasSwell());
	data1.setSupplierId(dto.getSupplierId());
	data1.setInvoiceType(dto.getInvoiceType());
	data1.setCost([](const list<CgrkBillEntryDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getEntry()));
	data1.setAttachment(attachment);
	data1.setRemark(dto.getRemark());
	data1.setIsAuto(0);
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":������, "14":������
	data1.setIsEffective(0);
	data1.setIsClosed(0);
	data1.setIsVoided(0);
	data1.setSysOrgCode(cDao.selectOrgCodeByUsername(payload.getUsername()));
	data1.setCreateBy(payload.getUsername());
	// ���ɵ�ǰʱ��
	data1.setCreateTime(SimpleDateTimeFormat::format());
	// ����ʼ
	dao.getSqlSession()->beginTransaction();
	// ִ���������
	uint64_t row = dao.insertCgrkBill(data1);
	if (row == 0) {
		// �ع�
		dao.getSqlSession()->rollbackTransaction();
		// ɾ������
		vector<string_view> fileNames = split(attachment, ",");
		if (!fileNames.empty()) {
			for (const auto& file : fileNames) {
				cDao.deleteAttachment(string(file));
			}
		}
		return -2;
	}
	// ��װ��ϸ����stk_io_entry
	StkIoEntryDO data2;
	for (auto& entry : dto.getEntry()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(entry.getEntryNo());
		data2.setSrcBillType(data1.getSrcBillType());
		data2.setSrcBillId(data1.getSrcBillId());
		data2.setSrcEntryId(entry.getSrcEntryId());
		data2.setSrcNo(data1.getSrcNo());
		data2.setMaterialId(entry.getMaterialId());
		data2.setBatchNo(dto.getBillNo() + "-" +(entry.getEntryNo()));
		data2.setWarehouseId(entry.getWarehouseId());
		data2.setStockIoDirection("1");
		data2.setSupplierId(entry.getSupplierId());
		data2.setUnitId(entry.getUnitId());	
		data2.setSwellQty(entry.getSwellQty());
		data2.setQty(entry.getQty());
		data2.setExpense(entry.getExpense());
		data2.setCost(entry.getCost());
		data2.setSettleQty(entry.getSettleQty());
		data2.setTaxRate(entry.getTaxRate());
		data2.setPrice(entry.getPrice());
		data2.setDiscountRate(entry.getDiscountRate());
		data2.setTax(entry.getTax());
		data2.setSettleAmt(entry.getSettleAmt());
		data2.setInvoicedQty(entry.getInvoicedQty());
		data2.setInvoicedAmt(entry.getInvoicedAmt());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		dao.insertCgrkBillEntry(data2);

	}
	// �ύ
	dao.getSqlSession()->commitTransaction();
	return row;
}


//�޸Ĳɹ���ⵥ
int CgrkService::updateCgrkBill(const ModifyCgrkBillDTO dto, const PayloadDTO& payload)
{

	// ����DAO�����
	CgrkDAO dao;
	CommonDAO cDao;

	// �ϴ�����
	// ���崫�����ݿ��ڵĸ�������
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = cDao.insertAttachment(file);
		if (!fileName.empty()) {
			if (attachment.size() != 0) {
				attachment += ",";
			}
			attachment += fileName;
		}
		else {
			return -4;
		}
	}

	// ��װ����stk_io��
	StkIoDO data1;
	SnowFlake sf(1, 5);

	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSupplierId(dto.getSupplierId());
	data1.setSrcBillType(dao.selectSrcBillTypeBySrcNo(dto.getSrcNo()));
	data1.setSrcBillId(dao.selectSrcBillIdBySrcNo(dto.getSrcNo()));
	data1.setSrcNo(dto.getSrcNo());
	data1.setSubject(dto.getSubject());
	data1.setOpDept(dao.selectOpDeptById(dto.getOperator1()));
	data1.setOperator1(dto.getOperator1());
	data1.setHandler(dto.getHandler());
	data1.setHasSwell(dto.getHasSwell());
	data1.setSupplierId(dto.getSupplierId());
	data1.setInvoiceType(dto.getInvoiceType());
	data1.setCost([](const list<CgrkBillEntryDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getEntry()));
	data1.setAttachment(attachment);
	data1.setRemark(dto.getRemark());
	data1.setIsAuto(0);
	if (dto.getApprove() == 1)
	{
		data1.setBillStage("24");//"24"������
	}
	else
	{
		data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":������, "14":������
	}

	if ((dto.getApprove() == 1)&& (dto.getApprovalResultType() == "1")) {

			data1.setIsEffective(1);
			data1.setIsClosed(1);

	}
	else
	{
		data1.setIsEffective(0);
		data1.setIsClosed(0);
	}

	data1.setApprovalRemark(dto.getApprovalRemark());
	data1.setSysOrgCode(cDao.selectOrgCodeByUsername(payload.getUsername()));
	data1.setUpdateBy(payload.getId());
	// ���ɵ�ǰʱ��
	data1.setUpdateTime(SimpleDateTimeFormat::format());
	// ����ʼ
	dao.getSqlSession()->beginTransaction();
	// ִ�����ݸ���
	int row = dao.updateCgrkBill(data1);
	if (row == 0) {
		// �ع�
		dao.getSqlSession()->rollbackTransaction();
		// ɾ������
		vector<string_view> fileNames = split(attachment, ",");
		if (!fileNames.empty()) {
			for (const auto& file : fileNames) {
				cDao.deleteAttachment(string(file));
			}
		}
		return -2;
	}
	// ��װ��ϸ����stk_io_entry
	dao.deleteCgrkBillEntry(dto.getBillNo());
	StkIoEntryDO data2;
	for (auto& entry : dto.getEntry()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(dao.selectIdBySrcNo(dto.getSrcNo()));
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(entry.getEntryNo());
		data2.setSrcBillType(data1.getSrcBillType());
		data2.setSrcBillId(data1.getSrcBillId());
		data2.setSrcEntryId(entry.getSrcEntryId());
		data2.setSrcNo(data1.getSrcNo());
		data2.setMaterialId(entry.getMaterialId());
		data2.setBatchNo(dto.getBillNo() + "-" + entry.getEntryNo());
		data2.setWarehouseId(entry.getWarehouseId());
		data2.setStockIoDirection("1");
		data2.setSupplierId(entry.getSupplierId());
		data2.setUnitId(entry.getUnitId());
		data2.setSwellQty(entry.getSwellQty());
		data2.setQty(entry.getQty());
		data2.setExpense(entry.getExpense());
		data2.setCost(entry.getCost());
		data2.setSettleQty(entry.getSettleQty());
		data2.setTaxRate(entry.getTaxRate());
		data2.setPrice(entry.getPrice());
		data2.setDiscountRate(entry.getDiscountRate());
		data2.setTax(entry.getTax());
		data2.setSettleAmt(entry.getSettleAmt());
		data2.setInvoicedQty(entry.getInvoicedQty());
		data2.setInvoicedAmt(entry.getInvoicedAmt());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		dao.insertCgrkBillEntry(data2);
	}
	// �ύ
	dao.getSqlSession()->commitTransaction();
	return row;
}


//ɾ���ɹ���ⵥ
bool CgrkService::removeCgrkBill(string billNo)
{
	CgrkDAO dao;
	return dao.deleteCgrkBill(billNo)>=1;

}
bool CgrkService::updataBillStatus(const ModifyCgrkBillStateDTO& dto) {
	//��װ��������
	ModifyCgrkBillStatusDO data;
	data.setBillNo(dto.getBillNo());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	//ִ�������޸�
	CgrkDAO cd;
	return cd.updataBillStatus(data) == 1;
}
