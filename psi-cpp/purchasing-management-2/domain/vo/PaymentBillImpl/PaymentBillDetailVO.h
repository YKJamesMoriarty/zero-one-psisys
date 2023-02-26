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
#ifndef _PAYMENT_BILL_DETAIL_VO_
#define _PAYMENT_BILL_DETAIL_VO_

#include "../../GlobalInclude.h"
#include "PaymentBillVO.h"

/*
��ѯ�����б�
*/
class PaymentBillDetailVO:public PaymentBillVO {
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	// �Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(PaymentBillDetailVO, billNo, billDate, subject, supplierId, opDept,
		operator, srcNo, amt, paidAmt, billStage, isEffective, isClosed, isVoided,
		isAuto, isRubric, remark, effectiveTime,
		approver, createTime, createBy, sysOrgCode, updateTime, updateBy, custom1, custom2);
};

#endif