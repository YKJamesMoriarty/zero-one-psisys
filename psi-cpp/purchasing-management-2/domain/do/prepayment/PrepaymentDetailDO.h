#pragma once

#ifndef _PREPAYMENTDETAILDO_H_
#define _PREPAYMENTDETAILDO_H_

#include "../DoInclude.h"
/**
 * ʾ�����ݿ�ʵ����-�ɹ�Ԥ��ʵ����
 */
class PrepaymentDetailDO {
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//����
	CC_SYNTHESIZE(string, mid, Mid);
	//���ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��¼��
	CC_SYNTHESIZE(uint64_t, entry_no, Entry_no);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcBillId
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paid_amt, Paid_amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(uint64_t, version, Version);

public:
	PrepaymentDetailDO() {
		entry_no = -1;
		amt = 0.00;
		paid_amt = 0.00;
		version = -1;
	}
};
#endif // _PREPAYMENTDETAILDO_H_

