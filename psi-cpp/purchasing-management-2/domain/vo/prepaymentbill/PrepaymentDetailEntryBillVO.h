#pragma once
#ifndef _PREPAYMENT_DETAIL_ENTRY_BILL_VO_
#define _PREPAYMENT_DETAIL_ENTRY_BILL_VO_

#include "../../GlobalInclude.h"
/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-��ѯ�����б���ʾ��ϸ
 */

class PrepaymentDetailEntryBillVO {

	//ID
	CC_SYNTHESIZE(string, id, Id);
	//���ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��¼��
	CC_SYNTHESIZE(string, entry_no, Entry_no);
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
	BIND_TO_JSON(PrepaymentDetailEntryBillVO, id, bill_no, entry_no, amt, remark,  custom1, custom2)

};
#endif // !_PREPAYMENT_DETAIL_ENTRY_BILL_VO_