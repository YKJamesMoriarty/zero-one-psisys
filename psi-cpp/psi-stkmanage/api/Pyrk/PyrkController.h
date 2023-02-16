#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_

#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/Pyrk/ModifyPyrkBillStateDTO.h"

/**
* ��ӯ��������
*/
class PyrkController
{
public:
	CREATE_API_FUN_BODY(removePyrkBillById, execRemovePyrkBillById, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillState, execModifyPyrkBillState, ModifyPyrkBillStateDTO);
private:
	//ɾ������
	JsonVO<uint64_t> execRemovePyrkBillById(const StringID& id);
	//�޸ĵ���״̬
	JsonVO<uint64_t> execModifyPyrkBillState(const ModifyPyrkBillStateDTO& dto, const PayloadDTO& payload);
};



#endif // !_PYRK_CONTROLLER_