#pragma once
/*
* @author:akun
* @time: 2023-2-26 22:06 
*/
#ifndef _PUR_ORDER_DIVIDED_LIST_QUERY_H_
#define _PUR_ORDER_DIVIDED_LIST_QUERY_H_
#include "../../GlobalInclude.h"
/**
 * �ɹ�����--�ɹ�����ķ�¼�б�
 */
class PurOrderDividedListQuery {
	CC_SYNTHESIZE(string, bill_no, BillNo);
public:
	// ��JSONת������
	friend void from_json(const json& j, PurOrderDividedListQuery& t) {
		// ���ݱ��
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};
#endif // !_PUR_ORDER_QUERY_




