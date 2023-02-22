#pragma once
#ifndef _PREPAYMENT_DO_
#define _PREPAYMENT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����-�ɹ�Ԥ��ʵ����
 */
class PrepaymentDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
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
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(int, is_voided, Is_voided);
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
	PrepaymentDO() {
		id = 0;
		bill_no = "";
		bill_date = "";
		subject = "";
		supplier_id = "";
		op_dept = "";
		op = "";
		amt = 0;
	}
};
#endif // !_PREPAYMENT_DO_
