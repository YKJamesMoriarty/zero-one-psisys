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
	PurQuotFindBillVO test;
	list<PurQuotFindBillVO> ls;
	ls.push_back(test);
	PageVO<PurQuotFindBillVO> result(1, 2, 0, 0, ls);
	return JsonVO<PageVO<PurQuotFindBillVO>>(result, RS_SUCCESS);

}

//��ѯָ�������б�
JsonVO<PurQuotFindDetailBillVO> PurQuotController::execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload) {

	//����һ������VO
	PurQuotFindDetailBillVO vo;
	//��Ӧ���
	return JsonVO<PurQuotFindDetailBillVO>(vo, RS_SUCCESS);
}

//ѯ�۵��б�
JsonVO<PurQuotListVO> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	//����һ������VO
	PurQuotListVO vo;
	//��Ӧ���
	return JsonVO<PurQuotListVO>(vo, RS_SUCCESS);
}
//ѯ�۵���¼�б�
JsonVO<PurQuotDividedListVO> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	//����һ������VO
	PurQuotDividedListVO vo;
	//��Ӧ���
	return JsonVO<PurQuotDividedListVO>(vo, RS_SUCCESS);
}