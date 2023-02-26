#include "stdafx.h"
#include "CgthrkService.h"
#include"domain/do/Cgthck/QueryCgthrkBillListDO.h"
#include"../../dao/Cgthrk/CgthrkDao.h"

PageVO<QueryCgthckBillVO> CgthrkService::queryAllFitBill(const QueryCgthckBillQuery& query) {
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
	//SampleDAO dao;
	CgthrkDao dao;
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
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}