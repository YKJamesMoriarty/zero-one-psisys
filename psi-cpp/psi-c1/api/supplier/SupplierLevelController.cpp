#include "stdafx.h"
#include "SupplierLevelController.h"
#include "../../service/supplier/SupplierLevelService.h"

/*
��Ӧ�̵ȼ������б�
Author C1-��ľ
2023.2.11 21��35��
*/


JsonVO<list<SupplierLevelVO>> SupplierLevelController::executequerySupplierLevel()
{
	SupplierLevelService service;
	list<SupplierLevelVO> data = service.listAll();
	JsonVO<list<SupplierLevelVO>> res;
	res.success(data);
	return res;
}
