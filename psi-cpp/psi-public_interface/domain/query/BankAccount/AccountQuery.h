#pragma once

#ifndef _ACCOUNTQUERY_H_
#define _ACCOUNTQUERY_H_
#include "../PageQuery.h"

/*
* �˻��б��ѯ
* @Author: Oxygen
* @Date: 2023/2/12 14:13:32
*/
class AccountQuery : PageQuery
{
	// ���
	CC_SYNTHESIZE(string, _t, _t);
	// ����
	CC_SYNTHESIZE(string, column, Column);
	// �������
	CC_SYNTHESIZE(string, order, Order);
	// ��ѯ��Χ
	CC_SYNTHESIZE(string, field, Field);
	// ��ǰҳ��
	CC_SYNTHESIZE(int, pageNo, PageNo);
	// ҳ�Ĵ�С
	CC_SYNTHESIZE(int, PageSizepageSizeNo);
public:
	// ��from_json
	friend void from_json(const json& j, AccountQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageNo);
		BIND_FROM_TO_ULL(j, t, pageSizepageSizeNo);
		BIND_FROM_TO_NORMAL(j, t, _t);
		BIND_FROM_TO_NORMAL(j, t, column);
		BIND_FROM_TO_NORMAL(j, t, order);
		BIND_FROM_TO_NORMAL(j, t, field);
	}
};

#endif // _ACCOUNTQUERY_H_