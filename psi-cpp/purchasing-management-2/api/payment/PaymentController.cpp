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

JsonVO<std::string> PaymentController::execExportPayment(const IntIDs& query)
{
	JsonVO<std::string> result;
	result.success(u8"http://filedownload.com");
	//��Ӧ���
	return result;
}

JsonVO<PaymentVO> PaymentController::exeImportPayment(const PaymentImportDTO& dto)
{
	//����һ������VO
	PaymentVO vo;
	//vo.setNickname(dto.getNickname());
	//vo.setIdCard(dto.getIdCard());
	//vo.setAge(dto.getAge());

	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}

	//��Ӧ���
	return JsonVO<PaymentVO>(vo, RS_API_UN_IMPL);
}
