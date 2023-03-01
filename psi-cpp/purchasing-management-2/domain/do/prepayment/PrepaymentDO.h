#pragma once
#ifndef _PREPAYMENT_DO_
#define _PREPAYMENT_DO_
#include "../DoInclude.h"

/**
 * �ɹ�Ԥ������ʵ����
 */
class PrepaymentDO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ���ݿ�ʼ����
	CC_SYNTHESIZE(string, bill_begin_date, Bill_begin_date);
	// ���ݽ�������
	CC_SYNTHESIZE(string, bill_end_date, Bill_end_date);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id); 
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//��������
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
	CC_SYNTHESIZE(string, op, Operator);
	//������
	CC_SYNTHESIZE(int, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ���ݽ׶�
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
	PrepaymentDO() {
		is_rubric = -1;
		amt = 0.00;
		paid_amt = 0.00;
		is_auto = -1;
		is_effective = -1;
		is_closed = -1;
		is_voided = -1;
		version = -1;
	}
};
#endif // !_PREPAYMENT_DO_
