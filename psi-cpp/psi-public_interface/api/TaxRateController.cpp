#include "stdafx.h"
#include "TaxRateController.h"

/*
˰��
Author C1-��ľ
2023.2.11 21��59��
*/

JsonVO<list<TaxRateVO>> TaxRateController::executequeryTaxRate()
{
    list<TaxRateVO> data;
    TaxRateVO vo;
    vo.setId(1);
    vo.setRate("0.17");
    data.push_back(vo);
    JsonVO<list<TaxRateVO>> res;
    res.success(data);
    return res;
}
