#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PUR_REQ_SERVICE_
#define _PUR_REQ_SERVICE_
#include <list>
#include "../../domain/vo/purReq/PurReqVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/purReq/PurReqQuery.h"
#include "../../dao/purOrder/PurOrderEntryDAO.h"

/**
 * �ɹ��������ʵ�֣������ɹ���������ʵ��
 */
class PurReqService
{
public:
	// ��ѯ��������
	list<PurReqVO> listAllData(const PurReqQuery& query);
	// ��ҳ��ѯ��������
	PageVO<PurReqVO> listAll(const PurReqQuery& query);
	// ��ѯ��������
	PurReqVO getData(uint64_t id);
};

#endif // ! _PUR_REQ_SERVICE_