#include "stdafx.h"
#include "SupplierQueryCriteriaController.h"
#include "../../service/supplier/SupplierQueryCriteriaService.h"
/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
*/

JsonVO<list<SupplierQueryCriteriaVO>> SupplierQueryCriteriaController::executequerySupplierQueryCriteria()
{
	SupplierQueryCriteriaService service;
	list<SupplierQueryCriteriaVO> data = service.listAll();
	JsonVO<list<SupplierQueryCriteriaVO>> res;
	res.success(data);
	return res;
}
