#pragma once
#ifndef _PREPAYMENT_VO_
#define _PREPAYMENT_VO_

#include "../../GlobalInclude.h"

/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-����޸�Ԥ������-�������
 */
class PrepaymentVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ҵ��Ա
	CC_SYNTHESIZE(string, op, Operator);
	// ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);

	// ������
	CC_SYNTHESIZE(int, amt, Amt);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	// ������ע
	CC_SYNTHESIZE(string, at_remark, At_remark);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);

	//------------------��Ҫ�޸�------------------------
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(int, is_voided, Is_voided);

public:
	// ��JSONת������
	BIND_TO_JSON(PrepaymentVO, bill_no, bill_date, subject, op, op_dept, supplier_id, amt, custom1, custom2, at_remark, attachment, bill_stage, is_effective, is_closed, is_voided);
};

#endif // !_PREPAYMENT_VO_