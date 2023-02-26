#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_VO_
#define _PREPAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * ʾ����ʾ����
 * �ɹ�Ԥ������-��ѯ�����б���ʾ��ϸ��Ϣ
 */

class PrepaymentDetailBillVO {
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//��¼��
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
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
	BIND_TO_JSON(PrepaymentDetailBillVO, id, entry_no, src_no, amt, remark, custom1, custom2);

	PrepaymentDetailBillVO(){
		amt = 0;
	}
};
#endif // !_PREPAYMENT_DETAIL_BILL_VO_