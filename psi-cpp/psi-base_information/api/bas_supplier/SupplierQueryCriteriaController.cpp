#include "stdafx.h"
#include "SupplierQueryCriteriaController.h"

/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
2023.2.13 21��54��
*/

JsonVO<list<SupplierQueryCriteriaVO>> SupplierQueryCriteriaController::executequerySupplierQueryCriteria()
{
    list<SupplierQueryCriteriaVO> data;
    SupplierQueryCriteriaVO vo;
    vo.setId(1);
    vo.setName(u8"��Ӧ�̷���");
    data.push_back(vo);
    JsonVO<list<SupplierQueryCriteriaVO>> res;
    res.success(data);
    return res;
}
