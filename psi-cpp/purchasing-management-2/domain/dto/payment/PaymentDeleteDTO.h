#pragma once

#ifndef _PAYMENTDELETEDTO_H_
#define _PAYMENTDELETEDTO_H_

#include "../../GlobalInclude.h"

/**
 * ɾ���ɹ��������뵥
 */
class PaymentDeleteDTO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// ��JSONת������
	friend void from_json(const json& j, PaymentDeleteDTO& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, id);
	}
};









#endif // _PAYMENTDELETEDTO_H_