#pragma once

#ifndef _QUERYQTRKBILLDETAILS_QUERY_
#define _QUERYQTRKBILLDETAILS_QUERY_

#include "../PageQuery.h"

/**
 * ��ѯ�����б���ϸ��Ϣ��ҳ��ѯ����
 */
class QueryQtrkBillDetailsQuery 
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// ��from_json
	friend void from_json(const json& j, QueryQtrkBillDetailsQuery& t) { // NOLINT

		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_QUERYQTRKBILLDETAILS_QUERY_