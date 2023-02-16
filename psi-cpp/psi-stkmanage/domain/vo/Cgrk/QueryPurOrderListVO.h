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
#ifndef _QUERY_PUR_ORDER_LIST_VO_
#define _QUERY_PUR_ORDER_LIST_VO_


class QueryPurOrderListVO 
{
	//ID
	CC_SYNTHESIZE(string, id, ID);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//�ɹ�����
	CC_SYNTHESIZE(string, purType, PurType);
	//���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	//Ԥ�������
	CC_SYNTHESIZE(double, prePaymentBal, PrePaymentBal);
	//���㷽ʽ
	CC_SYNTHESIZE(string, settleMethod, SettleMethod);
	//��������
	CC_SYNTHESIZE(string, deliveryTime, DeliverTime);
	//�����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliverPlace);
	//������ʽ
	CC_SYNTHESIZE(string, deliveryMethod, DeliverMethod);
	//���������
	CC_SYNTHESIZE(double, inQty, InQty);
	//�����ɱ�
	CC_SYNTHESIZE(double, inCost, InCost);	
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoiceAmt);
	//��Ʊ����
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//���
	CC_SYNTHESIZE(double, amt, Amt);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator1);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//�ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);

public:

	BIND_TO_JSON(QueryPurOrderListVO, id, billNo, billDate, purType, paymentMethod, prePaymentBal, settleMethod, deliveryTime, deliveryPlace,
		deliveryMethod, inQty, inCost, invoicedAmt, invoiceType, amt, isClosed, opDept, operator1, qty, remark, settleAmt, settledAmt, srcNo, subject, supplierId);
};

#endif // !_QUERY_PUR_ORDER_LIST_QUERY_