#pragma once
#ifndef _DEL_PUR_COM_VO_
#define _DEL_PUR_COM_VO_
#include "../../GlobalInclude.h"

class DelPurComVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);

public:
	// ��JSONת������
	BIND_TO_JSON(DelPurComVO, billId);
};
#endif