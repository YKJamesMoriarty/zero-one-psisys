#pragma once

#ifndef _QueryQtrkBillDetails_QUERY_
#define _QueryQtrkBillDetails_QUERY_

#include "../PageQuery.h"

/**
 * ��ѯ�����б���ϸ��Ϣ��ҳ��ѯ����
 */
class QueryQtrkBillDetailsQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, id, Id);
public:
	// ��from_json
	friend void from_json(const json& j, QueryQtrkBillDetailsQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_QueryQtrkBillDetails_QUERY_