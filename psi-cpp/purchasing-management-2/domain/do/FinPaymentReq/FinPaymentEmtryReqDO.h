#pragma once

#ifndef _FIN_PAYMENT_ENTRY_REQ_DO_
#define _FIN_PAYMENT_ENTRY_REQ_DO_
#include "../DoInclude.h"

class FINRaymentEntryReqDO {
	//id
	CC_SYNTHESIZE(string, id, Id);
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
	CC_SYNTHESIZE(double, amt, amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paidAmt, paid_amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	FINRaymentEntryReqDO() {

	}
};


#endif; //_FIN_PAYMENT_ENTRY_REQ_DO_