#pragma once

#ifndef _CURRENCYTYPEVO_H_
#define _CURRENCYTYPEVO_H_
#include "../../GlobalInclude.h"

/*
* ����ѡ��
* @Author: Oxygen
* @Date: 2023/2/12 15:05:25
*/
class CurrencyTypeVO
{
	// ���ͱ��
	CC_SYNTHESIZE(int, id, Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(CurrencyTypeVO, id, name);
};

#endif // _CURRENCYTYPEVO_H_