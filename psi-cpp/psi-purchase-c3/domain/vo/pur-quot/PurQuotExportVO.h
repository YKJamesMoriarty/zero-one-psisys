#pragma once
#ifndef _PUR_QUOT_EXPORT_VO_
#define _PUR_QUOT_EXPORT_VO_

#include "../../GlobalInclude.h"
	
//��VO�漰�����ݱ��е������ֶ�pur-quot��pur-quot-entry
//Ϊ������ͬ���ֶ�, ��pur-quot-entry�ֶε�����ǰ���entryǰ׺
class PurQuotExportVO {
	//�Ƿ���ʱ��Ӧ��
	CC_SYNTHESIZE(int, is_temp_supplier, is_temp_supplier);
	//��Ӧ������
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//�����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	//����ʱ��
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	//��ϵ�绰
	CC_SYNTHESIZE(string, phone, Phone);
	//����
	CC_SYNTHESIZE(string, fax, Fax);
	//�����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//���
	CC_SYNTHESIZE(double, amt, Amt);
	//--------------------��ϸ��ʼ----------------------
	//����
	CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
	//������λ
	CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
	//����
	CC_SYNTHESIZE(double, entry_qty, Entry_qty);
	//˰��%
	CC_SYNTHESIZE(double, entry_tax_rate, Entry_tax_rate);
	//��˰����
	CC_SYNTHESIZE(double, entry_price, Entry_price);
	//�ۿ���%
	CC_SYNTHESIZE(double, entry_discount_rate, Entry_discount_rate);
	//��˰���
	CC_SYNTHESIZE(double, entry_amt, Entry_amt);
	//�Զ���1
	CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
	//Դ����¼��---src_no
	CC_SYNTHESIZE(int, entry_src_no, Entry_src_no);
	//��¼��2
	CC_SYNTHESIZE(int, entry_entry_no, Entry_entry_no);
	//�Զ���2
	CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
	//Դ����¼id
	CC_SYNTHESIZE(string, entry_src_entry_id, Entry_src_entry_id);
	//Դ������
	CC_SYNTHESIZE(string, entry_src_bill_type, Entry_src_bill_type);
	//��ע
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	//���ݱ��
	CC_SYNTHESIZE(string, entry_bill_no, Entry_bill_no);
	//Դ��id
	CC_SYNTHESIZE(int, entry_src_bill_id, Entry_src_bill_id);
	//------------------��ϸ����-------------------------
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//������
	CC_SYNTHESIZE(int, is_voided, is_voided);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//�Ƿ����
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//�����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	//�������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);

public:
	BIND_TO_JSON(PurQuotExportVO, is_temp_supplier, supplier_name, supplier_id, payment_method, delivery_place,
		delivery_time, contact, phone, fax, email, qty, amt,
		//��ϸ�ֶο�ʼ
		entry_material_id, entry_unit_id, entry_qty, entry_tax_rate, entry_price, entry_discount_rate, entry_amt,
		entry_custom1, entry_src_no, entry_entry_no, entry_custom2, entry_src_entry_id, entry_src_bill_type, entry_remark, entry_bill_no, entry_src_bill_id,
		//��ϸ�ֶν���
		is_effective, attachment, src_bill_type, subject, bill_stage, src_no, is_auto, remark,
		bpmi_instance_id, is_voided, bill_no, is_rubric, src_bill_type, create_time, effective_time, approver, update_by,
		sys_org_code, is_closed, approval_result_type, bill_date, create_by, approval_remark);
};

#endif // !
