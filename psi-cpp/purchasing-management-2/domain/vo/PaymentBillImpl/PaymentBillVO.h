#pragma once

#ifndef _PAYMENT_BILL_VO_
#define _PAYMENT_BILL_VO_

#include "../../GlobalInclude.h"

/*
��ѯ�����б�
*/
class PaymentBillVO {
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id)
	// ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept)
	// ҵ��Ա
	CC_SYNTHESIZE(string, operator,Operator)
	// Դ����
	CC_SYNTHESIZE(string,src_no,Src_no)
	// ������
	CC_SYNTHESIZE(double, amt, Amt)
	// �Ѹ����
	CC_SYNTHESIZE(double, paid_amt, Paid_amt)
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч			
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�			
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������			
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// �Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ���ֵ���
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ��Чʱ��
	CC_SYNTHESIZE(int, effective_time, Effective_time);
	// ������
	CC_SYNTHESIZE(string, approver, approver);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// �Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	// �Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	// �޸���
	CC_SYNTHESIZE(string, update_by, Update_by);

public:
	// ��JSONת������
	BIND_TO_JSON(PaymentBillVO, bill_no, bill_date, subject, supplier_id, op_dept,
		operator, src_no, amt, paid_amt, bill_stage,is_effective, is_closed, is_voided,
		is_auto, is_rubric, remark,effective_time,
		approver, create_time, create_by, sys_org_code, update_time, update_by);
};



/*
��ѯ�����б�
*/
class PaymentBillDetailQuery : public PaymentBillVO {
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	// �Ѹ����
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(PaymentBillDetailQuery, src_no, amt, paid_amt, remark, custom1, custom2);
};

#endif