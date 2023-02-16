#pragma once

#ifndef _PAYMENT_BILL_DETAIL_QUERY_
#define _PAYMENT_BILL_DETAIL_QUERY_

#include "../PageQuery.h"

/*
��ѯ�����б�
*/
class PaymentBillDetailQuery {
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	// �Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(PaymentBillDetailQuery, srcNo, amt, paidAmt, remark, custom1, custom2);
};

#endif