#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_QUERY_
#define _PREPAYMENT_DETAIL_BILL_QUERY_
#include "../PageQuery.h"
/*
��ѯָ��������ϸ��Ϣ
*/
class PrepaymentDetailBillQuery {
	//ָ���ĵ��ݺ�
	CC_SYNTHESIZE(string, id, ID);
public:
	// ��JSONת������
	friend void from_json(const json& j, PrepaymentDetailBillQuery& t) {
	}
};
#endif // !
