#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:15:01

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
#ifndef _PUR_QUOT_EXPORT_VO_
#define _PUR_QUOT_EXPORT_VO_

#include "../../GlobalInclude.h"
	

class PurQuotExportVO {
	//�Ƿ���ʱ��Ӧ��
	CC_SYNTHESIZE(int, is_temp_supplier, is_temp_supplier);
	//��Ӧ������
	CC_SYNTHESIZE(std::string, supplier_name, supplier_name);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, supplier_id);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, payment_method);
	//�����ص�
	CC_SYNTHESIZE(string, delivery_place, delivery_place);
	//����ʱ��
	CC_SYNTHESIZE(string, delivery_time, delivery_time);
	//��ϵ��
	CC_SYNTHESIZE(string, contact, contact);
	//��ϵ�绰
	CC_SYNTHESIZE(string, phone, phone);
	//����
	CC_SYNTHESIZE(string, fax, fax);
	//�����ʼ�
	CC_SYNTHESIZE(string, email, email);
	//����
	CC_SYNTHESIZE(double, qty, qty);
	//���
	CC_SYNTHESIZE(double, amt, amt);
	//--------------------��ϸ��ʼ----------------------
	//����
	CC_SYNTHESIZE(string, material_id, material_id);
	//������λ
	CC_SYNTHESIZE(string, unit_id, unit_id);
	//����
	CC_SYNTHESIZE(double, qty, qty);
	//˰��%
	CC_SYNTHESIZE(double, tax_rate, tax_rate);
	//��˰����
	CC_SYNTHESIZE(double, price, price);
	//�ۿ���%
	CC_SYNTHESIZE(double, discount_rate, discount_rate);
	//��˰���
	CC_SYNTHESIZE(double, amt, amt);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, custom1);
	//Դ����¼��---src_no
	CC_SYNTHESIZE(int, src_no, src_no);
	//��¼��2
	CC_SYNTHESIZE(int, entry_no, entry_no);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, custom2);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, src_entry_id);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, src_bill_type);
	//��ע
	CC_SYNTHESIZE(string, remark, remark);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, bill_no);
	//Դ��id
	CC_SYNTHESIZE(int, src_bill_id, src_bill_id);
	//------------------��ϸ����-------------------------
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, is_effective);
	//����
	CC_SYNTHESIZE(string, attachment, attachment);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, src_bill_id);
	//��������
	CC_SYNTHESIZE(string, subject, subject);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, bill_stage);
	//Դ����
	CC_SYNTHESIZE(string, src_no, src_no);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, is_auto);
	//��ע
	CC_SYNTHESIZE(string, remark, remark);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, bpmi_instance_id);
	//������
	CC_SYNTHESIZE(int, is_closed, is_closed);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, bill_no);
	//�Ƿ����
	CC_SYNTHESIZE(int, is_rubric, is_rubric);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, src_bill_type);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, create_time);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, effective_time);
	//������
	CC_SYNTHESIZE(string, approver, approver);
	//�޸���
	CC_SYNTHESIZE(string, update_by, update_by);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, sys_org_code);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, is_closed);
	//�����������
	CC_SYNTHESIZE(string, approval_result_type, approval_result_type);
	//��������
	CC_SYNTHESIZE(string, bill_date, bill_date);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, create_by);
	//�������
	CC_SYNTHESIZE(string, approval_remark, approval_remark);

public:
	BIND_TO_JSON(PurQuotExportVO, is_temp_supplier, supplier_name, supplier_id, payment_method, delivery_place,
		delivery_time, contact, phone, fax, email, qty, amt,
		//��ϸ�ֶο�ʼ
		material_id, unit_id, qty, tax_rate, price, discount_rate, amt,
		custom1, src_no, entry_no, custom2, src_entry_id, src_bill_type, remark, bill_no, src_bill_id,
		//��ϸ�ֶν���
		is_effective, attachment, src_bill_type, subject, bill_stage, src_no, is_auto, remark,
		bpmi_instance_id, is_closed, bill_no, is_rubric, src_bill_type, create_time, effective_time, approver, update_by,
		sys_org_code, is_closed, approval_result_type, bill_date, create_by, approval_remark);
};

#endif // !
