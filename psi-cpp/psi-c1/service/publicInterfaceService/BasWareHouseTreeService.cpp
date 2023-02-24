#include "stdafx.h"
#include "BasWareHouseTreeService.h"
#include"./dao/publicInterfaceDao/BasWareHouseTreeDAO.h"

PageVO<BasWareHouseTreeListVO> BasWareHouseTreeService::listAll(const BasWareHouseItemQuery& query)
{
	//�������ض���
	PageVO<BasWareHouseTreeListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	//��ѯ����������
	BasWareHouseTreeDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	BasWareHouseTreeDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//��ҳ��ѯ����
	cout << "count: " << count << endl;
	pages.setTotal(count);
	pages.calcPages();
	list<BasWareHouseTreeDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<BasWareHouseTreeListVO> vp;
	//�ӽڵ�list
	list<BasWareHouseTreeListVO> vc;
	cout << "size" << result.size() << endl;
	for (BasWareHouseTreeDO sub : result)
	{
		//�������ӽڵ�Ϳ�ʼ����
		vector< BasWareHouseTreeListVO> res;
		if (sub.getHasChild() == "1") {
			BasWareHouseTreeListVO co;
			for (BasWareHouseTreeDO cb : result) {
				if (cb.getPid() == sub.getId()) {
					co.setCode(cb.getCode());
					co.setCreateBy(cb.getCreateBy());

					if (sub.getCreateBy() != "") co.setCreateBy_dictText(u8"����Ա");
					else co.setCreateBy_dictText(u8"");

					co.setCreateTime(cb.getCreateTime());
					co.setAuxName(cb.getAuxName());
					co.setHasChild(cb.getHasChild());
					co.setId(cb.getId());
					co.setIsEnabled(cb.getIsEnabled());

					if (sub.getIsEnabled() == 1) co.setIsEnable_dictText(u8"��");
					else co.setIsEnable_dictText(u8"��");

					co.setPhone(cb.getPhone());
					co.setName(cb.getName());
					co.setPid(cb.getPid());
					co.setRemark(cb.getRemark());
					co.setUpdateBy(cb.getUpdateBy());

					if (cb.getUpdateBy() != "")	co.setUpdateBy_dictText(u8"����Ա");
					else co.setUpdateBy_dictText(u8"");

					co.setUpdateTime(cb.getUpdateTime());
					co.setVersion(cb.getVersion());
					res.push_back(co);
				}
			}
		}

		BasWareHouseTreeListVO vo;
		vo.setCode(sub.getCode());
		vo.setCreateBy(sub.getCreateBy());
		if (sub.getCreateBy() != "") vo.setCreateBy_dictText(u8"����Ա");
		else vo.setCreateBy_dictText(u8"");
		vo.setCreateTime(sub.getCreateTime());
		vo.setAuxName(sub.getAuxName());
		vo.setHasChild(sub.getHasChild());
		vo.setId(sub.getId());
		vo.setIsEnabled(sub.getIsEnabled());
		if (sub.getIsEnabled() == 1)vo.setIsEnable_dictText(u8"��");
		else vo.setIsEnable_dictText(u8"��");
		vo.setName(sub.getName());

		vo.setPhone(sub.getPhone());
		vo.setRemark(sub.getRemark());
		vo.setPid(sub.getPid());
		vo.setUpdateBy(sub.getUpdateBy());
		if (sub.getUpdateBy() != "") vo.setUpdateBy_dictText(u8"����Ա");
		else vo.setUpdateBy_dictText(u8"");
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());
		vo.setChildren(res);

		vp.push_back(vo);
	}
	pages.setRows(vp);
	return pages;
}
