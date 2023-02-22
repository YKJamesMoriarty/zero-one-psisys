#include "stdafx.h"
#include "CurrencyController.h"
#include "../../service/currency/CurrencyService.h"

JsonVO<PageVO<CurrencyVO>> CurrencyController::execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload)
{
    //����һ��Service
    CurrencyService service;
    //��ѯ����
    PageVO<CurrencyVO> result = service.listAll(query);
    //��Ӧ���
    return JsonVO<PageVO<CurrencyVO>>(result, RS_SUCCESS);
}

JsonVO<CurrencyVO> CurrencyController::execQueryDetail(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    CurrencyService service;
    //��ѯ����
    CurrencyVO result = service.listByName(query);
    return JsonVO<CurrencyVO>(result, RS_SUCCESS);
}

JsonVO<CurrencyActionInfoVO> CurrencyController::execQueryActionInfo(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<CurrencyActionInfoVO>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execAddCurrency(const CurrencyDTO& dto)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execModifyCurrency(const CurrencyDTO& dto)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execRemoveCurrency(const OnlyValueCurrencyQuery& query)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<PageVO<CurrencyVO>> CurrencyController::execAddCurrencys(const CurrencyDTO& dto)
{
    return JsonVO<PageVO<CurrencyVO>>();
}

JsonVO<string> CurrencyController::execExportExecl(const CurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

JsonVO<string> CurrencyController::execExportExeclOnly(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}