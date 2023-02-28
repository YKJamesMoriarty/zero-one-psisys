
#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//��ѯ������Ϣ
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
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
	PrepaymentDetailBillVO result = service.getAll(query);
	return JsonVO<PrepaymentDetailBillVO>({}, RS_SUCCESS);
}

JsonVO<string> PrePayController::execRemoveDePayId(const DePayDTO& dto)
{
	PrePayService service;
	JsonVO<string> result;
	// ����У��
	if (dto.getId() == "" || dto.getBill_no() == "") {// ���ID�͵��ݱ��Ϊ��
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	}
	//ִ������ɾ��
	if (service.DePrePayId(dto)) {
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
