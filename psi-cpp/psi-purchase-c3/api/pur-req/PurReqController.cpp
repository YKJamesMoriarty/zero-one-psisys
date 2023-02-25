#include "stdafx.h"
#include "PurReqController.h"
#include "../../service/pur-req/PurReqService.h"



//��ѯ������Ϣ
JsonVO<PageVO<PurReqFindBillVO>> PurReqController::execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload) {
	PurReqService service;
	PageVO<PurReqFindBillVO> result = service.listAll(query);

	return JsonVO<PageVO<PurReqFindBillVO>>(result, RS_SUCCESS);
}

//��ѯָ��������ϸ��Ϣ
JsonVO<PurReqFindDetailBillVO> PurReqController::execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurReqService service;
	PurReqFindDetailBillVO result = service.detailsOne(query);
	JsonVO<PurReqFindDetailBillVO> jResult;
	if (result.getBill_no().empty())
	{
		jResult.setStatus(RS_PARAMS_INVALID);
		return jResult;
	}
	jResult.success(result);
	return jResult;
}



//�������
JsonVO<uint64_t> PurReqController::execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurReqService service;
	//���б����������
	if (dto.getBillNo() == "" || dto.getBillDate() == "" || dto.getRequestDept() == "" 
		|| dto.getRequester()=="" || dto.getRequestTime() == "" ||dto.getBillStage() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	//������ϸ����
	if (dto.getDetail().size() != 0) {
		for (auto d : dto.getDetail())
		{
			if (d.getEntryNo() < 0  || d.getMaterialId() == "" || d.getUnitId() == ""
				|| d.getQty() < 0 || d.getOrderedQty() < 0) {
				result.setStatus(RS_PARAMS_INVALID);
				result.setData(9999);
				return result;
			}
		}
	}


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

//�޸�����
JsonVO<uint64_t> PurReqController::execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurReqService service;
	//���б����������
	if (dto.getBillNo() == "" || dto.getBillDate() == "" || dto.getRequestDept() == ""
		|| dto.getRequester() == "" || dto.getRequestTime() == "" || dto.getBillStage() == ""
		|| dto.getSysOrgCode() == "" || dto.getCreateBy() == "" || dto.getCreateTime() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	//������ϸ����
	if (dto.getDetail().size() != 0) {
		for (auto d : dto.getDetail())
		{
			if (d.getEntryNo() < 0 || d.getMaterialId() == "" || d.getUnitId() == ""
				|| d.getQty() < 0 || d.getOrderedQty() < 0) {
				result.setStatus(RS_PARAMS_INVALID);
				result.setData(9999);
				return result;
			}
		}
	}
	//���и�ʽ���� ��ʱ����
	
	//ִ������ɾ��
	if (!service.removeData(dto.getBillNo())) //���ɾ��ʧ��
	{
		result.fail(9995);
	}
	//ִ���������
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

//ɾ������ ���
JsonVO<uint64_t> PurReqController::execRemovePurReqById(const DeletePurReqDTO& dto)
{
	PurReqService service;
	JsonVO<uint64_t> result;
	//���б����������
	if (dto.getBillNo() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}
	//ִ������ɾ��
	if (service.removeData(dto.getBillNo())) {
		result.success(100);
	}
	else
	{
		result.fail(9995);
	}
	//��Ӧ���
	return result;
}

//�޸ĵ���״̬ ���
JsonVO<uint64_t> PurReqController::execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurReqService service;

	//���б����������
	if (dto.getBillNo() == "") {
		result.setStatus(RS_PARAMS_INVALID);
		result.setData(9999);
		return result;
	}

	//ִ������״̬�޸�
	uint64_t id = service.updateBillStatus(dto, payload);
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

//����
JsonVO<uint64_t> PurReqController::execPurReqInto(const PurReqIntoDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	//�����ļ����ҽ���execl����
	PurReqService service;
	uint64_t ret = 1;
	for (string file : dto.getFiles()) {
		ret = service.getFromExecl(file, payload);
		if (ret == 0)
		{
			result.fail(9995);
			break;
		}
	}
	//��Ӧ���
	if (ret)
	{
		result.success(100);
	}	
	return result;
}

//����
JsonVO<string> PurReqController::execPurReqExport(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	JsonVO<string> result;
	PurReqService service;
	string url = service.getToExecl(dto.getBillNoList());
	if (url == "")
	{
		result.fail("");
	}
	else {
		result.success(url);
	}
	//��Ӧ���
	return result;
}

