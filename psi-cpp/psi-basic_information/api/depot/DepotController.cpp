#include "stdafx.h"
#include "DepotController.h"

/*
* ���̴�Լ�ǣ�����->Service->dao Ȼ�� ServiceҪ�õ�Do,dao��ʵ��Ҫ�õ�Mapper
* ����Service�Ĺ��ܴ�ž��ǲ�ͬ����֮�����ݵİ󶨺͵���DAO�����ݿ⽻��
* DAO����ֱ�Ӻ����ݿ⽻������Ҫ����Mapper���ֶκͶ������Թ�������
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
    //����һ��Service
    DepotService service;
    //��ѯ����
    DepotVO result = service.listKid(query);
    // ͨ��Id��pid�Ĺ�ϵ���߼��Ͳ�ѯ��൫û���÷�ҳ
    return JsonVO<DepotVO>(result, RS_SUCCESS);
}

JsonVO<DepotDetailVO> DepotController::execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotDetailVO>();
}

JsonVO<DepotActionInfoVO> DepotController::execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<DepotActionInfoVO>();
}

JsonVO<PageVO<DepotVO>> DepotController::execAddDepot(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<PageVO<DepotVO>> DepotController::execModifyDepot(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<PageVO<DepotVO>> DepotController::execRemoveDepot(const OnlyValueQuery& query)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<PageVO<DepotVO>> DepotController::execAddDepots(const DepotDTO& dto)
{
    return JsonVO<PageVO<DepotVO>>();
}

JsonVO<string> DepotController::execExportExecl(const DepotQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    return JsonVO<string>();
}

