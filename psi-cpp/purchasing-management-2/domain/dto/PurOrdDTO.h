#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _PUR_ORDER_DTO_
#define _PUR_ORDER_DTO_

#include "../../GlobalInclude.h"

/**
 * 
 */
namespace PUR_ORDER_DTO {
	class PurOrderDTO
	{
		// ���ݱ��
		CC_SYNTHESIZE(string, bill_no, Bill_no);
		// ��������
		CC_SYNTHESIZE(string, bill_date, Bill_date);
		// ��������
		CC_SYNTHESIZE(string, subject, Subject);
		// ���ֵ���
		CC_SYNTHESIZE(int, is_rubric, Is_rubric);
		// �ɹ�����
		CC_SYNTHESIZE(int, pur_type, Pur_type);
		// ��Ӧ��
		CC_SYNTHESIZE(string, supplier_id, Supplier_id);
		// ҵ����
		CC_SYNTHESIZE(string, op_dept, Op_dept);
		// ҵ��Ա
		CC_SYNTHESIZE(string, operator, Operator);
		// ������ʽ
		CC_SYNTHESIZE(string, delivery_method, Delivery_method);
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
		//��Ʊ����	
		CC_SYNTHESIZE(string, invoice_type, Invoice_type);
		//����
		CC_SYNTHESIZE(uint64_t, qty, Qty);
		//���		
		CC_SYNTHESIZE(float, amt, Amt);
		//Ԥ�����	
		CC_SYNTHESIZE(float, prepayment_bal, Prepayment_bal);
		//��������
		CC_SYNTHESIZE(uint64_t, settle_qty, Settle_qty);
		//������
		CC_SYNTHESIZE(float, settle_amt, Settle_amt);
		//���������		
		CC_SYNTHESIZE(uint64_t, in_qty, In_qty);
		//�������
		CC_SYNTHESIZE(float, in_cost, In_cost);
		//�ѽ�����
		CC_SYNTHESIZE(float, settle_amt, settle_amt);
		//�Զ�����
		CC_SYNTHESIZE(int, is_auto, Is_auto);
		//���ݽ׶�		
		CC_SYNTHESIZE(int, bill_stage, Bill_stage);
		//��ע
		CC_SYNTHESIZE(string, remark, Remark);
		//������
		CC_SYNTHESIZE(string, approver, Approver);
		//����Ч
		CC_SYNTHESIZE(int, is_effective, Is_effective);
		//��Чʱ��
		CC_SYNTHESIZE(string, effective_time, Effective_time);
		//�ѹر�
		CC_SYNTHESIZE(int, is_closed, Is_closed);
		//������
		CC_SYNTHESIZE(int, is_voided, Is_voided);	
		//�Ƶ�����
		CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
		//�Ƶ���
		CC_SYNTHESIZE(string, create_by, Create_by);
		//�Ƶ�ʱ��
		CC_SYNTHESIZE(string, create_time, Create_time);
		//�޸���
		CC_SYNTHESIZE(string, updateBy, UpdateBy);	
		//�޸�ʱ��
		CC_SYNTHESIZE(string, updateTime, UpdateTime);
		
	public:
		// ��JSONת������
		friend void from_json(const json& j, PurOrderDTO& t); // NOLINT
		BIND_TO_JSON(PurOrderDTO, bill_no, bill_date, subject, \
			is_rubric, pur_type, supplier_id, op_dept, operator, \
			delivery_method, delivery_time, transport_method, \
			payment_method, settle_method, settle_time, \
			invoice_type, qty, amt, prepayment_bal, settle_qty, \
			settle_amt, in_qty, in_cost, settle_amt, is_auto, \
			bill_stage, remark, approver, is_effective, \
			effective_time, is_closed, is_voided, sys_org_code, \
			create_time, updateBy, updateTime);
	};
}


#endif // !_PUR_ORDER_DTO_