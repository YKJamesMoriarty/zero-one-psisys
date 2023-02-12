#pragma once


#ifndef _REQELEANOR_CONTROLLER_
#define _REQELEANOR_CONTROLLER_

#include "../../domain/dto/req-eleanor/ReqEleanorDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/req-eleanor/ReqEleanorVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/user/UserDTO.h"
#include "../../domain/vo/user/UserVO.h"


/**
 * ʾ������������ʾ�ӿڵ�ʹ��
 */
class ReqEleanorController
{
	//�������뵥���������뵥
public:
	//�ӿ�1 �������뵥

	//�ӿ�2 �������뵥
	CREATE_API_FUN_BODY_FILE(modifyReqEleanorInfo, execModifyReqEleanorInfo, ReqEleanorDTO);

	
private:


	//��ʾ�ļ��ϴ�
	JsonVO<ReqEleanorVO> execModifyReqEleanorInfo(const ReqEleanorDTO& dto);
};



#endif // _REQYELEANOR__CONTROLLER_