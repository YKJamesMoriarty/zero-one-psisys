#pragma once

#ifndef _DeleteQtrkBill_DTO_
#define _DeleteQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * ɾ�����ݴ������
 */
class DeleteQtrkBillDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, id, Id);

public:
	// ��JSONת������
	friend void from_json(const json& j, DeleteQtrkBillDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, id);
	}// NOLINT
};

#endif // !_DeleteQtrkBill_DTO_