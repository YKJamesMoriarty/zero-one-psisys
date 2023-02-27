#pragma once
#ifndef _FIN_PAYMENT_REQ_
#define _FIN_PAYMENT_REQ_

#include "../DoInclude.h"

class FinPayReqDO
{
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//
	CC_SYNTHESIZE(string, subject, Subject);
	//�Ƿ����
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//��������
	CC_SYNTHESIZE(string, payment_type, Payment_type);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);

	//ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator);

	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//�����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//�������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//������
	CC_SYNTHESIZE(string, create_by, Create_by);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
public:
	FinPayReqDO() {
		//��������
		sys_org_code = "";
		//Դ������
		src_bill_type = "";
		//��������
		payment_type = "";
		//�Ѹ����
		paid_amt = 0.0000; 
		//Դ��id
		src_bill_id = "";
		//Դ����
		src_no = "";
		//��������
		subject = "";
		//�Ƿ����
		is_rubric = 0;
		//�ο����
		amt = 0.00;
		//����
		attachment = "";
		//��ע
		remark = "";
		//�Ƿ��Զ�����
		is_auto = 0;
		//�����
		approver = "";
		//����id
		bpmi_instance_id = "";
		//�����������
		approval_result_type = "";
		//�������
		approval_remark = "";
		//�Ƿ���Ч
		is_effective = 0;
		//��Чʱ��
		effective_time = "";
		//�Ƿ��ѹر�
		is_closed = 0;
		//�Ƿ�����
		is_voided = 0;
		//�޸���
		update_by = "";
		//�޸�ʱ��
		update_time = "";
		//�汾
		version = -1;
	}

};
#endif 