#include "PurQuotController.h"

//#include "../../service/purchase-quotation-naiguan/PurQuotService.h"


//��ӹ�Ӧ���ۡ�����ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execAddPurQuot(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//��ʱ���ⲿ��ע�ͣ�����������������������
//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
//DTO�����û��дĬ�Ϲ��캯�������getId()û��ֵ
//���⣬Servie���ֻ�û��д�����û��SampleService�࣬�޷���service.updateData(dto)�������жϣ���Ȼ������������ʽ�����
	SampleService service;
	//ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	*/
	return result;
}

//�޸Ĺ�Ӧ���ۡ�����ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execModPurQuot(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//��ʱ���ⲿ��ע�ͣ�����������������������
//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
//DTO�����û��дĬ�Ϲ��캯�������getId()û��ֵ
//���⣬Servie���ֻ�û��д�����û��SampleService�࣬�޷���service.updateData(dto)�������жϣ���Ȼ������������ʽ�����

	SampleService service;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	*/
	return result;
}

//ɾ����Ӧ���ۡ�����ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execDelPurQuot(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//��ʱ���ⲿ��ע�ͣ�����������������������
//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
//DTO�����û��дĬ�Ϲ��캯�������getId()û��ֵ
//���⣬Servie���ֻ�û��д�����û��SampleService�࣬�޷���service.updateData(dto)�������жϣ���Ȼ������������ʽ�����
	SampleService service;
	//ִ������ɾ��
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//��Ӧ���
	*/
	return result;
}

//�޸ı���״̬������ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execPurQuotModBillStatus(const PurQuotDTO& dto)
{
	JsonVO<uint64_t> result;
	/*
//��ʱ���ⲿ��ע�ͣ�����������������������
//���ͣ����Ƕ���ӿڵ�ʱ�򣬲ο�Sample�İ�����û��ʵ�֣�������APIPost����
//DTO�����û��дĬ�Ϲ��캯�������getId()û��ֵ
//���⣬Servie���ֻ�û��д�����û��SampleService�࣬�޷���service.updateData(dto)�������жϣ���Ȼ������������ʽ�����

	SampleService service;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	*/
	return result;
}


