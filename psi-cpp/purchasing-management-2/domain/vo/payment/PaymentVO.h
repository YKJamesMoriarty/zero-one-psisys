#pragma once


#ifndef _PAYMENTVO_H_
#define _PAYMENTVO_H_

class PaymentVO
{
	// 
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ���֤��
	CC_SYNTHESIZE(std::string, idCard, IdCard);
public:
	// ��JSONת������
	BIND_TO_JSON(PaymentVO, id, age, idCard);
};




#endif // _PAYMENTVO_H_