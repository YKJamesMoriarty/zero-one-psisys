#pragma once

#ifndef _PURREQ_CONTROLLER_
#define _PURREQ_CONTROLLER_

#include "../../domain/dto/req-eleanor/PurReqDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/user/UserDTO.h"
#include "../../domain/vo/user/UserVO.h"

/**
 * ʾ������������ʾ�ӿڵ�ʹ��
 */
class PurReqController
{
	//�������뵥���������뵥
public:
	//�ӿ�1 �������뵥
	CREATE_API_FUN_BODY_PAYLOAD(exportPurReqInfo, execPurReqExportInfo, PurReqExportDTO);

	//�ӿ�2 �������뵥
	CREATE_API_FUN_BODY_FILE(inportPurReqInfo, execPurReqIntoInfo, PurReqIntoDTO);
	
	
private:
	//ִ�з���������
	nlohmann::json execPurReqExportInfo(const PurReqExportDTO &dto, const PayloadDTO &payload);

	//ִ�з���������
	nlohmann::json execPurReqIntoInfo(const PurReqIntoDTO& dto);
	
};

#endif // _PURREQ__CONTROLLER_