
#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"

//��ѯ������Ϣ
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	//��ѯ�ɹ�
	PrePayService service;
	PageVO<PrepaymentBillVO> result = service.listAll(query);
	return JsonVO<PageVO<PrepaymentBillVO>>(result, RS_SUCCESS);
}

//��ѯָ��������ϸ��Ϣ
JsonVO<PageVO<PrepaymentDetailBillVO>> PrePayController::execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload)
{
	PrePayService service;
	PageVO<PrepaymentDetailBillVO> result = service.getAll(query);
	if (result.getTotal() > 0) {
		return JsonVO<PageVO<PrepaymentDetailBillVO>>(result, RS_SUCCESS);
	}
	else {
		return JsonVO<PageVO<PrepaymentDetailBillVO>>(result, RS_PARAMS_INVALID);
	}
	
}

//����Ԥ�����뵥
JsonVO<uint64_t> PrePayController::execAddPay(const  AddPayDTO& dto, const PayloadDTO& payload)
{
	//��Ӧ���
	JsonVO<uint64_t> result;
	PrePayService service;
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	//��Ӧ���
	return result;
}

//�޸�Ԥ�����뵥
JsonVO<uint64_t> PrePayController::execModifyPay(const  AddPayDTO& dto, const PayloadDTO& payload)
{
	PrePayService service;
	JsonVO<uint64_t> result;
	if (service.updateData(dto, payload)) {
		result.success(1);
	}
	else {
		result.fail(0);
	}
	return result;
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


//�޸ĵ���״̬
JsonVO<uint64_t> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto)
{
	PrePayService service;
	JsonVO<uint64_t> result;
	//if (service.updateStatus(dto)) {
	//	result.success(dto.getId());
	//}
	//else {
	//	result.fail(dto.getId());
	//}
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