#pragma once
#ifndef __PUR_QUOT_FIND_BILL_QUERY_H_
#define __PUR_QUOT_FIND_BILL_QUERY_H_
#include "../PageQuery.h"
class PurQuotFindBillQuery : public PageQuery{
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������--��ʼ
	CC_SYNTHESIZE(string, bill_date_begin, Bill_date_begin);
	//��������--����
	CC_SYNTHESIZE(string, bill_date_end, Bill_date_end);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(string, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(string, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(string, is_voided, Is_voided);
public:
	friend void from_json(const json& j, PurQuotFindBillQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date_begin);
		BIND_FROM_TO_NORMAL(j, t, bill_date_end);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_NORMAL(j, t, is_effective);
		BIND_FROM_TO_NORMAL(j, t, is_closed);
		BIND_FROM_TO_NORMAL(j, t, is_voided);
	}
	void GetCode() {

	}
};
#endif
