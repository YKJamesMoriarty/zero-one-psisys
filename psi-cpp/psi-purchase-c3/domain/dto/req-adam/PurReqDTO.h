#pragma once
#ifndef _PUR_REQ_DTO_
#define _PUR_REQ_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class PurReqDTO
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
	friend void from_json(const json& j, PurReqDTO& t); // NOLINT
	BIND_TO_JSON(PurReqDTO, id, name, age, sex);
};

#endif // !_PUR_REQ_DTO_