#pragma once

#ifndef _QueryQtrkBillList_QUERY_
#define _QueryQtrkBillList_QUERY_

#include "../PageQuery.h"

/**
 * ��ѯ�����б��ҳ��ѯ����
 */
class QueryQtrkBillListQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// ��from_json
	friend void from_json(const json& j, QueryQtrkBillListQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_ULL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_QueryQtrkBillList_QUERY_