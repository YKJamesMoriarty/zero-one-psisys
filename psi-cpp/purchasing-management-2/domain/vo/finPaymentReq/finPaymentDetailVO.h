#pragma once

#ifndef _FIN_PAYMENT_DETAIL_VO_
#define _FIN_PAYMENT_DETAIL_VO_

#include "../../GlobalInclude.h"
#include "finPaymentReqVO.h"
#include "finPaymentReqEntryVO.h"

/*
��ѯ�����б���ʾ����
*/
//��ע:��ĺ�������ֶ�������Ҫ����
class FinPaymentDetailVO : public FinPaymentReqVO {
	//��ϸ�б�
	CC_SYNTHESIZE(list<FinPaymentReqEntryVO>, detailBillsVO, DetailBillsVO);

public:
	// ��JSONת������
	BIND_TO_JSON(FinPaymentDetailVO, billNo, billDate, isEffective, isClosed,
		isVoided, subject, detailBillsVO);
};
#endif // _FIN_PAYMENT_DETAIL_VO_
