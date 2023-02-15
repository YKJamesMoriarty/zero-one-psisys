#pragma once
#ifndef _CURRENCY_TYPE_CONTROLLER_
#define _CURRENCY_TYPE_CONTROLLER_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/CurrencyTypeVO.h"


class CurrencyTypeController
{
public:
	CREATE_API_FUN_QUERY3(queryCurrencyType, execQueryCurrencyType);
private:
	//ִ�в�ѯ��������
	JsonVO<list<CurrencyTypeVO>> execQueryCurrencyType();
};
#endif // !_CURRENCY_TYPE_CONTROLLER_
