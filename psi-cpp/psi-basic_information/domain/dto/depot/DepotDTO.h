#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Linsky
 @Date: 2023/2/13 20:31:04

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
#ifndef _DEPOT_DTO_
#define _DEPOT_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * 基础资料仓库模块传输对象
 */
class DepotDTO : public FileDTO
{
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 助记名
	CC_SYNTHESIZE(string, help_name, Help_name);
	// 电话
	CC_SYNTHESIZE(int, phone, Phone);
	// 启用
	// 备注
	// 创建时间
	// 创建人
	// 修改时间
	// 修改人
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DepotDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, help_name);
		BIND_FROM_TO_I(j, t, phone);
	}

	BIND_TO_JSON(DepotDTO, name, id, help_name, phone);
};

#endif // !_DEPOT_DTO_
