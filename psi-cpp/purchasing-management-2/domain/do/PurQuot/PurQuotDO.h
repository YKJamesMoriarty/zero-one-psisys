#pragma once
#ifndef _PUR_QUOT_DO_
#define _PUR_QUOT_DO_

#include "../DoInclude.h"

/**
 *��Ӧ���۵�ʵ����
 */
class PurQuotDO
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
	//�Ƿ���ʱ��Ӧ��
	CC_SYNTHESIZE(int, is_temp_supplier, Is_temp_supplier);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// ��Ӧ������
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	// ���ʽ	
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	// ����ʱ��
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	// �����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
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
	// ���
	CC_SYNTHESIZE(float, amt, Amt);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ��Զ�����:�Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ����״̬
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
	PurQuotDO() {
		

	}
};

#endif 
