#include "stdafx.h"
#include "SupplierCategoryService.h"
#include "../../dao/supplierDAO/SupplierCategoryDAO.h"
#include "../../domain/do/supplierDO/SupplierCategoryReturnDO.h"
std::list<SuppliersCategoryVO> SupplierCategoryService::listAll(const SupplierCategoryQuery& query)
{
	//�������ض���
	list<SuppliersCategoryVO> vr;
	//������ѯ����
	SupplierCategoryQueryDO obj;
	obj.setName(query.getName());
	//����dao��
	SupplierCategoryDAO dao;
	list<SupplierCategoryReturnDO> result = dao.selectSupplierCategory(obj);
	for (SupplierCategoryReturnDO sub : result)
	{
		SuppliersCategoryVO vo;
		vo.setName(sub.getName());
		vr.push_back(vo);
	}
	return vr;
}
