#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: 111
 @Date: 2023/02/19 11:08:56
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
#ifndef _BASMATERIAL_SERVICE_
#define _BASMATERIAL_SERVICE_
#include <list>
#include "../../domain/vo/BasMaterial/BasMaterialVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/BasMaterial/BasMaterialQuery.h"
#include "../../domain/dto/BasMaterial/BasMaterialDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class BasMaterialService
{
public:
	// 分页查询所有数据
	PageVO<BasMaterialVO> listAll(const BasMaterialQuery& query);
	//id查询
	BasMaterialVO getData(const BasMaterialQuery& query);

	// 保存数据
	uint64_t saveData(const BasMaterialDTO& dto);
	// 修改数据
	bool updateData(const BasMaterialDTO& dto);
	// 通过code编码删除数据
	bool removeData(uint64_t id);
};

#endif // !_BASMATERIAL_SERVICE_