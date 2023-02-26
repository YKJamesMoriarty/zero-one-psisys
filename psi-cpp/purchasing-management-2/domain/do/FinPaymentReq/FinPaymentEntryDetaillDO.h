#pragma once

#ifndef _FIN_PAYMENT_ENTRY_DETAIL_DO_
#define _FIN_PAYMENT_ENTRY_DETAIL_DO_
#include "../DoInclude.h"

/*
 *���������
 */
class FinPaymentEntryDetaillDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
	//����id
	CC_SYNTHESIZE(string, mid, Mid);
	//���ݺ�
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����¼id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
public:
	FinPaymentEntryDetaillDO() {

	}
};


#endif; //_FIN_PAYMENT_ENTRY_DETAIL_DO_