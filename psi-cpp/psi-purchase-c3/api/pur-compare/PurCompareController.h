﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:57:54

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
#ifndef _PUR_COMPARE_CONTROLLER_
#define _PUR_COMPARE_CONTROLLER_
//公共接口
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

//query
#include "../../domain/query/pur-compare/PurComFindBillQuery.h"
#include "../../domain/query/pur-compare/PurComFindDetailBillQuery.h"
#include "../../domain/query/pur-compare/PurComDividedListQuery.h"
#include "../../domain/query/pur-compare/PurComListQuery.h"
#include "../../domain/query/pur-compare/PurComExportQuery.h"
//dto
#include "../../domain/dto/pur-compare/PurComIntoDTO.h"
#include "../../domain/dto/pur-compare/AddPurComDTO.h"
#include "../../domain/dto/pur-compare/ModPurComDTO.h"
#include "../../domain/dto/pur-compare/PurComModBillStatusDTO.h"
#include "../../domain/dto/pur-compare/DelPurComDTO.h"

//vo
#include "../../domain/vo/pur-compare/PurComFindBillVO.h"
#include "../../domain/vo/pur-compare/PurComFindDetailBillVO.h"
#include "../../domain/vo/pur-compare/PurComListVO.h"
#include "../../domain/vo/pur-compare/PurComDividedListVO.h"
/**
 * 比价单控制器
 */
class PurCompareController
{
public:
	// 新增比价
	CREATE_API_FUN_JSON_PAYLOAD(addPurCom, execAddPurCom, AddPurComDTO);

	// 修改比价
	CREATE_API_FUN_JSON_PAYLOAD(modifyPurCom, execModifyPurCom, ModPurComDTO);
	// 删除比价
	CREATE_API_FUN_BODY(removePurCom, execRemovePurCom, DelPurComDTO);
	// 修改单据状态
	CREATE_API_FUN_BODY_PAYLOAD(purComModBillStatus, execPurComModBillStatus, PurComModBillStatusDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindBill, execQueryPurComFindBill, PurComFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindDetailBill, execQueryPurComFindDetailBill, PurComFindDetailBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComList, execQueryPurComList, PurComListQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComDividedList, execQueryPurComDividedList, PurComDividedListQuery);
	CREATE_API_FUN_JSON_PAYLOAD(queryPurComExport, execPurComExport, PurComExportQuery)
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurComInto, execPurComInto, PurComIntoDTO);
private:
	//演示新增比价
	JsonVO<uint64_t> execAddPurCom(const AddPurComDTO& dto, PayloadDTO payload);
	//演示修改比价
	JsonVO<uint64_t> execModifyPurCom(const ModPurComDTO& dto, PayloadDTO payload);
	//演示删除比价
	JsonVO<uint64_t> execRemovePurCom(const DelPurComDTO& dto);
	//演示修改单据状态
	JsonVO<uint64_t> execPurComModBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload);
	// 查询比价单单据列表
	JsonVO<PageVO<PurComFindBillVO>> execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload);
	// 查询指定比价单单据详细信息
	JsonVO<PurComFindDetailBillVO> execQueryPurComFindDetailBill(const PurComFindDetailBillQuery& query, const PayloadDTO& payload);
	// 查询报价单列表
	JsonVO<list<PurComListVO>> execQueryPurComList(const PurComListQuery& query, const PayloadDTO& payload);
	// 查询报价单分录列表
	JsonVO<list<PurComDividedListVO>> execQueryPurComDividedList(const PurComDividedListQuery& query, const PayloadDTO& payload);
	// 导出
	JsonVO<std::string> execPurComExport(const PurComExportQuery& query, const PayloadDTO& payload);
	// 导入
	JsonVO<uint64_t> execPurComInto(const PurComIntoDTO& dto, const PayloadDTO& payload);
};

#endif // _SAMPLE_CONTROLLER_#pragma once
