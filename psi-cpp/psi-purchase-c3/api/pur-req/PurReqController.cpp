
#include "stdafx.h"
#include "PurReqController.h"
#include "service/pur-req/PurReqService.h"
#include "domain/dto/pur-req/PurReqExportDTO.h"

//��ѯ������Ϣ
JsonVO<PageVO<PurReqFindBillVO>> PurReqController::execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload){
	PurReqFindBillVO test1;
	list<PurReqFindBillVO> ls; 
	ls.push_back(test1);
	PageVO<PurReqFindBillVO> result(1, 2, 0, 0, ls);
	return JsonVO<PageVO<PurReqFindBillVO>>(result, RS_SUCCESS);
}

//��ѯָ��������ϸ��Ϣ
JsonVO<PurReqFindDetailBillVO> PurReqController::execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload){
	PurReqFindDetailBillVO result;
	return JsonVO<PurReqFindDetailBillVO>(result, RS_SUCCESS);
}


//����
nlohmann::json PurReqController::execPurReqExport(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	//��Ӧ���
	return nlohmann::json(JsonVO<std::string>());
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

