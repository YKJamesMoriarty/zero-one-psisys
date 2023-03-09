#pragma once
#ifndef _QUERYZDRKBILLDETAILS_QUERY_
#define _QUERYZDRKBILLDETAILS_QUERY_

#include "../PageQuery.h"

/**
 * ��ѯ������ϸ��Ϣ
 */
class QueryZdrkBillDetailsQuery
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// ��from_json
	friend void from_json(const json& j, QueryZdrkBillDetailsQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_QUERYDOC_QUERY_