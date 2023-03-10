﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/22 22:02:32

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

#ifndef _FIN_PAYMENT_REQ_DO_
#define _FIN_PAYMENT_REQ_DO_
#include "../DoInclude.h"
#include "FinPaymentReqEntryDO.h"

/*
 * 采购付款申请DO
 */
class FinPaymentReqDO
{
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//源单号
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单编号
	CC_SYNTHESIZE(string, src_no, Src_no);

	CC_SYNTHESIZE(string, subject, Subject);
	//是否红字
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//付款类型
	CC_SYNTHESIZE(string, payment_type, Payment_type);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//业务员
	CC_SYNTHESIZE(string, operator1,Operator);
	//申请金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已付金额
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//审核人
	CC_SYNTHESIZE(string, approver, Approver);
	//审核实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//生效时间
	CC_SYNTHESIZE(string,effective_time, Effective_time);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//创建部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//创建人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//版本
	CC_SYNTHESIZE(int, version, Version);
	
	CC_SYNTHESIZE(list<FinPaymentReqEntryDO>, detail, Detail);
public:
	FinPaymentReqDO()
	{
		id = "";
		bill_no = "";
		bill_date = "";
		src_bill_type = "";
		src_bill_id = "";
		src_no = "";
		subject = "";
		is_rubric = -1;
		payment_type = "";
		supplier_id = "";
		op_dept = "";
		operator1 = "";
		amt = -1;
		paid_amt = -1;
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

#endif // !_FIN_PAYMENT_REQ_DO_