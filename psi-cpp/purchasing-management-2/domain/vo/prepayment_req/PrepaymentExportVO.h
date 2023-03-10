#pragma once
#ifndef _PREPAYMENT_EXPORT_VO_
#define _PREPAYMENT_EXPORT_VO_

#include "../../GlobalInclude.h"
/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-����Ԥ�����뵥
 */

class PrepaymentExportVO {

	//��������
	CC_SYNTHESIZE(int, payment_type, Payment_type);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//ҵ����
	CC_SYNTHESIZE(string, od_dept, Od_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, op, Operator);



	//-----------------�������뵥��ϸ�ֶο�ʼ----------------------------
	//������
	CC_SYNTHESIZE(int, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);

	//-----------------�������뵥��ϸ�ֶο�ʼ----------------------------
	////������
	//CC_SYNTHESIZE(int, amt, Amt);
	////�Ѹ����
	//CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//Դ����¼��
	CC_SYNTHESIZE(double, src_on, Src_on);
	//��¼��
	CC_SYNTHESIZE(double, entry_on, Entry_on);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	///Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//----------------------��ϸ�ֶν���---------------------------------
	//�Ƿ���Ч
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	////Դ��id
	//CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(bool, is_auto, Is_auto);
	// ������ע
	CC_SYNTHESIZE(string, at_remark, At_remark);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//������
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	////���ݱ��
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	//�Ƿ����
	CC_SYNTHESIZE(bool, is_rubric, Is_rubric);
	////Դ������
	//CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
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
	BIND_TO_JSON(PrepaymentExportVO, payment_type, supplier_id, od_dept, op, amt, paid_amt,
		//�������뵥��ϸ�ֶο�ʼ
		amt, paid_amt, custom1, src_on, entry_on, custom2, src_entry_id, src_bill_type,
		remark, bill_no, src_bill_id,
		//��ϸ�ֶν���
		is_effective, attachment, src_bill_id, subject, bill_stage, src_no, is_auto, at_remark, bpmi_instance_id,
		is_voided, bill_no, is_rubric, src_bill_type, create_time, effective_time, approver, update_by, sys_org_code,
		is_closed, approval_result_type, bill_date, create_by, approval_remark);
};
#endif // !_PREPAYMENT_EXPORT_VO_