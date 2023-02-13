#pragma once
#ifndef _PUR_REQ_QUERY_
#define _PUR_REQ_QUERY_

#include "../PageQuery.h"

/**
 * ʾ����ҳ��ѯ����
 */
class PurReqQuery : public PageQuery
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
public:
	// ��from_json
	friend void from_json(const json& j, PurReqQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_PUR_REQ_QUERY_