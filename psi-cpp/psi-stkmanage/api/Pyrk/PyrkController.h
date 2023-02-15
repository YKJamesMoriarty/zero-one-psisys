#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_

#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"

/**
* ��ӯ��������
*/
class PyrkController
{
public:
	CREATE_API_FUN_BODY(removeById, execRemoveById, StringID);
private:
	//ɾ������
	JsonVO<uint64_t> execRemoveById(const StringID& id);
};



#endif // !_PYRK_CONTROLLER_