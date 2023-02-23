#pragma once


#ifndef _PAY_APPLY_CONTROLLER_
#define _PAY_APPLY_CONTROLLER_

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillQuery.h"
#include "../../domain/query/PaymentBillImpl/PaymentBillDetailQuery.h"
#include "../../domain/vo/PaymentBillImpl/PaymentBillVO.h"
#include "../../domain/dto/PaymentBillImpl/AddPayApplyDTO.h"
#include "../../domain/dto/PaymentBillImpl/ModPayApplyDTO.h"


/**
 * �ɹ����빦�ܵ�
 */
class PayReqController
{
public:
	//��ѯ�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentBill, execQueryPayBill, PaymentBillQuery);
	//��ѯ��ϸ����
	CREATE_API_FUN_QUERY_PAYLOAD(queryPaymentDetailBill, execQueryPayDetailBill, PaymentBillDetailQuery);
	//���
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPayApply, execAddPayHandle , AddPayApplyDTO);
	//�޸�
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modPayReqApply, execModPayHandle , ModPayApplyDTO);

private:
	//��ѯ�б�
	JsonVO<PageVO<PaymentBillQuery>> execQueryPayBill(const PaymentBillQuery& query, const PayloadDTO& payload);
	//��ѯ��ϸ����
	JsonVO<PaymentBillDetailQuery> execQueryPayDetailBill(const PaymentBillDetailQuery& query, const PayloadDTO& payload);
	//���
	JsonVO<uint64_t> execAddPayHandle(const AddPayApplyDTO& dto, const PayloadDTO& payload);
	//�޸�
	JsonVO<uint64_t> execModPayHandle(const ModPayApplyDTO& dto, const PayloadDTO& payload);

};
#endif 
