#include "stdafx.h"
#include "CurrencyController.h"
#include "../../service/currency/CurrencyService.h"

JsonVO<PageVO<CurrencyVO>> CurrencyController::execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload)
{
    //����һ��Service
    CurrencyService service;
    //��ѯ����
    PageVO<CurrencyVO> result = service.listAll(query);
    if ( query.getPageSize() < 1 || query.getPageIndex() < 1)
    {
        return JsonVO<PageVO<CurrencyVO>>(result, RS_PARAMS_INVALID);
    }
    //��Ӧ���
    return JsonVO<PageVO<CurrencyVO>>(result, RS_SUCCESS);
}

JsonVO<CurrencyVO> CurrencyController::execQueryDetail(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload)
{
    CurrencyService service;
    //��ѯ����
    CurrencyVO result = service.listByName(query);
    if(result.getCode().size() == 0) return JsonVO<CurrencyVO>(result, RS_FAIL);
    return JsonVO<CurrencyVO>(result, RS_SUCCESS);
}

JsonVO<uint64_t> CurrencyController::execAddCurrency(const CurrencyDTO& dto, const PayloadDTO& payload)
{
    JsonVO<uint64_t> result;
    CurrencyService service;
    if (dto.getCode().size() == 0 || dto.getName().size() == 0) return JsonVO<uint64_t>(0, RS_PARAMS_INVALID);
    //ִ����������
    uint64_t id = service.saveData(dto, payload);
    if (id > 0) {
        result.success(id);

    }
    else
    {
        result.fail(id);
    }
    //��Ӧ���
    return result;
}

JsonVO<uint64_t> CurrencyController::execModifyCurrency(const CurrencyDTO& dto, const PayloadDTO& payload)
{
    CurrencyService service;
    JsonVO<uint64_t> result;
    if (dto.getCode().size() == 0 || dto.getName().size() == 0) return JsonVO<uint64_t>(0, RS_PARAMS_INVALID);
    bool flag = service.updateData(dto, payload);
    if (flag) {
        result.success(flag);
    }
    else
    {
        result.fail(flag);
    }
    return result;
}

JsonVO<uint64_t> CurrencyController::execRemoveCurrency(const CurrencyDTO& dto)
{
    CurrencyService service;
    JsonVO<uint64_t> result;
    bool flag = service.removeData(dto.getCode());
    //ִ������ɾ��
    if (flag) {
        result.success(flag);
    }
    else
    {
        result.fail(flag);
    }
    //��Ӧ���
    return result;
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