#include "stdafx.h"
#include "TaxScaleController.h"
#include "../../service/publicInterfaceService/TaxScaleService.h"

/*
��˰��ģ�����б�
Author C1 - ��ľ
*/

JsonVO<list<TaxScaleVO>> TaxScaleController::executequeryTaxScale()
{
    TaxScaleService service;
    list<TaxScaleVO> data = service.listAll();
    JsonVO<list<TaxScaleVO>> res;
    res.success(data);
    return res;
}
