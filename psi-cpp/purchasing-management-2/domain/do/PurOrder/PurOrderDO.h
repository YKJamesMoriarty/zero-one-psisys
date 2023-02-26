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
	CC_SYNTHESIZE(double, amt, Amt);
	// Ԥ�����	
	CC_SYNTHESIZE(double, prepayment_bal, Prepayment_bal);
	// ��������
	CC_SYNTHESIZE(double, settle_qty, Settle_qty);
	// ������
	CC_SYNTHESIZE(double, settle_amt, Settle_amt);
	// ���������		
	CC_SYNTHESIZE(double, in_qty, In_qty);
	// �����ɱ�
	CC_SYNTHESIZE(double, in_cost, In_cost);
	// �ѽ�����
	CC_SYNTHESIZE(double, settled_amt, Settled_amt);
	// �ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoiced_amt, Invoiced_amt);
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

public:
	PurOrderDO() {
		id = -1;
		bill_no = "";
		bill_date = "";
		src_bill_type = "";
		src_bill_id = "";
		src_no = "";
		subject = "";
		is_rubric = -1;
		pur_type = "";
		qty = -1;
		amt = -1;
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
		supplier_id = "";
		contact = "";
		phone = "";
		fax = "";
		email = "";
		op_dept = "";
		op_er = "";
		delivery_method = "";
		delivery_place = "";
		delivery_time = "";
		transport_method = "";
		payment_method = "";
		settle_method = "";
		settle_time = "";
		invoice_method = "";
		invoice_type = "";
		currency = "";
		exchange_rate = -1;
		prepayment_bal = -1;
		settle_qty = -1;
		settle_amt = -1;
		in_qty = -1;
		in_cost = -1;
		invoiced_amt = -1;
	}
};

#endif // !_PUR_ORDER_DO_
