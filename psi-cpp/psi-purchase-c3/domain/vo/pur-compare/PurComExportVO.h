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
#ifndef _PUR_COM_EXPORT_VO_
#define _PUR_COM_EXPORT_VO_

#include "../../GlobalInclude.h"


class PurComExportVO {

	//���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	////�����ص�
	//CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	////����ʱ��
	//CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	////��ѡ���۵�ids
	//CC_SYNTHESIZE(string, candidate_quot_ids, Candidate_quot_ids);
	////-----------------��ϸ�ֶο�ʼ----------------------------
	////��Ӧ��
	//CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	////����
	//CC_SYNTHESIZE(string, material_id, Material_id);
	////������λ
	//CC_SYNTHESIZE(string, unit_id, Unit_id);
	////����
	//CC_SYNTHESIZE(double, qty, Qty);
	////˰��%
	//CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	////��˰����
	//CC_SYNTHESIZE(double, price, Price);
	////�ۿ���%
	//CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	////��˰���
	//CC_SYNTHESIZE(double, amt, Amt);
	////����
	//CC_SYNTHESIZE(int, ranking, Ranking);
	////�Զ���1
	//CC_SYNTHESIZE(string, custom1, Custom1);
	////Դ����¼��
	//CC_SYNTHESIZE(string, src_no, Src_no);
	////��¼��
	//CC_SYNTHESIZE(string, entry_no, Entry_no);
	////�Զ���2
	//CC_SYNTHESIZE(string, custom2, Custom2);
	////Դ����¼id
	//CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	////Դ������
	//CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	////��ע
	//CC_SYNTHESIZE(string, remark, Remark);
	////���ݱ��
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	////Դ��id
	//CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	////----------------------��ϸ�ֶν���---------------------------------
	////�Ƿ���Ч
	//CC_SYNTHESIZE(int, is_effective, Is_effective);
	////����
	//CC_SYNTHESIZE(string, attachment, Attachment);
	////Դ��id
	//CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	////��������
	//CC_SYNTHESIZE(string, subject, Subject);
	////���ݽ׶�
	//CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	////Դ����
	//CC_SYNTHESIZE(string, src_no, Src_no);
	////�Ƿ��Զ�����
	//CC_SYNTHESIZE(int, is_auto, Is_auto);
	////��ע
	//CC_SYNTHESIZE(string, remark, Remark);
	////����ʵ��id
	//CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	////������
	//CC_SYNTHESIZE(int, is_voided, Ss_voided);
	////���ݱ��
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	////�Ƿ����
	//CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	////Դ������
	//CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	////�Ƶ�ʱ��
	//CC_SYNTHESIZE(string, create_time, Create_time);
	////��Чʱ��
	//CC_SYNTHESIZE(string, effective_time, Effective_time);
	////������
	//CC_SYNTHESIZE(string, approver, Approver);
	////�޸���
	//CC_SYNTHESIZE(string, update_by, Update_by);
	////�Ƶ�����
	//CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	////�ѹر�
	//CC_SYNTHESIZE(int, is_closed, Is_closed);
	////�����������
	//CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	////��������
	//CC_SYNTHESIZE(string, bill_date, Bill_date);
	////�Ƶ���
	//CC_SYNTHESIZE(string, create_by, Create_by);
	////�������
	//CC_SYNTHESIZE(string, approval_remark, Approval_remark);

public:
	BIND_TO_JSON(PurComExportVO, payment_method);
	//BIND_TO_JSON(PurComExportVO, payment_method, delivery_place, delivery_time, candidate_quot_ids, 
	//	//��ϸ�ֶο�ʼ
	//	supplier_id,material_id, unit_id, qty, tax_rate, price, discount_rate, amt,
	//	ranking, custom1, src_no, entry_no, custom2, src_entry_id, src_bill_type,remark, bill_no, src_bill_id, 
	//	//��ϸ�ֶν���
	//	is_effective, attachment, src_bill_id, subject, bill_stage, src_no,is_auto, remark, bpmi_instance_id, 
	//	is_voided, bill_no, is_rubric,src_bill_type, create_time, effective_time, approver, update_by, sys_org_code, 
	//	is_closed, approval_result_type, bill_date, create_by, approval_remark);
};
#endif // !

