#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/18 22:45

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

#ifndef __PUR_INQUIRY_DO_H__
#define __PUR_INQUIRY_DO_H__

#include "../DoInclude.h"

/*
*  �����ݿ� pur_inquiry ��Ӧ
*/

class PurInquiryDO
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
	// �Ƿ����
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// ���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	// �����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	// ����ʱ�� 
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	// ��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, phone, Phone);
	// ����
	CC_SYNTHESIZE(string, fax, Fax);
	// �����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);
	// �ο����
	CC_SYNTHESIZE(double, amt, Amt);
	// ��Ч�ı��۵���
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ���ݽ׶Σ������ӿڣ�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ������
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
	PurInquiryDO() {
		//id = "";
		bill_no = "CGXJ-230112-005";
		bill_date = "2023-2-22";
		src_bill_type = "����";
		src_bill_id = "";
		src_no = "";
		subject = "����";
		is_rubric = -1;
		payment_method = "";
		delivery_place = "";
		delivery_time = "2023-2-22";
		contact = "";
		phone = "";
		fax = "";
		email = "";
		qty = -1.0;
		amt = -1.0;
		quot_count = -1;
		attachment = "";
		remark = "";
		is_auto = -1;
		bill_stage = "";
		approver = "";
		bpmi_instance_id = "";
		approval_result_type = "";
		approval_remark = "";
		is_effective = -1;
		effective_time = "";
		is_closed = -1;
		is_voided = -1;
		sys_org_code = "";
		create_by = "";
		create_time = "2023-2-22";
		update_by = "";
		update_time = "2023-2-22";
		version = -1;
	}
	
};



#endif  //  !__PUR_INQUIRY_FIND_BILL_DO_H__