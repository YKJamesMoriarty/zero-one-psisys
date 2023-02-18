#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#include "../../GlobalInclude.h"

class PurQuotFindDetailBillVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotFindDetailBillVO, billNo, billDate, billStage);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_
