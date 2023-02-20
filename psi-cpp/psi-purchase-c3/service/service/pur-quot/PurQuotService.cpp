#include "stdafx.h"
#include "PurQuotService.h"
#include "../../dao/pur-quot/PurQuotDAO.h"
//#include "../../domain/do/pur-quot/PurQuotFindBillDO.h"

PageVO<PurQuotFindBillVO> PurQuotService::listPurQuotFindBill(const PurQuotFindBillQuery& query) {
	//�������ض���
	PageVO<PurQuotFindBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	PurQuotFindBillDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_no());
	PurQuotDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<PurQuotFindBillDO> result = dao.selectPurQuotFindBillDO(obj, query.getPageIndex(), query.getPageSize());
	list<PurQuotFindBillVO> vr;
	for (PurQuotFindBillDO sub : result)
	{
		PurQuotFindBillVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSubject(sub.getSubject());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}