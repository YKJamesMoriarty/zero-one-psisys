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
#include "stdafx.h"
#include "PurReqController.h"
#include "service/pur-req/PurReqService.h"
#include "domain/query/pur-req/PurReqExportQuery.h"


//����
JsonVO<PurReqExportVO> PurReqController::execPurReqExport(const PurReqExportQuery& query, const PayloadDTO& payload)
{
	//��Ӧ���
	return JsonVO<PurReqExportVO>();
}

//����
JsonVO<uint64_t> PurReqController::execPurReqInto(const PurReqIntoDTO& dto)
{
	//��Ӧ���
	return JsonVO<uint64_t>();
}
