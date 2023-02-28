#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/16 0:23:02

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

#ifndef _PUR_ORDER_CONTROLLER_
#define _PUR_ORDER_CONTROLLER_

#include "../../domain/query/PurOrder/PurOrderQuery.h"
#include "../../domain/dto/PurOrder/PurOrderDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PurOrder/PurOrderVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * 采购订单控制器，采购订单接口的使用
 */
class PurOrderController
{
public:
	// 删除采购订单
	// 负责人：Andrew
	CREATE_API_FUN_BODY(removeById, execRemoveById, StringID);
	// 修改单据状态(关闭/反关闭/作废)
	// 负责人：Andrew
	CREATE_API_FUN_BODY_PAYLOAD(statusPurOrder, execStatusPurOrder, PurOrderDTO);

private:
	// 删除采购订单
	// 负责人：Andrew
	JsonVO<string> execRemoveById(const StringID& id);
	// 修改单据状态(关闭/反关闭/作废)
	// 负责人：Andrew
	JsonVO<string> execStatusPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload);

};

#endif // _PUR_ORDER_CONTROLLER_