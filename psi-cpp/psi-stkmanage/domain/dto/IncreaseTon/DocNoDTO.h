#pragma once
#ifndef _DOCNO_DTO_
#define _DOCNO_DTO_

#include "../../GlobalInclude.h"

/**
 * ���ݱ�Ŵ������
 */
class DocNoDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// ��JSONת������
	friend void from_json(const json& j, DocNoDTO& t); // NOLINT
	BIND_TO_JSON(DocNoDTO, billNo);
};

#endif // !_QueryDoc_DTO_