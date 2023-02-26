#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Papillon
 @Date: 2023/02/16 22:00:00
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
#ifndef _ADD_PAY_APPLY_DTO_
#define _ADD_PAY_APPLY_DTO_

#include "../../GlobalInclude.h"
#include "PurPayReqEntryDTO.h"

class AddPayApplyDTO :public FileDTO
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator, Operator);
	//付款类型
	CC_SYNTHESIZE(string, paymentType, PaymentType);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//版本
	CC_SYNTHESIZE(int, version, Version);
	//明细列表
	CC_SYNTHESIZE(list<PurPayReqEntryDTO>, detail, Detail);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, AddPayApplyDTO& apt) {
		BIND_FROM_TO_ULL(j, apt, billNo);
		BIND_FROM_TO_ULL(j, apt, billDate);
		BIND_FROM_TO_ULL(j, apt, srcBillType);
		BIND_FROM_TO_ULL(j, apt, srcBillId);
		BIND_FROM_TO_ULL(j, apt, srcNo);
		BIND_FROM_TO_ULL(j, apt, subject);
		BIND_FROM_TO_ULL(j, apt, supplierId);
		BIND_FROM_TO_ULL(j, apt, opDept);
		BIND_FROM_TO_ULL(j, apt, operator);
		BIND_FROM_TO_ULL(j, apt, paymentType);
		BIND_FROM_TO_ULL(j, apt, remark);
		BIND_FROM_TO_ULL(j, apt, billStage);
		BIND_FROM_TO_ULL(j, apt, effectiveTime);
		BIND_FROM_TO_ULL(j, apt, version);

		BIND_FROM_TO_D(j, apt, amt);

		BIND_FROM_TO_I(j, apt, isAuto);
		BIND_FROM_TO_I(j, apt, isEffective);
		BIND_FROM_TO_I(j, apt, isClosed);
		BIND_FROM_TO_I(j, apt, isVoided);

		BIND_FROM_TO_OBJ(j, apt, detail, list<PurPayReqEntryDTO>);
	}
};

#endif
