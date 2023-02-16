/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/15 11:59:38

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
#include "stdafx.h"
#include "PurOrderDTO.h"
void from_json(const json& j, PurOrderDTO& t) { // NOLINT
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
	BIND_FROM_TO_NORMAL(j, t, approve_result_type);
	// �������
	BIND_FROM_TO_NORMAL(j, t, approve_remark);
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