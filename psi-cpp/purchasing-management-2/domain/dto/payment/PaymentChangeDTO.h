#pragma once

#ifndef _PAYMENTCHANGEDTO_H_
#define _PAYMENTCHANGEDTO_H_

#include "../../GlobalInclude.h"

/**
 * �޸ĵ���״̬���ر�/����/���رգ�
 */
class PaymentChangeDTO
{
	
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ״̬(close/unclose/abolish)
	CC_SYNTHESIZE(string, status, Status);

public:
	// ��JSONת������
	friend void from_json(const json& j, PaymentChangeDTO& t); // NOLINT
	BIND_TO_JSON(PaymentChangeDTO, id, status);
};

#endif // !_PAYMENTCHANGEDTO_H_