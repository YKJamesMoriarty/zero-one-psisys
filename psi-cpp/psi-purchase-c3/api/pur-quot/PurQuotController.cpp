#include "stdafx.h"
#include "PurQuotController.h"
#include "../../service/pur-quot/PurQuotService.h"

//��ӹ�Ӧ���ۡ�����ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//�޸Ĺ�Ӧ���ۡ�����ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

//ɾ����Ӧ���ۡ�����ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execDelPurQuotById(const DelPurQuotDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}

//�޸ı���״̬������ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}


//����
JsonVO<PurQuotExportVO> PurQuotController::execPurQuotExport(const PurQuotExportQuery& dto, const PayloadDTO& payload)
{
	//����һ������VO
	PurQuotExportVO vo;
	//��Ӧ���
	return JsonVO<PurQuotExportVO>(vo, RS_SUCCESS);;
}

//����
JsonVO<PurQuotIntoVO> PurQuotController::execPurQuotInto(const PurQuotIntoDTO& dto)
{
	//����һ������VO
	PurQuotIntoVO vo;
	//��Ӧ���
	return JsonVO<PurQuotIntoVO>(vo, RS_SUCCESS);;
}

//��ѯ�����б�
JsonVO<PageVO<PurQuotFindBillVO>> PurQuotController::execQueryPurQuotFindBill(const PurQuotFindBillQuery& query, const PayloadDTO& payload) {
	//��δ��ʼ����У��

	//����һ��Service
	PurQuotService service;
	//�������ض���
	PageVO<PurQuotFindBillVO> result	= service.listPurQuotFindBillVO(query);
	//��Ӧ���
	return JsonVO<PageVO<PurQuotFindBillVO>>(result, RS_SUCCESS);
}



//��ѯָ�������б�
JsonVO<PurQuotFindDetailBillVO> PurQuotController::execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindDetailBillVO result;
	//��ʱδ��������У��
	if(query.getBill_no() == "") return JsonVO<PurQuotFindDetailBillVO>(result, RS_PARAMS_INVALID);
	PurQuotService service;
	result = service.getPurQuotFindDetailBillVO(query);
	//��Ӧ���
	return JsonVO<PurQuotFindDetailBillVO>(result, RS_SUCCESS);
}

//ѯ�۵��б�
JsonVO<list<PurQuotListVO>> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	//�������ض���
	list<PurQuotListVO> result;
	//����У��
	if(query.getBill_no() == "") return JsonVO<list<PurQuotListVO>>(result, RS_PARAMS_INVALID);

	//����У��ɹ�,���ض�Ӧ�Ķ���
	PurQuotService service;	
	result = service.listPurQuotListVO(query);
	return JsonVO<list<PurQuotListVO>>(result, RS_SUCCESS);
}
//ѯ�۵���¼�б�
JsonVO<list<PurQuotDividedListVO>> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	//�������ض���
	list<PurQuotDividedListVO> result;
	//����У��
	if(query.getBill_no() == "") return JsonVO<list<PurQuotDividedListVO>>(result, RS_PARAMS_INVALID);

	//����У��ɹ�,���ض�Ӧ�Ķ���
	PurQuotService service;
	result = service.listPurQuotDividedListVO(query);
	return JsonVO<list<PurQuotDividedListVO>>(result, RS_SUCCESS);
}

