
#include "stdafx.h"
#include "PurReqController.h"
#include "service/pur-req/PurReqService.h"
#include "domain/query/pur-req/PurReqExportQuery.h"

//��ѯ������Ϣ
JsonVO<PageVO<PurReqFindBillVO>> PurReqController::execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload){
	JsonVO<PageVO<PurReqFindBillVO>> rs;

	PageVO<PurReqFindBillVO> data;
	std::list<PurReqFindBillVO> rows;
	rows.push_back(PurReqFindBillVO());
	rows.push_back(PurReqFindBillVO());
	rows.push_back(PurReqFindBillVO());
	data.setRows(rows);
	return rs;
}

//��ѯָ��������ϸ��Ϣ
JsonVO<PurReqFindDetailBillVO> PurReqController::execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload){
	PurReqFindDetailBillVO result;
	return JsonVO<PurReqFindDetailBillVO>(result, RS_SUCCESS);
}


//����
JsonVO<std::string> PurReqController::execPurReqExport(const PurReqExportQuery& query, const PayloadDTO& payload)
{
	//��Ӧ���
	return JsonVO<std::string>();
}

//����
JsonVO<PurReqIntoVO> PurReqController::execPurReqInto(const PurReqIntoDTO& dto)
{
	//��Ӧ���
	return JsonVO<PurReqIntoVO>();
}



//��������
JsonVO<uint64_t> PurReqController::execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//�޸Ķ���
JsonVO<uint64_t> PurReqController::execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//�޸Ķ���״̬
JsonVO<uint64_t> PurReqController::execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto,  const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//ɾ������
JsonVO<uint64_t> PurReqController::execRemovePurReqById(const DeletePurReqDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}

