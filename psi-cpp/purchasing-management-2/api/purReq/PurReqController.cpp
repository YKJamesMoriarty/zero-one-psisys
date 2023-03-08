/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
@Date: 2023/02/16 0:23:02

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
#include "stdafx.h"
#include "PurReqController.h"
#include "../../service/purReq/PurReqService.h"

// ��ѯlist��ҳ����
JsonVO<PageVO<PurReqVO>> PurReqController::execListPurReq(const PurReqQuery& query, const PayloadDTO& payload) {
	// ����һ��Service
	PurReqService service;
	// ��ѯ����
	PageVO<PurReqVO> result = service.listAll(query);
	// ��Ӧ���
	return JsonVO<PageVO<PurReqVO>>(result, RS_SUCCESS);
}

// ��ѯ��������
JsonVO<PurReqVO> PurReqController::execGetPurReq(const PurReqQuery& query)
{
	PurReqService service;
	JsonVO<PurReqVO> result = JsonVO(service.getData(query.getId()), RS_SUCCESS);
	return result;
}

// ��ѯlist����
JsonVO<list<PurReqVO>> PurReqController::execListPurReqList(const PurReqQuery& query, const PayloadDTO& payload)
{
	// ����һ��Service
	PurReqService service;
	// ��ѯ����
	list<PurReqVO> result = service.listAllData(query);
	// ��Ӧ���
	return JsonVO<list<PurReqVO>>(result, RS_SUCCESS);
}