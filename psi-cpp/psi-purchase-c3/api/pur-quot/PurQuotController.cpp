#include "stdafx.h"
#include "PurQuotController.h"


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
	//��Ӧ���
	return JsonVO<PurQuotExportVO>();
}

//����
JsonVO<uint64_t> PurQuotController::execPurQuotInto(const PurQuotIntoDTO& dto)
{
	JsonVO<uint64_t> result;
	//��Ӧ���
	return JsonVO<uint64_t>();
}

//��ѯ�����б�
JsonVO<PageVO<PurQuotFindBillVO>> PurQuotController::execQueryPurQuotFindBill(const PurQuotFindBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindBillVO test;
	list<PurQuotFindBillVO> ls;
	ls.push_back(test);
	PageVO<PurQuotFindBillVO> result(1, 2, 0, 0, ls);
	return JsonVO<PageVO<PurQuotFindBillVO>>(result, RS_SUCCESS);
}

//��ѯָ�������б�
JsonVO<PurQuotFindDetailBillVO> PurQuotController::execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindDetailBillVO result;
	//��Ӧ���
	return JsonVO<PurQuotFindDetailBillVO>(result, RS_SUCCESS);
}


JsonVO<PageVO<PurQuotListVO>> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	PageVO<PurQuotListVO> result;
	return JsonVO<PageVO<PurQuotListVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurQuotDividedListVO>> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	PageVO<PurQuotDividedListVO> result;
	return JsonVO<PageVO<PurQuotDividedListVO>>(result, RS_SUCCESS);
}