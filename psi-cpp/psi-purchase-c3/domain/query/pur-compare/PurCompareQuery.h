#pragma once
#ifndef _PUR_COMPARE_QUERY_
#define _PUR_COMPARE_QUERY_

#include "../PageQuery.h"

/**
 * ʾ����ҳ��ѯ����
 */
class PurCompareQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ���ݿ�ʼ����
	CC_SYNTHESIZE(string, billBeginDate, BillBeginDate);
	// ���ݽ�������
	CC_SYNTHESIZE(string, billEndDate, BillEndDate);
	// ������ʼ����
	CC_SYNTHESIZE(string, deliveryBeginDate, DeliveryBeginDate);
	// ������������
	CC_SYNTHESIZE(string, deliveryEndDate, DeliveryEndDate);
	
public:
	// ��from_json
	friend void from_json(const json& j, PurCompareQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_NORMAL(j, t, billBeginDate);
		BIND_FROM_TO_NORMAL(j, t, billEndDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryBeginDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryEndDate);
	}
};

#endif // !_PUR_COMPARE_QUERY_