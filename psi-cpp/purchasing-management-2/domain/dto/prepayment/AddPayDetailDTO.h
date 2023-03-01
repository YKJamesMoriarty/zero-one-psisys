#pragma once

#ifndef _ADDPAYDETAILDTO_H_
#define _ADDPAYDETAILDTO_H_

#include "../../GlobalInclude.h"

/**
 * �ɹ�Ԥ������-���Ԥ������-������ϸ
 * �������뵥��ϸ����fin_payment_req_entry
 */
class AddPayDetailDTO {
	//��¼��
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);
	// ������
	CC_SYNTHESIZE(double, amt, Amt);
	// �Ѹ����
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	friend void from_json(const json& j, AddPayDetailDTO& t) {
		BIND_FROM_TO_I(j, t, entry_no);
		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		BIND_FROM_TO_NORMAL(j, t, src_bill_id);
		BIND_FROM_TO_NORMAL(j, t, src_entry_id);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, paid_amt);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	} // NOLINT
	BIND_TO_JSON(AddPayDetailDTO, entry_no, src_bill_type, src_bill_id, src_entry_id, src_no, amt, paid_amt, remark, custom1, custom2);
};


#endif // _ADDPAYDETAILDTO_H_