#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_VO_
#define _PREPAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
#include "PrepaymentBillVO.h"

/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-��ѯ�����б���ʾ��ϸ��Ϣ
 */

class PrepaymentDetailBillVO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
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

public:
	// ��JSONת������
	BIND_TO_JSON(PrepaymentBillVO, id, bill_no, bill_date, subject, supplier_id, op_dept, op, paid_amt, bill_stage,
		is_effective, is_closed, is_voided, remark);

};
#endif // !_PREPAYMENT_DETAIL_BILL_VO_