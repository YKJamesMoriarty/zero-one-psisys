#pragma once
#ifndef _REMOVE_CGRK_BILL_DTO_
#define _REMOVE_CGRK_BILL_DTO_

#include "../../GlobalInclude.h"


/**
 * ɾ���ɹ���ⵥ
 */
class RemoveCgrkBillDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// ��JSONת������
	friend void from_json(const json& j, RemoveCgrkBillDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}

};

#endif // !_REMOVE_CGRK_BILL_DTO_
