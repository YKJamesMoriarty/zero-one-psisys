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
	CC_SYNTHESIZE(string, id, Id);
	// ������
	CC_SYNTHESIZE(string, name, Name);
public:
	CurrencyTypeDO() {
		id = "";
		name = "";
	}
};

#endif // !_CURRENCYTYPE_DO_