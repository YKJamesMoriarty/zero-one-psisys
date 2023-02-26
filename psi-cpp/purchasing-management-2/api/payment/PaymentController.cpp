#include "stdafx.h"
#include "PaymentController.h"
#include "../../service/Payment/PaymentService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//�޸ĵ���״̬
JsonVO<string>  PaymentController::execChangePayment(const PaymentChangeDTO& dto)
{
	PaymentService service;
	JsonVO<string> result;

	// ����У��
	if (dto.getId() == "" || dto.getBill_no() == "") // ���ID�͵��ݱ��Ϊ��
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	if (dto.getOpType() != PaymentChangeDTO::CLOSE && dto.getOpType() != PaymentChangeDTO::UNCLOSE && dto.getOpType() != PaymentChangeDTO::CANCEL)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	// ִ��
	if (service.ChangePayStatus(dto)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case PaymentChangeDTO::CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("�رճɹ�"));
			break;
		case PaymentChangeDTO::UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���رճɹ�"));
			break;
		case PaymentChangeDTO::CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���ϳɹ�"));
			break;
		}
	}
	else {
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case PaymentChangeDTO::CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("�ر�ʧ��"));
			break;
		case PaymentChangeDTO::UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���ر�ʧ��"));
			break;
		case PaymentChangeDTO::CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("����ʧ��"));
			break;
		}
	}
	return result;
}

// ɾ�����뵥
JsonVO<string> PaymentController::execDePayment(const DePaymentDTO& dto)
{
	PaymentService service;
	JsonVO<string> result;
	// ����У��
	if (dto.getId() == "" || dto.getBill_no() == "") {// ���ID�͵��ݱ��Ϊ��
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//ִ������ɾ��
	if (service.DePayment(dto)) {
		result.success(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("ɾ���ɹ�"));
	}
	else {
		result.fail(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("ɾ��ʧ��"));
	}
	//��Ӧ���
	return result;
}

// ������뵥
JsonVO<string> PaymentController::execAddPayment(const AddPaymentDTO& dto)
{
	PaymentService service;
	JsonVO<string> result;
	// ����У��
	if ( dto.getBill_no() == "") {   // ������ݱ��Ϊ��
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//ִ���������
	if (service.AddPay(dto)) {
		result.success(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("��ӳɹ�"));
	}
	else {
		result.fail(dto.getId());
		result.setMessage(CharsetConvertHepler::ansiToUtf8("���ʧ��"));
	}
	//��Ӧ���
	return result;
}

//�������
JsonVO<uint64_t> PaymentController::execAddPayment(const AddPaymentDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PaymentService service;
	//���б����������
	if (dto.getBill_no() == "" || dto.getBill_date() == "" || dto.getOperator() == ""|| dto.getOp_dept() == "" 
		|| dto.getSupplier_id() == "" ) {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	////������ϸ����
	//if (dto.getDetail().size() != 0) {
	//	for (auto d : dto.getDetail())
	//	{
	//		if (d.getEntryNo() < 0 || d.getMaterialId() == "" || d.getUnitId() == ""
	//			|| d.getQty() < 0 || d.getOrderedQty() < 0) {
	//			result.setStatus(RS_PARAMS_INVALID);
	//			result.setData(9999);
	//			return result;
	//		}
	//	}
	//}


	//ִ����������
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.success(100);
	}
	else
	{
		result.fail(9995);
	}
	//��Ӧ���
	return result;
}
