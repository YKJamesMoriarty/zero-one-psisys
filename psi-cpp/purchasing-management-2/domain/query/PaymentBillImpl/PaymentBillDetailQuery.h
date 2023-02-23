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
#ifndef _PAYMENT_BILL_DETAIL_QUERY_
#define _PAYMENT_BILL_DETAIL_QUERY_


#include "../PageQuery.h"
/*
��ѯ�����б�
*/
class PaymentBillDetailQuery {
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
	friend void from_json(const json& j, PaymentBillDetailQuery& t) {
		BIND_FROM_TO_ULL(j, t, srcNo);
		BIND_FROM_TO_ULL(j, t, remark);
		BIND_FROM_TO_ULL(j, t, custom1);
		BIND_FROM_TO_ULL(j, t, custom2);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, paidAmt);
	}
};

#endif