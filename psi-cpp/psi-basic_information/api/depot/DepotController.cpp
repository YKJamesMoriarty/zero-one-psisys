#include "stdafx.h"
#include "DepotController.h"

/*
* ����У��
* �Ľӿڷ���ֵ
* ������Ϣ��̨ PayloadDTO��ô����ˣ��޸���
* ID��������com-ѩ��
* �ɹ�ʾ����ʧ��ʾ��
* 
*/

JsonVO<PageVO<DepotVO>> DepotController::execQueryDepot(const DepotQuery& query, const PayloadDTO& payload)
{
    //����һ��Service
    DepotService service;
    //��ѯ����
    PageVO<DepotVO> result = service.listAll(query);
    //��Ӧ���
    return JsonVO<PageVO<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<DepotVO> DepotController::execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotVO>();
}

JsonVO<DepotDetailVO> DepotController::execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotDetailVO>();
}

JsonVO<DepotActionInfoVO> DepotController::execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotActionInfoVO>();
}

JsonVO<string> DepotController::execAddDepot(const DepotDTO& dto)
{
    JsonVO<string> result;
    //����һ��Service
    DepotService service;
    //��������
    uint64_t id = service.saveData(dto);
    if (id > 0) {
        result.success(to_string(id));
    }
    else {
        result.fail(to_string(id));
    }
    return result;
}

JsonVO<string> DepotController::execModifyDepot(const DepotDTO& dto)
{
    //����һ��Service
    DepotService service;
    return JsonVO<string>();
}

JsonVO<bool> DepotController::execRemoveDepot(const OnlyValueQuery& query)
{
    JsonVO<bool> result;
    //����һ��Service
    DepotService service;
    //ɾ������
    if (service.removeData(query)) {
        result.success(true);
    }
    else
    {
        result.fail(false);
    }
    return result;
}

JsonVO<int> DepotController::execAddDepots(const DepotDTO& dto)
{
    return JsonVO<int>();
}

JsonVO<string> DepotController::execExportExecl(const DepotQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

