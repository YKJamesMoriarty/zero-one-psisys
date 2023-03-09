﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _PUR_INQUIRY_FIND_BILL_QUERY_H_
#define _PUR_INQUIRY_FIND_BILL_QUERY_H_

#include "../PageQuery.h"

/**
 * 示例分页查询对象 —— 采购询价单列表
 */

//采购询价单查询列表
class PurInquiryFindBillQuery : public PageQuery
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
//单据状态
	//是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);

public:
	// 绑定from_json
	friend void from_json(const json& j, PurInquiryFindBillQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_closed);
		BIND_FROM_TO_I(j, t, is_voided);
	}
};

#endif // !_PUR_INQUIRY_FIND_BILL_QUERY_