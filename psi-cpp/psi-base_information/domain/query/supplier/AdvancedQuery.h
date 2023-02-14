#pragma once

#ifndef _ADVANCED_QUERY_
#define _ADVANCED_QUERY_
#include "../../GlobalInclude.h"

class AdvancedQuery
{
	// ����ƥ������
	CC_SYNTHESIZE(string, rule, Rule);
	//��ѯ�ֶ�
	CC_SYNTHESIZE(string, name, Name);
	//	�ֶβ�ѯ���������ڡ������������ڡ�����....
	CC_SYNTHESIZE(string, condition, Condition);
	//�û��������Ҫ��ѯ���ֶε�ֵ
	CC_SYNTHESIZE(string, value, Value);
public:
	// ��from_json
	friend void from_json(const json& j, AdvancedQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, rule);
		BIND_FROM_TO_ULL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, condition);
		BIND_FROM_TO_NORMAL(j, t, value);
	}
};

#endif // !_ADVANCED_QUERY_

