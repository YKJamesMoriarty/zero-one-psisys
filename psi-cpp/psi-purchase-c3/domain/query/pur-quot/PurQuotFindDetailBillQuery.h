#include "stdafx.h"
#ifndef __PurQuotFindDetailBill_QUERY_H__
#define __PurQuotFindDetailBill_QUERY_H__

#include "../PageQuery.h"

class PurQuotFindDetailBillQuery : public PageQuery
{

	// ���ݱ��
	CC_SYNTHESIZE(string, receiptId, ReceiptId);
public:
	friend void from_json(const json& j, PurQuotFindDetailBillQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, receiptId);
	}
};
#endif