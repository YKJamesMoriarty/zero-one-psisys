#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/15 10:55:01

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
#ifndef _PUR_ORDER_QUERY_
#define _PUR_ORDER_QUERY_

#include "../PageQuery.h"

/**
 * �ɹ�������ҳ��ѯ����
 */
class PurOrderQuery : public PageQuery {
	// ID
	CC_SYNTHESIZE(uint64_t, id, Id);
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
	// ��JSONת������
	friend void from_json(const json& j, PurOrderQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		// ID
		BIND_FROM_TO_ULL(j, t, id);
		// ���ݱ��
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		// ��������
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		// Դ������
		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		// Դ��id
		BIND_FROM_TO_NORMAL(j, t, src_bill_id);
		// Դ����
		BIND_FROM_TO_NORMAL(j, t, src_no);
		// ��������
		BIND_FROM_TO_NORMAL(j, t, subject);
		// ���ֵ���
		BIND_FROM_TO_I(j, t, is_rubric);
		// �ɹ�����
		BIND_FROM_TO_NORMAL(j, t, pur_type);
		// ��Ӧ��
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		// ��ϵ��
		BIND_FROM_TO_NORMAL(j, t, contact);
		// ��ϵ�绰
		BIND_FROM_TO_NORMAL(j, t, phone);
		// ����
		BIND_FROM_TO_NORMAL(j, t, fax);
		// �����ʼ�
		BIND_FROM_TO_NORMAL(j, t, email);
		// ҵ����
		BIND_FROM_TO_NORMAL(j, t, op_dept);
		// ҵ��Ա
		BIND_FROM_TO_NORMAL(j, t, op_er);
		// ������ʽ
		BIND_FROM_TO_NORMAL(j, t, delivery_method);
		// �����ص�
		BIND_FROM_TO_NORMAL(j, t, delivery_place);
		// ��������	
		BIND_FROM_TO_NORMAL(j, t, delivery_time);
		// ���䷽ʽ
		BIND_FROM_TO_NORMAL(j, t, transport_method);
		// ���ʽ	
		BIND_FROM_TO_NORMAL(j, t, payment_method);
		// ���㷽ʽ	
		BIND_FROM_TO_NORMAL(j, t, settle_method);
		// ��������	
		BIND_FROM_TO_NORMAL(j, t, settle_time);
		// ��Ʊ��ʽ
		BIND_FROM_TO_NORMAL(j, t, invoice_method);
		// ��Ʊ����	
		BIND_FROM_TO_NORMAL(j, t, invoice_type);
		// ��ұ���
		BIND_FROM_TO_NORMAL(j, t, currency);
		// ����
		BIND_FROM_TO_D(j, t, exchange_rate);
		// ����
		BIND_FROM_TO_D(j, t, qty);
		// ���
		BIND_FROM_TO_F(j, t, amt);
		// Ԥ�����	
		BIND_FROM_TO_F(j, t, prepayment_bal);
		// ��������
		BIND_FROM_TO_D(j, t, settle_qty);
		// ������
		BIND_FROM_TO_F(j, t, settle_amt);
		// ���������		
		BIND_FROM_TO_D(j, t, in_qty);
		// �����ɱ�
		BIND_FROM_TO_F(j, t, in_cost);
		// �ѽ�����
		BIND_FROM_TO_F(j, t, settled_amt);
		// �ѿ�Ʊ���
		BIND_FROM_TO_F(j, t, invoiced_amt);
		// ����
		BIND_FROM_TO_NORMAL(j, t, attachment);
		//��ע
		BIND_FROM_TO_NORMAL(j, t, remark);
		// �Ƿ��Զ�����:�Զ�����
		BIND_FROM_TO_I(j, t, is_auto);
		// ���ݽ׶�		
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		// �����
		BIND_FROM_TO_NORMAL(j, t, approver);
		// ����ʵ��id
		BIND_FROM_TO_NORMAL(j, t, bpmi_instance_id);
		// �����������
		BIND_FROM_TO_NORMAL(j, t, approval_result_type);
		// �������
		BIND_FROM_TO_NORMAL(j, t, approval_remark);
		// �Ƿ���Ч
		BIND_FROM_TO_I(j, t, is_effective);
		// ��Чʱ��
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		// �Ƿ�ر�
		BIND_FROM_TO_I(j, t, is_closed);
		// �Ƿ�����
		BIND_FROM_TO_I(j, t, is_voided);
		// ��������
		BIND_FROM_TO_NORMAL(j, t, sys_org_code);
		// ������
		BIND_FROM_TO_NORMAL(j, t, create_by);
		// ����ʱ��
		BIND_FROM_TO_NORMAL(j, t, create_time);
		// �޸���
		BIND_FROM_TO_NORMAL(j, t, update_by);
		// �޸�ʱ��
		BIND_FROM_TO_NORMAL(j, t, update_time);
		// �汾
		BIND_FROM_TO_I(j, t, version);
	}
};
#endif // !_PUR_ORDER_QUERY_




