#include "stdafx.h"
#include "PurQuotController.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/AddPurQuotVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/DelPurQuotVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/ModPurQuotVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/PurQuotModBillStatusVO.h"
#include "../../domain/dto/purchase-quotation-naiguan/PurQuotDTO.h"
//#include "../../service/purchase-quotation-naiguan/PurQuotService.h"


//��ӹ�Ӧ���ۡ�����ʾ����δʵ��
nlohmann::json PurQuotController::execAddPurQuot(PurQuotDTO dto)
{
	JsonVO<uint64_t> result;
	/*
	//��ʱ���ⲿ��ע�ͣ�����������������������
	//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
	PurQuotService service;
	//ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	//��Ӧ���
	*/
	return nlohmann::json(result);
}

//�޸Ĺ�Ӧ���ۡ�����ʾ����δʵ��
nlohmann::json PurQuotController::execModPurQuot(PurQuotDTO dto)
{
	JsonVO<int> result;
	/*
	//��ʱ���ⲿ��ע�ͣ�����������������������
	//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
	PurQuotService service;
	
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else {
		result.fail(dto.getId());
	}
	*/
	return nlohmann::json(result);
}

//ɾ����Ӧ���ۡ�����ʾ����δʵ��
nlohmann::json PurQuotController::execDelPurQuot(PurQuotDTO dto)
{
	JsonVO<int> result;
	/*
	//��ʱ���ⲿ��ע�ͣ�����������������������
	//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
	PurQuotService service;
	//ִ������ɾ��
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else {
		result.fail(dto.getId());
	}
	//��Ӧ���
	*/
	return nlohmann::json(result);
}

//�޸ı���״̬������ʾ����δʵ��
nlohmann::json PurQuotController::execPurQuotModBillStatus(PurQuotDTO dto)
{
	JsonVO<int> result;
	/*
	//��ʱ���ⲿ��ע�ͣ�����������������������
	//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
	PurQuotService service;

	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else {
		result.fail(dto.getId());
	}
	*/
	return nlohmann::json(result);
}


