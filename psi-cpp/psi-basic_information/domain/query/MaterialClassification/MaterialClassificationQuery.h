#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/13 15:40:04

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
#ifndef _MATERIALCLASSIFICATION_QUERY_
#define _MATERIALCLASSIFICATION_QUERY_
#include "../PageQuery.h"

/**
* �������Ϸ���ģ���ѯ����
*/
class MaterialClassificationQuery : public PageQuery {

	//����
	CC_SYNTHESIZE(string, name, Name);

	//����
	CC_SYNTHESIZE(string, code, Code);

public:
	// ��from_json
	friend void from_json(const json& j, MaterialClassificationQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, code);
	}
};



#endif

