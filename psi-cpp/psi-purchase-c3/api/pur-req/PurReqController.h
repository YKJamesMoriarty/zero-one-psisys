#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

#include"api/ApiHelper.h"
#include "../../domain/query/pur-req/PurReqExportQuery.h"
#include "../../domain/dto/pur-req/PurReqIntoDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/pur-req/PurReqIntoVO.h"


/**
 * �ṩ�ӿڣ��������뵥���������뵥
 */


class PurReqController
{
public:
	//�ӿ�1 �������뵥
	CREATE_API_FUN_BODY_PAYLOAD(queryPurReqExport, execPurReqExport, PurReqExportQuery);

	//�ӿ�2 �������뵥
	CREATE_API_FUN_BODY_FILE(modifyPurReqInto, execPurReqInto, PurReqIntoDTO);
	
	
private:
	//ִ�з���������
	JsonVO<std::string> execPurReqExport(const PurReqExportQuery&query, const PayloadDTO &payload);

	//ִ�з���������
	JsonVO<PurReqIntoVO> execPurReqInto(const PurReqIntoDTO& dto);
};

#endif // _PUR_REQ__CONTROLLER_