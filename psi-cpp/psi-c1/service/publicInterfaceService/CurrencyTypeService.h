#pragma once

#ifndef _CURRENCY_TYPE_SERVICE_
#define _CURRENCY_TYPE_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/CurrencyTypeVO.h"


class CurrencyTypeService
{
public:
	//��ѯ���������б�
	list<CurrencyTypeVO> listAll();
};
#endif // !_CURRENCY_TYPE_SERVICE_
