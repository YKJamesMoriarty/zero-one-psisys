#pragma once
#ifndef _PUR_QUOT_EXPORT_QUERY_
#define _PUR_QUOT_EXPORT_QUERY_

#include "../PageQuery.h"

class PurQuotExportQuery : public PageQuery {
	//ָ���ĵ��ݺ�
	CC_SYNTHESIZE(string, id, ID);
public:
	// ��JSONת������
	friend void from_json(const json& j, PurQuotExportQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_ULL(j, t, id);
	}
};

#endif // !




