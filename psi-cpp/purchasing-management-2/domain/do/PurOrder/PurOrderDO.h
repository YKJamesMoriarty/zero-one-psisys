#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/15 12:02:32

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
#ifndef _PUR_ORDER_DO_
#define _PUR_ORDER_DO_
#include "../DoInclude.h"

/**
 * �ɹ��������ݿ�ʵ����
 */
class PurOrderDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	// Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ���ֵ���
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// �ɹ�����
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// ��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, phone, Phone);
	// ����
	CC_SYNTHESIZE(string, fax, Fax);
	// �����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	// ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	// ҵ��Ա
	CC_SYNTHESIZE(string, op_er, Op_er);
	// ������ʽ
	CC_SYNTHESIZE(string, delivery_method, Delivery_method);
	// �����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	// ��������	
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	// ���䷽ʽ
	CC_SYNTHESIZE(string, transport_method, Transport_method);
	// ���ʽ	
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	// ���㷽ʽ	
	CC_SYNTHESIZE(string, settle_method, Settle_method);
	// ��������	
	CC_SYNTHESIZE(string, settle_time, Settle_time);
	// ��Ʊ��ʽ
	CC_SYNTHESIZE(string, invoice_method, Invoice_method);
	// ��Ʊ����	
	CC_SYNTHESIZE(string, invoice_type, Invoice_type);
	// ��ұ���
	CC_SYNTHESIZE(string, currency, Currency);
	// ����
	CC_SYNTHESIZE(double, exchange_rate, Exchange_rate);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);
	// ���
	CC_SYNTHESIZE(float, amt, Amt);
	// Ԥ�����	
	CC_SYNTHESIZE(float, prepayment_bal, Prepayment_bal);
	// ��������
	CC_SYNTHESIZE(double, settle_qty, Settle_qty);
	// ������
	CC_SYNTHESIZE(float, settle_amt, Settle_amt);
	// ���������		
	CC_SYNTHESIZE(double, in_qty, In_qty);
	// �����ɱ�
	CC_SYNTHESIZE(float, in_cost, In_cost);
	// �ѽ�����
	CC_SYNTHESIZE(float, settled_amt, Settled_amt);
	// �ѿ�Ʊ���
	CC_SYNTHESIZE(float, invoiced_amt, Invoiced_amt);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ��Զ�����:�Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ���ݽ׶�		
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// �����
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	// �����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	// �������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	// �Ƿ�ر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// �޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	// �汾
	CC_SYNTHESIZE(int, version, Version);
public:
	PurOrderDO() {
		exchange_rate = 0.0;
		qty = 0.0;
		amt = 0.0;
		prepayment_bal = 0.0;
		settle_amt = 0.0;
		settle_qty = 0.0;
		in_qty = 0.0;
		in_cost = 0.0;
		settled_amt = 0.0;
		invoiced_amt = 0.0;
		is_rubric = -1;
		is_auto = -1;
		is_effective = -1;
		is_closed = -1;
		is_voided = -1;
		version = -1;
	}
};

#endif // !_PUR_ORDER_DO_
