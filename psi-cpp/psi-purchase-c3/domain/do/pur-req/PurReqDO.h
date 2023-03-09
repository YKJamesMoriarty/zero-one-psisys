﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
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
#ifndef _PUR_REQ_DO_
#define _PUR_REQ_DO_
#include "../DoInclude.h"
#include "PurReqEntryDO.h"
/**
 * 示例数据库实体类
 */

//主表
class PurReqDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// 源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	// 主题
	CC_SYNTHESIZE(string, subject, Subject);
	//是否红字
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// 采购类型
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// 需求部门
	CC_SYNTHESIZE(string, request_dept, Request_dept);
	// 需求人
	CC_SYNTHESIZE(string, requester, Requester);
	//需求时间
	CC_SYNTHESIZE(string, request_time, Request_time);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 参考金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 已订数量
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否自动生成
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// 单据阶段--公共接口
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 审核人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	// 核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	// 核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 生效时间
	CC_SYNTHESIZE(int, effective_time, Effective_time);
	// 已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 创建部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 创建人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//明细
	CC_SYNTHESIZE(list<PurReqEntryDO>,detail, Detail);
public:
	PurReqDO(){
		id = "";
		bill_no = "";
		bill_date = "";
		src_bill_type = "";
		src_bill_id = "";
		src_no = "";
		subject = "";
		is_rubric = -1;
		pur_type = "";
		request_dept = "";
		requester = "";
		request_time = "";
		qty = -1;
		amt = -1;
		ordered_qty = -1;
		attachment = "";
		remark = "";
		is_auto = -1;
		bill_stage = "";
		approver = "";
		bpmi_instance_id = "";
		approval_result_type = "";
		approval_remark = "";
		is_effective = -1;
		effective_time = -1;
		is_closed = -1;
		is_voided = -1;
		sys_org_code = "";
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";
	}
};
#endif