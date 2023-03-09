#include "stdafx.h"
#include "QtrkController.h"
#include "../../service/Qtrk/QtrkService.h"

JsonVO<PageVO<QueryQtrkBillListVO>> QtrkController::execQueryQtrk(const QueryQtrkBillListQuery& query, const PayloadDTO& payload)
{
	QtrkService service;
	PageVO<QueryQtrkBillListVO> result = service.listQtrkBillList(query);
	return JsonVO<PageVO<QueryQtrkBillListVO>>(result, RS_SUCCESS);
}

JsonVO<QueryQtrkBillDetailsVO> QtrkController::execQueryQtrkBillDetails(const QueryQtrkBillDetailsQuery& query)
{
	QtrkService service;
	QueryQtrkBillDetailsVO result = service.getQtrkBillDetails(query);
	return JsonVO<QueryQtrkBillDetailsVO>(result, RS_SUCCESS);
}

JsonVO<int> QtrkController::execAddQtrk(const AddQtrkBillDTO& dto, const PayloadDTO& payload)
{
	JsonVO<int> result;
	QtrkService service;
	//ִ����������
	int id = service.saveBillData(dto, payload);
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

JsonVO<int> QtrkController::execModifyQtrk(const AddQtrkBillDTO& dto, const PayloadDTO& payload)
{
	JsonVO<int> result;
	QtrkService service;
	//ִ����������
	int id = service.updateBillDate(dto, payload);
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

JsonVO<int> QtrkController::execModifyQtrkState(const ModifyQtrkBillDTO& dto, const PayloadDTO& payload)
{
	QtrkService cs;
	JsonVO<int> result;

	if (cs.updataBillStatus(dto, payload)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
	}
	return result;
}

JsonVO<int> QtrkController::execModifyQtrkApproval(const ApprovalDTO& dto, const PayloadDTO& payload)
{
	JsonVO<int> result;
	// ����һ��Service
	QtrkService service;
	// ִ���޸�����(���)
	int id = service.updateApproval(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else if (id == -1) {
		result.setData(id);
		result.setStatus(RS_PARAMS_INVALID);
	}
	else {
		result.fail(id);
	}
	return result;
}

JsonVO<uint64_t> QtrkController::execRemoveQtrk(const DeleteQtrkBillDTO& dto)
{
	JsonVO<uint64_t> result;
	//ִ������ɾ��
	QtrkService cs;

	if (cs.deleteBill(dto)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
	}
	//��Ӧ���
	return result;
}
