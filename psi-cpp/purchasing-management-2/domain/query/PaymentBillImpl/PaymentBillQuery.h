#pragma once

#ifndef _PAYMENT_BILL_Query_
#define _PAYMENT_BILL_Query_

#include "../PageQuery.h"


//��ѯ�����б�
class PaymentBillQuery : public PageQuery {
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id)
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч			
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�			
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������			
	CC_SYNTHESIZE(int, is_voided, Is_voided);
public:
	// ��JSONת������
	friend void from_json(const json& j, PaymentBillQuery& pbq) {
		BIND_FROM_TO_ULL(j, pbq, bill_no);
		BIND_FROM_TO_ULL(j, pbq, bill_date);
		BIND_FROM_TO_ULL(j, pbq, subject);
		BIND_FROM_TO_ULL(j, pbq, supplier_id);
		BIND_FROM_TO_ULL(j, pbq, bill_stage);
		BIND_FROM_TO_I(j, pbq, is_effective);
		BIND_FROM_TO_I(j, pbq, is_closed);
		BIND_FROM_TO_I(j, pbq, is_voided);
	}
};


/*
��ѯָ��������ϸ��Ϣ
*/
class PaymentBillDetailQuery {
	//ָ���ĵ��ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// ��JSONת������
	friend void from_json(const json& j, PaymentBillDetailQuery& pbdq) {
		BIND_FROM_TO_ULL(j, pbdq, bill_no);
	}
};


#endif
