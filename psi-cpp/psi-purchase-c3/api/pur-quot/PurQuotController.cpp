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
	//��Ӧ���
	return JsonVO<uint64_t>();
}