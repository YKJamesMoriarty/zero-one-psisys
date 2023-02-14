/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:46:24

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
#include "MeasurementDTO.h"
void from_json(const json& j, MeasurementDTO& t) { // NOLINT
	BIND_FROM_TO_NORMAL(j, t, 名称);
	BIND_FROM_TO_NORMAL(j, t, 符号);
	BIND_FROM_TO_I(j, t, 换算系数);
	BIND_FROM_TO_NORMAL(j, t, 启用);
	BIND_FROM_TO_NORMAL(j, t, 创建时间);
	BIND_FROM_TO_NORMAL(j, t, 创建人);
	BIND_FROM_TO_NORMAL(j, t, 修改时间);
	BIND_FROM_TO_NORMAL(j, t, 修改人);
}