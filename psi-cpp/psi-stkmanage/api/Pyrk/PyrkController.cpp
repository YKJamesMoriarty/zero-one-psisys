#include "stdafx.h"
#include "PyrkController.h"
#include "../../service/Pyrk/PyrkService.h"



//��ѯ�����б�
JsonVO<PageVO<QueryPyrkBillListVO>> PyrkController::execQueryPyrkBillList (const QueryPyrkBillListQuery& query)
{

	PyrkService service;
	PageVO<QueryPyrkBillListVO> result = service.listPyrkBillList(query);
	return JsonVO<PageVO<QueryPyrkBillListVO>>(result, RS_SUCCESS);


}

//�鿴ָ��������ϸ��Ϣ
JsonVO<QueryPyrkBillDetailsVO> PyrkController::execQueryPyrkBillDetails(const QueryPyrkBillDetailsQuery& query)
{
	PyrkService service;
	QueryPyrkBillDetailsVO result = service.getPyrkBillDetails(query);
	return JsonVO<QueryPyrkBillDetailsVO>(result, RS_SUCCESS);
}

JsonVO<int> PyrkController::exeAddBillDetailed(const PyrkBillDetailDTO& addMessage) {
    return JsonVO<int>(1, RS_SUCCESS);
}

JsonVO<int> PyrkController::exeUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage) {
    return JsonVO<int>(1, RS_SUCCESS);
}

JsonVO<uint64_t> PyrkController::execRemovePyrkBillById(const StringID& id)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyPyrkBillStateToClose(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyPyrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<uint64_t> PyrkController::execModifyPyrkBillStateToVoid(const StringID& id, const PayloadDTO& payload)
{ 
	JsonVO<uint64_t> result;
	uint64_t data = 0;
	result.success(data);
	return result;
}

JsonVO<ImportPyrkFileVO> PyrkController::execImportPyrkFile(const ImportPyrkFileDTO& dto, const PayloadDTO& payload)
{
	JsonVO<ImportPyrkFileVO> result;
	ImportPyrkFileVO vo;
	result.success(vo);
	return result;
}

JsonVO<string> PyrkController::execExportPyrkFile(const StringIDs& ids)
{
	JsonVO<string> result;
	string s = "www.baidu.com";
	result.success(s);
	return result;
}
