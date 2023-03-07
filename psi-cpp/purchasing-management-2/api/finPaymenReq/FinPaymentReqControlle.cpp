#include "stdafx.h"
#include "FinPaymentReqControlle.h"
#include "../../service/finPaymentReq/finPyamentReqService.h"

/*
��ѯ�б� 
������: �ͱ���
*/
JsonVO<PageVO<FinPaymentReqVO>> FinPaymentReqControlle::execQueryPayBill(const FinPaymentReqQuery& query, const PayloadDTO& payload) {
	FinPyamentReqService service;
	PageVO<FinPaymentReqVO> result = service.queryList(query);

	return JsonVO<PageVO<FinPaymentReqVO>>(result, RS_SUCCESS);
}

/*
��ѯ����
������: �ͱ���
*/
JsonVO<FinPaymentDetailVO> FinPaymentReqControlle::execQueryPayDetailBill(const FinPaymentReqEntryQuery& query, const PayloadDTO& payload) {
	FinPyamentReqService service;
	FinPaymentDetailVO result = service.detailDate(query);
	JsonVO<FinPaymentDetailVO> jResult;
	if (result.getBillNo().empty())
	{
		jResult.setStatus(RS_PARAMS_INVALID);
		return jResult;
	}
	jResult.success(result);
	return jResult;
}

/*
��Ӷ���
������: �ͱ���
*/
JsonVO<uint64_t> FinPaymentReqControlle::execAddPayHandle(const AddPaymentReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	return result;
}

/*
�޸Ķ���
������: �ͱ���
*/
JsonVO<uint64_t> FinPaymentReqControlle::execModPayHandle(const ModPyamentReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	FinPyamentReqService service;
	//�����������
	if (dto.getBillNo() == "" || dto.getBillDate() == "" || dto.getSupplierId() == ""
		|| dto.getOpDept() == "" || dto.getOperator() == "" || dto.getCreateTime() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	//��ϸ����
	if (dto.getDetail().size() != 0) {
		for (auto d : dto.getDetail())
		{
			if (d.getEntryNo() < 0 ||  d.getAmt() < 0) {
				result.setStatus(RS_PARAMS_INVALID);
				result.setData(9999);
				return result;
			}
		}
	}

	if (!service.removeData(dto.getBillNo())) //���ɾ��ʧ��
	{
		result.fail(9995);
	}

	//�������
	uint64_t id = service.updateData(dto, payload);
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