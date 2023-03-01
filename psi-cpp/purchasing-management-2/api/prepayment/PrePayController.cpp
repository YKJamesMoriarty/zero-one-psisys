#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

//�ɹ������б�
JsonVO<PageVO<PurOrderVO>> PrePayController::execQuerypayFindBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	PrePayService service;
	PageVO<PurOrderVO> result = service.listAll(query);
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

//�ɹ��������б�
JsonVO<PurOrderVO> PrePayController::execQueryPayDetailBill(const PurOrderQuery& query, const PayloadDTO& payload)
{
	if (query.getBill_no() == "") {
		return JsonVO<PurOrderVO>({}, RS_PARAMS_INVALID);
}
	PrePayService service;
	PurOrderVO result = service.getAll(query);
	return JsonVO<PurOrderVO>({}, RS_SUCCESS);
}

//ɾ��
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
