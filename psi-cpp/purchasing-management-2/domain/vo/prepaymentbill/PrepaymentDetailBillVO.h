#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_VO_
#define _PREPAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
#include "PrepaymentBillVO.h"

/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-��ѯ�����б���ʾ��ϸ��Ϣ
 */

class PrepaymentDetailBillVO : public PrepaymentBillVO {
	//������
	CC_SYNTHESIZE(int, amt, Amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(PrepaymentDetailBillVO, bill_no, bill_date, subject, supplier_id, od_dept, op, amt, paid_amt, bill_stage, is_effective, is_closed,
		is_voided, remark, effective_time, approver, create_time, create_by, sys_org_code, update_time, update_by, custom1, custom2)

};
#endif // !_PREPAYMENT_DETAIL_BILL_VO_