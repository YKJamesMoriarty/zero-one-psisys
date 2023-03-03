#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _QUERY_PUR_ORDER_LIST_QUERY_
#define _QUERY_PUR_ORDER_LIST_QUERY_

#include "../PageQuery.h"

class QueryPurOrderListQuery : public PageQuery
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�������ڣ���ʼ��
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	//�������ڣ�������
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	//�ɹ�����
	CC_SYNTHESIZE(string, purType, PurType);
	//���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	//���㷽ʽ
	CC_SYNTHESIZE(string, settleMethod, SettleMethod);
	//�������ڣ���ʼ��
	CC_SYNTHESIZE(string, deliveryTimeStart, DeliveryTimeStart);
	//�������ڣ�������
	CC_SYNTHESIZE(string, deliveryTimeEnd, DeliveryTimeEnd);
	//������ʽ
	CC_SYNTHESIZE(string, deliveryMethod, DeliveryMethod);
	//��Ʊ����
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);




public:
	// ��from_json
	friend void from_json(const json& j, QueryPurOrderListQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateStart);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, purType);
		BIND_FROM_TO_NORMAL(j, t, paymentMethod);
		BIND_FROM_TO_NORMAL(j, t, settleMethod);
		BIND_FROM_TO_NORMAL(j, t, deliveryTimeStart);
		BIND_FROM_TO_NORMAL(j, t, deliveryTimeEnd);
		BIND_FROM_TO_NORMAL(j, t, deliveryMethod);
		BIND_FROM_TO_NORMAL(j, t, invoiceType);

	}
};

#endif // !_QUERY_PUR_ORDER_LIST_QUERY_