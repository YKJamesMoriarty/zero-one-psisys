#pragma once
#ifndef _PREPAYMENT_BILL_VO_
#define _PREPAYMENT_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-��ѯ�����б���ʾ��Ϣ
 */
class PrepaymentBillVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//ҵ����
	CC_SYNTHESIZE(string, od_dept, Od_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, op, Operator);
	//������
	CC_SYNTHESIZE(int, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
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
	BIND_TO_JSON(PrepaymentBillVO, bill_no, bill_date, subject, supplier_id, od_dept, op, amt, paid_amt, bill_stage,
		is_effective, is_closed, is_voided, remark, effective_time, approver, create_time, create_by, sys_org_code, update_time, update_by);
public:
	PrepaymentBillVO() {
		bill_no = "test";
		bill_date = "test";
	}
};
#endif // !_PREPAYMENT_BILL_VO_