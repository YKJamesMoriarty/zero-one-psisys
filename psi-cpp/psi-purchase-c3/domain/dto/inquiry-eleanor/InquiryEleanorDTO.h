#pragma once

#ifndef _INQUIRYELEANOR_DTO_
#define _INQUIRYELEANOR_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class InquiryEleanorDTO
{
//����������


public:
	// ��JSONת������
	friend void from_json(const json& j, InquiryEleanorDTO& t); // NOLINT
	//BIND_TO_JSON();
};

class AssignInquiryEleanorDTO
{
//����������


public:
	// ��JSONת������
	friend void from_json(const json& j, InquiryEleanorDTO& t); // NOLINT
	//BIND_TO_JSON();
};


#endif // !_INQUIRYELEANOR_DTO_