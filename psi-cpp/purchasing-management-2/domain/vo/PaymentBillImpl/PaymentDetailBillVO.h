#pragma once

#ifndef _PAYMENT_DETAIL_BILL_VO_
#define _PAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
#include "PaymentBillVO.h"
#include "PaymentBillDetailVO.h"

/*
��ѯ�����б���ʾ����
*/
//��ע:��ĺ�������ֶ�������Ҫ����
class PaymentDetailBillVO : public PaymentBillVO {
	//��ϸ�б�
	CC_SYNTHESIZE(list<PaymentBillDetailVO>, detailBillsVO, DetailBillsVO);

public:
	// ��JSONת������
	BIND_TO_JSON(PaymentDetailBillVO, billNo, billDate, isEffective, isClosed,
		isVoided, subject, detailBillsVO);
};
#endif // _PAYMENT_DETAIL_BILL_VO_
