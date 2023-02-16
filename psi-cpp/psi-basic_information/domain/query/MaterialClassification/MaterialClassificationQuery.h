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
* 基础资料分类模块查询对象
*/
class MaterialClassificationQuery : public PageQuery {

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编码
	CC_SYNTHESIZE(uint64_t, code, Code);

public:
	// 绑定from_json
	friend void from_json(const json& j, MaterialClassificationQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, code);
	}
};

//查询子级列表对象
class MaterialClassificationChildQuery  {

	//名称
	CC_SYNTHESIZE(string, name, Name);

	//编码
	CC_SYNTHESIZE(uint64_t, code, Code);

public:
	// 绑定from_json
	friend void from_json(const json& j, MaterialClassificationChildQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, code);
	}
};


//查询详细信息对象
class MaterialClassificationDetailQuery {

	//创建时间
	CC_SYNTHESIZE(string, create_time, createTime);

	//创建人
	CC_SYNTHESIZE(string, create_by, createBy);

	//修改时间
	CC_SYNTHESIZE(string, update_time, updateTime);

	//修改人
	CC_SYNTHESIZE(string, update_by, updateBy);

public:
	// 绑定from_json
	friend void from_json(const json& j, MaterialClassificationDetailQuery& t) { // NOLINT

		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, create_by);
		BIND_FROM_TO_NORMAL(j, t, update_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);

	}
};

#endif

