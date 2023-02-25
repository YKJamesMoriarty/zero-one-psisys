
#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//��ѯ������Ϣ
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	//todo������У��
	if (query.getBill_no() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getBill_date() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getSubject() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getSupplier_id() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}
	if (query.getBill_stage() == "") {
		return JsonVO<PageVO<PrepaymentBillVO>>({}, RS_PARAMS_INVALID);
	}

	//��ѯ�ɹ�
	PrePayService service;
	PageVO<PrepaymentBillVO> result = service.listAll(query);
	return JsonVO<PageVO<PrepaymentBillVO>>(result, RS_SUCCESS);
}

//��ѯָ��������ϸ��Ϣ
JsonVO<PrepaymentDetailBillVO> PrePayController::execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload)
{
	if (query.getBill_no() == "") {
		return JsonVO<PrepaymentDetailBillVO>({}, RS_PARAMS_INVALID);
}
	PrePayService service;
	PageVO<PrepaymentDetailBillVO> result = service.getAll(query);
	return JsonVO<PrepaymentDetailBillVO>({}, RS_SUCCESS);
}

//����
JsonVO<uint64_t> PrePayController::execPayInto(const PayIntoDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//��Ӧ���
	return JsonVO<uint64_t>(result);
}

//����
JsonVO<PrepaymentExportVO> PrePayController::execPrepayExport(const PrePayExportQuery& query, const PayloadDTO& payload)
{
	//��Ӧ���
	JsonVO<uint64_t> result;
	result.success(200);
	return JsonVO<PrepaymentExportVO>();
}

//����Ԥ�����뵥
JsonVO<uint64_t> PrePayController::execAddPay(const  AddPayDTO& dto)
{

	JsonVO<uint64_t> result;	
	PrePayService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else{
		result.fail(id);
	}
	//��Ӧ���
	return result;
}

//�޸�Ԥ�����뵥
JsonVO<string> PrePayController::execModifyPay(const  PrepaymentDTO& dto)
{
	PrePayService service;
	JsonVO<string> result;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else{
		result.fail(dto.getId());
	}
	return result;
}

//�޸ĵ���״̬
JsonVO<string> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	PrePayService service;
	JsonVO<string> result;

	// ����У��
	if (dto.getId() == "" || dto.getBill_no() == "") // ���ID�͵��ݱ��Ϊ��
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	// ���������Ϊ�ջ��߲���ö������Ԫ�����������
	if (dto.getOpType() != dto.CLOSE && dto.getOpType() != dto.CANCEL && dto.getOpType() != dto.UNCLOSE)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	// ִ��
	if (service.updateStatus(dto, payload)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("�رճɹ�"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���رճɹ�"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���ϳɹ�"));
			break;
		}
	}
	else {
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("�ر�ʧ��"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("���ر�ʧ��"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("����ʧ��"));
			break;
		}
	}
	return result;
}

// ɾ��Ԥ�����뵥
JsonVO<uint64_t> PrePayController::execRemoveDePay(const DePayDTO& dto)
{
	PrePayService service;
	JsonVO<uint64_t> result;
	//ִ������ɾ��
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//��Ӧ���
	return result;
}

JsonVO<uint64_t> PrePayController::execRemovePayById(const IntID& id)
{
	DePayDTO dto;
	dto.setId(id.getId());
	return execRemoveDePay(dto);
}