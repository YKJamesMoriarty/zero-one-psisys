#pragma once

#ifndef DELIVERYMETHODCONTROLLER_H_
#define DELIVERYMETHODCONTROLLER_H_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/publicInterfaceVO/DeliveryMethodVO.h"
#include "api/ApiHelper.h"

class DeliveryMethodController
{
public:
	CREATE_API_FUN_QUERY3(queryDeliveryMethod, executeQueryDeliveryMethod);
private:
	JsonVO<std::list<DeliveryMethodType>> executeQueryDeliveryMethod();
};


#endif // !DELIVERYMETHODTYPE_H_

