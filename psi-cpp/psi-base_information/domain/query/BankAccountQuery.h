#ifndef _BANKACCOUNT_QUERY_
#define _BANKACCOUNT_QUERY_

#include "PageQuery.h"

/**
* c1-ruizi
* 2.14 1.28
 * �����˻��б��ѯ
 */
class BankAccountQuery : public PageQuery
{
	//��ͨ��ѯ��Ҫʲô������

public:
	// ��from_json
	friend void from_json(const json& j, BankAccountQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		//BIND_FROM_TO_NORMAL(j, t, name);
		//BIND_FROM_TO_NORMAL(j, t, sex);
	}
};

#endif // !_BANKACCOUNT_QUERY_