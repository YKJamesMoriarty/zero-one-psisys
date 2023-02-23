#pragma once
#ifndef _PREPAY_DETAIL_BILL_QUERY_
#define _PREPAY_DETAIL_BILL_QUERY_
#include "../PageQuery.h"

/**
 * �ɹ�Ԥ������-��ѯָ��Ԥ�����뵥���б�-��ѯʱ������ݱ��
*/
class PrepayDetailBillQuery {
	//ָ���ĵ��ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	// ��JSONת������
	friend void from_json(const json& j, PrepayDetailBillQuery& t) {
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};
#endif // !_PREPAY_DETAIL_BILL_QUERY_
