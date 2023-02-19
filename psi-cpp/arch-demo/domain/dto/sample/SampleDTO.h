#pragma once

#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class SampleDTO
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
	friend void from_json(const json& j, SampleDTO& t); // NOLINT
	BIND_TO_JSON(SampleDTO, id, name, age, sex);
};

#endif // !_SAMPLE_DTO_