#pragma once
#ifndef _CURRENCYTYPE_DO_
#define _CURRENCYTYPE_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class CurrencyTypeDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ������
	CC_SYNTHESIZE(string, name, Name);
public:
	CurrencyTypeDO() {
		id = 0;
		name = "";
	}
};

#endif // !_CURRENCYTYPE_DO_