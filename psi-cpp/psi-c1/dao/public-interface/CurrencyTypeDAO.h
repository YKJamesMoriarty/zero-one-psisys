#pragma once
#ifndef _CURRENCYTYPE_DAO_
#define _CURRENCYTYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/public-interface/CurrencyTypeDO.h"

class CurrencyTypeDAO : public BaseDAO
{
public:
	// ��ѯ��������
	list<CurrencyTypeDO> selectCurrencyType();
};
#endif // !_CURRENCYTYPE_DAO_