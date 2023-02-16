#pragma once

#ifndef _PAYMENT_BILL_Query_
#define _PAYMENT_BILL_Query_

#include "../PageQuery.h"


//��ѯ�����б�
class PaymentBillQuery : public PageQuery {
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId)
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч			
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�			
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������			
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// ��JSONת������
	friend void from_json(const json& j, PaymentBillQuery& pbq) {
		BIND_FROM_TO_ULL(j, pbq, billNo);
		BIND_FROM_TO_ULL(j, pbq, billDate);
		BIND_FROM_TO_ULL(j, pbq, subject);
		BIND_FROM_TO_ULL(j, pbq, supplierId);
		BIND_FROM_TO_ULL(j, pbq, billStage);
		BIND_FROM_TO_I(j, pbq, isEffective);
		BIND_FROM_TO_I(j, pbq, isClosed);
		BIND_FROM_TO_I(j, pbq, isVoided);
	}
};


/*
��ѯָ��������ϸ��Ϣ
*/
class PaymentBillDetailQuery {
	//ָ���ĵ��ݺ�
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// ��JSONת������
	friend void from_json(const json& j, PaymentBillDetailQuery& pbdq) {
		BIND_FROM_TO_ULL(j, pbdq, billNo);
	}
};


#endif
