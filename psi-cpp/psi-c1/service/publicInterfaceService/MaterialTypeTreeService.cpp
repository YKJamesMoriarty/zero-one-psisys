#include "stdafx.h"
#include "MaterialTypeTreeService.h"
#include"../../dao/publicInterfaceDAO/MaterialTypeTreeDAO.h"

PageVO<MaterialTypeTreeListVO> MaterialTypeTreeListService::listAll(const MaterialTypeItemQuery& query)
{

	//�������ض���
	PageVO<MaterialTypeTreeListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	//��ѯ����������
	MaterialTypeTreeDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	MaterialTypeTreeDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<MaterialTypeTreeDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MaterialTypeTreeListVO> vp;
	//�ӽڵ�list
	list<MaterialTypeTreeListVO> vc;
	for (MaterialTypeTreeDO sub : result)
	{
		//�������ӽڵ�Ϳ�ʼ����
		vector< MaterialTypeTreeListVO> res;
		if (sub.getHasChild() == "1") {
			MaterialTypeTreeListVO co;
			for (MaterialTypeTreeDO cb : result) {
				if (cb.getPid() == sub.getId()) {
					co.setCode(cb.getCode());
					co.setCreateBy(cb.getCreateBy());
					if (sub.getCreateBy() != "") co.setCreateBy_dictText(u8"����Ա");
					else co.setCreateBy_dictText(u8"");
					co.setCreateTime(cb.getCreateTime());
					co.setFullname(cb.getFullname());
					co.setHasChild(cb.getHasChild());
					co.setHasChild_dictText(u8"111");
					co.setId(cb.getId());
					co.setIsEnabled(cb.getIsEnabled());
					if (sub.getIsEnabled() == 1) co.setIsEnabled_dictText(u8"��");
					else co.setIsEnabled_dictText(u8"��");
					co.setName(cb.getName());
					co.setPid(cb.getPid());
					co.setUpdateBy(cb.getUpdateBy());
					if (cb.getUpdateBy() != "")	co.setUpdateBy_dictText(u8"����Ա");
					else co.setUpdateBy_dictText(u8"");
					co.setUpdateBy_dictText(u8"22");
					co.setUpdateTime(cb.getUpdateTime());
					co.setVersion(cb.getVersion());
					res.push_back(co);
				}
			}
		}
		
		MaterialTypeTreeListVO vo;
		vo.setCode(sub.getCode());
		vo.setCreateBy(sub.getCreateBy());
		if(sub.getCreateBy() != "") vo.setCreateBy_dictText(u8"����Ա");
		else vo.setCreateBy_dictText(u8"");
		vo.setCreateTime(sub.getCreateTime());
		vo.setFullname(sub.getFullname());
		vo.setHasChild(sub.getHasChild());
		vo.setHasChild_dictText(u8"11");
		vo.setId(sub.getId());
		vo.setIsEnabled(sub.getIsEnabled());
		if(sub.getIsEnabled() == 1)vo.setIsEnabled_dictText(u8"��");
		else vo.setIsEnabled_dictText(u8"��");
		vo.setName(sub.getName());
		vo.setPid(sub.getPid());
		vo.setUpdateBy(sub.getUpdateBy());
		if(sub.getUpdateBy()!="") vo.setUpdateBy_dictText(u8"����Ա");
		else vo.setUpdateBy_dictText(u8"");
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());
		vo.setChildren(res);

		vp.push_back(vo);
	}
	pages.setRows(vp);
	return pages;
}
