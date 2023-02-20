#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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

#ifndef _Measurement_DO_
#define _Measurement_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class MeasurementDO
{
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 符号
	CC_SYNTHESIZE(string, sign, Sign);
	// 换算系数
	CC_SYNTHESIZE(uint64_t, scale, Scale);
	// 启用
	CC_SYNTHESIZE(string, enable, Enable);
	// 创建时间
	CC_SYNTHESIZE(string, ctime, Ctime);
	// 创建人
	CC_SYNTHESIZE(string, creater, Creater);
	// 修改时间
	CC_SYNTHESIZE(string, rtime, Rtime);
	// 修改人
	CC_SYNTHESIZE(string, riviser, Riviser);
public:
	MeasurementDO() {
		name = "";
		sign = "";
		scale = 1;
		enable = "";
		ctime = "";
		creater = "";
		rtime = "";
		riviser = "";
	}
};

#endif // !_Measurement_DTO_
