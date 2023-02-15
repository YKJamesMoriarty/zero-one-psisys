#pragma once

#ifndef _PUR_COM_MOD_BILL_STATUS_VO_
#define _PUR_COM_MOD_BILL_STATUS_VO_
#include "../../GlobalInclude.h"

class PurComModBillStatusVO{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);

public:
	// ��JSONת������
	BIND_TO_JSON(PurComModBillStatusVO, billId, isEffect, isClose, isCancelled, billStatus, updateDate, updatePerson);
};
#endif