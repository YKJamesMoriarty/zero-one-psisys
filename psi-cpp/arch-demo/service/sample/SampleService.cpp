#include "stdafx.h"
#include "SampleService.h"
#include "../../dao/sample/SampleDAO.h"

PageVO<SampleVO> SampleService::listAll(const SampleQuery& query)
{
	//�������ض���
	PageVO<SampleVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	//��ѯ����������
	SampleDO obj;
	obj.setName(query.getName());
	obj.setSex(query.getSex());
	SampleDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<SampleDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());

	list<SampleVO> vr;
	for (SampleDO sub : result)
	{
		SampleVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setSex(sub.getSex());
		vo.setAge(sub.getAge());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

