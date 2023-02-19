#pragma once
#ifndef _PRE_PAYMENT_DTO_
#define _PRE_PAYMENT_DTO_

#include "../../GlobalInclude.h"

/**
 * �ɹ�Ԥ������-����޸�Ԥ������-�������
 * �������뵥����fin_payment_req
 */
class PrepaymentDTO
{
	//------------------ֱ������------------------------
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
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
	// ������ע
	CC_SYNTHESIZE(string, at_remark, At_remark);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);

	//------------------������------------------------
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(bool, is_voided, Is_voided);

	// ����
	CC_SYNTHESIZE(string, mid, Mid);
	//��¼��
	CC_SYNTHESIZE(double, entry_on, Entry_on);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//Դ����¼��
	CC_SYNTHESIZE(double, src_on, Src_on);
	// ������
	CC_SYNTHESIZE(int, amt, Amt);
	// �Ѹ����
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	friend void from_json(const json& j, PrepaymentDTO& t); // NOLINT
	BIND_TO_JSON(PrepaymentDTO, id, bill_no, bill_date, subject, op, op_dept, supplier_id, at_remark, attachment, bill_stage, is_effective, is_closed, is_voided,
		mid, entry_on, src_bill_type, src_bill_id, src_entry_id, src_on, amt, paid_amt, remark, custom1, custom2);
};

#endif // !_SAMPLE_DTO_