#pragma once


#ifndef _PAY_APPLY_CONTROLLER_
#define _PAY_APPLY_CONTROLLER_

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillQuery.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillDetailQuery.h"
#include "../../domain/vo/PaymentBillImpl/PaymentBillVO.h"
#include "../../domain/vo/PaymentBillImpl/PaymentBillDetailVO.h"
#include "../../domain/dto/Payment/AddPaymentDTO.h"
#include "../../domain/dto/PaymentBillImpl/ModPayApplyDTO.h"


/**
 * �ɹ����빦�ܵ�
 */
class PayApplyControlle
{
public:
	//��ѯ�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentBill, execQueryPayBill, PaymentBillQuery);
	//��ѯ��ϸ����
	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentDetailBill, execQueryPayDetailBill, PaymentBillDetailQuery);
	//���
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPayApply, execAddPayHandle, AddPaymentDTO);
	//�޸�
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPayReqApply, execModPayHandle, ModPayApplyDTO);

private:
	//��ѯ�б�
	JsonVO<PageVO<PaymentBillVO>> execQueryPayBill(const PaymentBillQuery& query, const PayloadDTO& payload);
	//��ѯ��ϸ����
	JsonVO<PaymentBillDetailVO> execQueryPayDetailBill(const PaymentBillDetailQuery& query, const PayloadDTO& payload);
	//���
	JsonVO<uint64_t> execAddPayHandle(const AddPaymentDTO& dto, const PayloadDTO& payload);
	//�޸�
	JsonVO<uint64_t> execModPayHandle(const ModPayApplyDTO& dto, const PayloadDTO& payload);

};
#endif 
