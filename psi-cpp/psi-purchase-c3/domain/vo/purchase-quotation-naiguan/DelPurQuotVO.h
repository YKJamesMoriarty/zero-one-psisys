#include "stdafx.h"
#include "../../GlobalInclude.h"

#ifndef _DEL_PUR_QUOT_VO_
#define _DEL_PUR_QUOT_VO_


//ɾ����Ӧ���۵���
class DelPurQuotVO
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);

public:
	// ��JSONת������
	BIND_TO_JSON(DelPurQuotVO, billNo);
};


#endif // !_DEL_PUR_QUOT_VO_