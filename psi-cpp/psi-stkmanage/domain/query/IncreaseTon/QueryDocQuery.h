#pragma once
#ifndef _QUERYDOC_QUERY_
#define _QUERYDOC_QUERY_

#include "../PageQuery.h"

/**
 * ��ѯ������ϸ��Ϣ
 */
class QueryDocQuery
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// ��from_json
	friend void from_json(const json& j, QueryDocQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_QUERYDOC_QUERY_