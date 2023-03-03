#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _PURORDER_DO_
#define _PURORDER_DO_
#include "../DoInclude.h"

/**
 * pur_order���ݿ�ʵ����
 */
class PurOrderDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//�Ƿ����
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//�ɹ�����
	CC_SYNTHESIZE(string, purType, PurType);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	//��ϵ�绰
	CC_SYNTHESIZE(string, phone, Phone);
	//����
	CC_SYNTHESIZE(string, fax, Fax);
	//�����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator1);
	//������ʽ
	CC_SYNTHESIZE(string, deliveryMethod, DeliveryMethod);
	//�����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	//���䷽ʽ
	CC_SYNTHESIZE(string, transportMethod, TransportMethod);
	//���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	//���㷽ʽ
	CC_SYNTHESIZE(string, settleMethod, SettleMethod);
	//��������
	CC_SYNTHESIZE(string, settleTime, SettleTime);
	//��Ʊ��ʽ
	CC_SYNTHESIZE(string, invoiceMethod, InvoiceMethod);
	//��Ʊ����
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//��ұ���
	CC_SYNTHESIZE(string, currency, Currency);
	//����
	CC_SYNTHESIZE(double, exchangeRate, ExchangeRate);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//���
	CC_SYNTHESIZE(double, amt, Amt);
	//Ԥ�������
	CC_SYNTHESIZE(double, prepaymentBal, PrepaymentBal);
	//��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//���������
	CC_SYNTHESIZE(double, inQty, InQty);
	//�����ɱ�
	CC_SYNTHESIZE(double, inCost, InCost);
	//�ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//�����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��������
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�汾
	CC_SYNTHESIZE(string, version, Version);



public:
	StkIoDO() {


	}
};

#endif // !_STKIO_DO_
