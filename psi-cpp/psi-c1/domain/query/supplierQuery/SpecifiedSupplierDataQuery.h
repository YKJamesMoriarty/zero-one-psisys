#pragma once

#ifndef _SPECIFIED_QUERY_
#define _SPECIFIED_QUERY_

#include "../PageQuery.h"

class SpecifiedSupplierDataQuery 
{
	// ���
	CC_SYNTHESIZE(string, id, ID);
	
public:
	// ��from_json
	friend void from_json(const json& j, SpecifiedSupplierDataQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};

#endif // !_SPECIFIED_QUERY_
