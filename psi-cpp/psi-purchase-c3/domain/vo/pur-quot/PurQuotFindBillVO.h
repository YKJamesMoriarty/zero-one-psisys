#pragma once
#ifndef _PUR_QUOT_FIND_BILL_VO_H_
#define _PUR_QUOT_FIND_BILL_VO_H_
#include "../../GlobalInclude.h"

class PurQuotFindBillVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotFindBillVO, billNo);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_
