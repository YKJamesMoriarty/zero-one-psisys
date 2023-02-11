#ifndef _PURTYPE_CONTROLLER_
#define _PURTYPE_CONTROLLER_

#include "domain/vo/JsonVO.h"
#include "domain/vo/PurTypeVO.h"
#include "api/ApiHelper.h"

/*
�ɹ���ʽ
Author C1-��ľ
2023.2.11 20��54��
*/
class PurTypeController
{
public:
	CREATE_API_FUN_QUERY3(queryPurType, executequeryPurType);
private:
	JsonVO<list<PurTypeVO>> executequeryPurType();
};

#endif //_PURTYPE_CONTROLLER_