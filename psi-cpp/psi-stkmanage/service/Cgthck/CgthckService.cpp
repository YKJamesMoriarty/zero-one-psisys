#include "stdafx.h"
#include "CgthckService.h"
#include"domain/do/Cgthck/QueryCgthrkBillListDO.h"
#include"../../dao/Cgthck/CgthckDAO.h"

PageVO<QueryCgthckBillVO> CgthckService::queryAllFitBill(const QueryCgthckBillQuery& query) {
	//�������ض���
	PageVO<QueryCgthckBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	QueryCgthrkBillListDO obj; //���ǲ�ѯ���ݿ������  ��װ����
	obj.setId(query.getBillNo());
	obj.setBeginData(query.getBeginData());
	obj.setEndData(query.getEndData());
	obj.setTheme(query.getSubject());
	obj.setStage(query.getBillStage());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsEffective(query.getIsEff());
	obj.setIsVoided(query.getIsVoided());
	CgthckDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<QueryCgthrkBillListReturnDO> result = dao.selectCgthckBillList(obj, query.getPageIndex(), query.getPageSize());
	list<QueryCgthckBillVO> vr;
	for (QueryCgthrkBillListReturnDO sub : result)
	{
		QueryCgthckBillVO vo;
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSubject(sub.getSubject());
		vo.setSrcNo(sub.getSrcNo());
		vo.setSupplierId(sub.getSupplierId());
		vo.setOptDept(sub.getOptDept());
		vo.setSrcOperator(sub.getSrcOperator());
		vo.setInAmt(sub.getInAmt());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettledAmt(sub.getSettledAmt());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setInvoiceType(sub.getInvoiceType());
		vo.setHandler(sub.getHandler());
		vo.setBillStage(sub.getBillStage());
		vo.setIsEff(sub.getIsEff());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setIsAuto(sub.getIsAuto());
		vo.setIsRubric(sub.getIsRubric());
		vo.setRemark(sub.getRemark());
		vo.setEffTime(sub.getEffTime());
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



QueryCgthrkDetailedBillVO CgthckService::queryBillDetial(const CgthckBillDetailedDTO& query) {
	//�������ض���
	QueryCgthrkDetailedBillVO vo;

	BillDetailedDO obj; //���ǲ�ѯ���ݿ������  ��װ����
	obj.setBillNo(query.getBillNo());
	CgthckDAO dao;

	QueryCgthrkBillDetailedReturnDO sub = dao.selectCgthckBillListDetailed(obj);
	//��ҳ��ѯ����
	vo.setBillNo(sub.getBillNo());
	vo.setBillDate(sub.getBillDate());
	vo.setSubject(sub.getSubject());
	vo.setSrcNo(sub.getSrcNo());
	vo.setSupplierId(sub.getSupplierId());
	vo.setOptDept(sub.getOptDept());
	vo.setSrcOperator(sub.getSrcOperator());
	vo.setInAmt(sub.getInAmt());
	vo.setSettleAmt(sub.getSettleAmt());
	vo.setSettledAmt(sub.getSettledAmt());
	vo.setInvoicedAmt(sub.getInvoicedAmt());
	vo.setInvoiceType(sub.getInvoiceType());
	vo.setHandler(sub.getHandler());
	vo.setBillStage(sub.getBillStage());
	vo.setIsEff(sub.getIsEff());
	vo.setIsClosed(sub.getIsClosed());
	vo.setIsVoided(sub.getIsVoided());
	vo.setIsAuto(sub.getIsAuto());
	vo.setIsRubric(sub.getIsRubric());
	vo.setRemark(sub.getRemark());
	vo.setEffTime(sub.getEffTime());
	vo.setApprover(sub.getApprover());
	vo.setCreateTime(sub.getCreateTime());
	vo.setCreateBy(sub.getCreateBy());
	vo.setSysOrgCode(sub.getSysOrgCode());
	vo.setUpdateTime(sub.getUpdateTime());
	vo.setUpdateBy(sub.getUpdateBy());
	vo.setDetail(sub.getDetail());
	return vo;

}