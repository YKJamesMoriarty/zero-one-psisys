#pragma once
#ifndef _PUR_QUOT_LIST_VO_H_
#define _PUR_QUOT_LIST_VO_H_
#include "../../GlobalInclude.h"
class PurQuotListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);

public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotListVO, billNo, billDate);

};
#endif