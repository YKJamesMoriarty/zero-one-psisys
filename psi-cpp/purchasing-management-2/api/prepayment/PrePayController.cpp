
#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"

//��ѯ������Ϣ
JsonVO<PageVO<PrepaymentBillVO>> PrePayController::execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<PrepaymentBillVO>> rs;

	PageVO<PrepaymentBillVO> data;
	std::list<PrepaymentBillVO> rows;
	rows.push_back(PrepaymentBillVO());
	rows.push_back(PrepaymentBillVO());
	rows.push_back(PrepaymentBillVO());
	data.setRows(rows);
	return rs;
}

//��ѯָ��������ϸ��Ϣ
JsonVO<PrepaymentDetailBillVO> PrePayController::execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload)
{
		PrepaymentDetailBillVO result;
		return JsonVO<PrepaymentDetailBillVO>(result, RS_SUCCESS);
}

//����
JsonVO<uint64_t> PrePayController::execPayInto(const PayIntoDTO& dto)
{
	JsonVO<uint64_t> result;
	//��Ӧ���
	return JsonVO<uint64_t>();
}

//����
	JsonVO<PrepaymentExportVO> PrePayController::execPrepayExport(const PrePayExportQuery & query, const PayloadDTO & payload)
{
	//��Ӧ���
	return JsonVO<PrepaymentExportVO>();
}

//��������
JsonVO<uint64_t> PrePayController::execAddPay(const  AddPayDTO& dto)
{
	JsonVO<uint64_t> result;	
	return result;
}
//�޸Ķ���
JsonVO<uint64_t> PrePayController::execModifyPay(const  PrepaymentDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}
//�޸ĵ���״̬
JsonVO<uint64_t> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(200);
	return result;
}

// ɾ������
JsonVO<uint64_t> PrePayController::execRemovePayById(const DePayDTO& id)
{
	JsonVO<uint64_t> result;
	return result;
}


