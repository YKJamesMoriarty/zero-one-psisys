#include "stdafx.h"
#include "TaxRateController.h"
#include "../../service/publicInterfaceService/TaxRateService.h"

/*
˰�������б�
Author C1-��ľ
2023.2.11 21��59��
*/

JsonVO<list<TaxRateVO>> TaxRateController::executequeryTaxRate()
{
    TaxRateService service;
    list<TaxRateVO> data = service.listAll();
    JsonVO<list<TaxRateVO>> res;
    res.success(data);
    return res;
}
