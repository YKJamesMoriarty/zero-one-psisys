#pragma once
#ifndef _PREPAYMENT_INTO_VO_
#define _PREPAYMENT_INTO_VO_

#include "../../GlobalInclude.h"

/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-����Ԥ�����뵥
 */
class PrepayaymentIntoVO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	//��������
	CC_SYNTHESIZE(int, payment_type, Payment_type);
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
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//�����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//������
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	//�Ƿ���Ч
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(bool, is_auto, Is_auto);
	//�Ƿ����
	CC_SYNTHESIZE(bool, is_rubric, Is_rubric);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//�ѹر�
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);


public:
	BIND_TO_JSON(PrepayaymentIntoVO, id, payment_type, supplier_id,
		op_dept, op, amt, paid_amt, remark, bill_no, approval_result_type, update_by,
		is_effective, is_voided, approver, bill_date,
		is_auto, is_rubric, sys_org_code, create_time, create_by, effective_time,
		bill_stage, is_closed);
};
#endif // !_PREPAYMENT_INTO_VO_
