#pragma once
#ifndef _PREPAYMENT_ENTRY_DTO_
#define _PREPAYMENT_ENTRY_DTO_

#include "../../GlobalInclude.h"

/**
 * �ɹ�Ԥ������-����޸�Ԥ������-������ϸ
 * �������뵥��ϸ����fin_payment_req_entry
 */
class PrepaymentEntryDTO
{

	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string,mid, Mid);
	// ���ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
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
	friend void from_json(const json& j, PrepaymentEntryDTO& t); // NOLINT
	BIND_TO_JSON(PrepaymentEntryDTO, id, mid, bill_no, entry_on, src_bill_type, src_bill_id, src_entry_id, src_on, amt, paid_amt, remark, custom1, custom2);
};

#endif // !_PREPAYMENT_ENTRY_DTO_
