#pragma once

#ifndef _PURREQ_CONTROLLER_
#define _PURREQ_CONTROLLER_

#include "../../domain/dto/req-eleanor/PurReqExportDTO.h"
#include "../../domain/dto/req-eleanor/PurReqIntoDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/req-eleanor/PurReqIntoVO.h"

/**
 * �ṩ�ӿڣ��������뵥���������뵥
 */


class PurReqController
{
public:
	//�ӿ�1 �������뵥
	CREATE_API_FUN_BODY_PAYLOAD(exportPurReqInfo, execPurReqExportInfo, PurReqExportDTO);

	//�ӿ�2 �������뵥
	CREATE_API_FUN_BODY_FILE(inportPurReqInfo, execPurReqIntoInfo, PurReqIntoDTO);
	
	
private:
	//ִ�з���������
	nlohmann::json execPurReqExportInfo(const PurReqExportDTO &dto, const PayloadDTO &payload);

	//ִ�з���������
	JsonVO<PurReqIntoVO> execPurReqIntoInfo(const PurReqIntoDTO& dto);
};

#endif // _PURREQ__CONTROLLER_