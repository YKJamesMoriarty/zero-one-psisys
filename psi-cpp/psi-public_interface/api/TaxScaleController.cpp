#include "stdafx.h"
#include "TaxScaleController.h"

/*
��˰��ģ
Author C1 - ��ľ
2023.2.11 22��01��
*/

JsonVO<list<TaxScaleVO>> TaxScaleController::executequeryTaxScale()
{
    list<TaxScaleVO> data;
    TaxScaleVO vo;
    vo.setId(1);
    vo.setName(u8"һ����˰��");
    data.push_back(vo);
    JsonVO<list<TaxScaleVO>> res;
    res.success(data);
    return res;
}
