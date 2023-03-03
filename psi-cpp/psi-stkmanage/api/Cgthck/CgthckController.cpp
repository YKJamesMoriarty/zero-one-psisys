#include "stdafx.h"
#include "CgthckController.h"
#include"../../service/Cgthck/CgthckService.h"
#include"domain/dto/Cgthck/CgthckBillDetailedDTO.h"
JsonVO<PageVO<QueryCgthckBillVO>> CgthckController::execQueryCgthckBill(const QueryCgthckBillQuery& query)
{
    //����һ��Service
    CgthckService service;
    //��ѯ���
    PageVO<QueryCgthckBillVO> result = service.queryAllFitBill(query);
    //��Ӧ���
    return JsonVO<PageVO<QueryCgthckBillVO>>(result, RS_SUCCESS);
}

JsonVO<QueryCgthrkDetailedBillVO> CgthckController::execQueryCgthckBillDetail(const CgthckBillDetailedDTO& query)
{
    //����һ��Service
    CgthckService service;

    //��ѯ���
    QueryCgthrkDetailedBillVO result = service.queryBillDetial(query);

    //��Ӧ���
    return JsonVO<QueryCgthrkDetailedBillVO>(result, RS_SUCCESS);
}

JsonVO<uint64_t> CgthckController::execAddCgthckBill(const AddCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execModifyCgthckBill(const ModifyCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execDeleteCgthckBill(const DeleteCgthckBillDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execImportCgthckFile(const ImportCgthckFileDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}

JsonVO<uint64_t> CgthckController::execExportCgthckFile(const ExportCgthckFileDTO& dto)
{
    JsonVO<uint64_t> result;
    result.success(1);
    return result;
}
