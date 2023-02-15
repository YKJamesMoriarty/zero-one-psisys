#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:55:04

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
#ifndef _PUR_COM_LIST_QUERY_
#define _PUR_COM_LIST_QUERY_

#include "../PageQuery.h"

/**
 *  ���۵��б��ѯ����
 */
class PurComListQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// ��from_json
	friend void from_json(const json& j, PurComListQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif 