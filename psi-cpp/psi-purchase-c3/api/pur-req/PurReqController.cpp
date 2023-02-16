
#include "stdafx.h"
#include "PurReqController.h"
#include "../../domain/query/pur-req/PurReqExportQuery.h"

#include "service/pur-req/PurReqService.h" //���ͷ�ļ��Ǹ����?--����

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


//�������
JsonVO<uint64_t> PurReqController::execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//�޸�����
JsonVO<uint64_t> PurReqController::execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//ɾ������
JsonVO<uint64_t> PurReqController::execRemovePurReqById(const DeletePurReqDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//�޸ĵ���״̬
JsonVO<uint64_t> PurReqController::execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

//����
JsonVO<uint64_t> PurReqController::execPurReqInto(const PurReqIntoDTO& dto)
{
	//��Ӧ���
	return JsonVO<uint64_t>();
}

//����
JsonVO<PurReqExportVO> PurReqController::execPurReqExport(const PurReqExportQuery& query, const PayloadDTO& payload)
{
	//��Ӧ���
	return JsonVO<PurReqExportVO>();
}

