#pragma once
#ifndef _PUR_QUOT_DIVIDED_LIST_VO_H_
#define _PUR_QUOT_DIVIDED_LIST_VO_H_
#include "../../GlobalInclude.h"
class PurQuotDividedListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotDividedListVO, billNo);

};
#endif