#pragma once
#ifndef _QUERYDOC_DTO_
#define _QUERYDOC_DTO_

#include "../../GlobalInclude.h"

/**
 * ��ѯ���ض������
 */
class QueryDocDTO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
public:
	// ��JSONת������
	friend void from_json(const json& j, QueryDocDTO& t) {
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_I(j, t,age);
		BIND_FROM_TO_NORMAL(j, t, sex);
	}
	BIND_TO_JSON(QueryDocDTO, id, name, age, sex);
};

#endif // !_QueryDoc_DTO_
