#pragma once
#ifndef _PRE_PAY_DETAIL_BILL_QUERY_
#define _PRE_PAY_DETAIL_BILL_QUERY_
#include "../PageQuery.h"
/*
��ѯָ��������ϸ��Ϣ
*/
class PrepayDetailBillQuery {
	//ָ���ĵ��ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// ��JSONת������
	friend void from_json(const json& j, PrepayDetailBillQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};
#endif // !
