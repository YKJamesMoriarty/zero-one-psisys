#ifndef _PUR_COM_MOD_BILL_STATUS_DTO_
#define _PUR_COM_MOD_BILL_STATUS_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class PurComModBillStatusDTO{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
public:
	// ��JSONת������
	friend void from_json(const json& j, PurComModBillStatusDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_I(j, t, isEffect);
		BIND_FROM_TO_I(j, t, isClose);
		BIND_FROM_TO_I(j, t, isCancelled);
	}
};

#endif _

