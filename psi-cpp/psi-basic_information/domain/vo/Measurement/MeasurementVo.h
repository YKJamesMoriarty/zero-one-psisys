#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _Measuremnet_VO_
#define _Measurement_VO_

#include "../../GlobalInclude.h"

/**
 * 显示对象
 */
class MeasurementVO
{
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 符号
	CC_SYNTHESIZE(string, sign, Sign);
	// 换算系数
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 启用
	CC_SYNTHESIZE(string, start, Start);
	// 创建时间
	CC_SYNTHESIZE(string, ctime, Ctime);
	// 创建人
	CC_SYNTHESIZE(string, creater, Creater);
	// 修改时间
	CC_SYNTHESIZE(string, rtime, Rtime);
	// 修改人
	CC_SYNTHESIZE(string, reviser, Reviser);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(MeasurementDTO, 名称, 符号, 换算系数, 启用, 创建时间, 创建人, 修改时间, 修改人);
};

#endif // !_measurement_VO_
