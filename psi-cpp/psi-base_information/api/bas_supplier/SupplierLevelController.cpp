#include "stdafx.h"
#include "SupplierLevelController.h"

/*
��Ӧ�̵ȼ������б�
Author C1-��ľ
2023.2.11 21��35��
*/


JsonVO<list<SupplierLevelVO>> SupplierLevelController::executequerySupplierLevel()
{
    list<SupplierLevelVO> data;
    SupplierLevelVO vo;
    vo.setId(1);
    vo.setName(u8"һ��");
    data.push_back(vo);
    JsonVO<list<SupplierLevelVO>> res;
    res.success(data);
    return res;
}
