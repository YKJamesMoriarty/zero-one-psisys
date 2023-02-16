#pragma once
#ifndef _MODIFY_CGRK_BILL_STATE_DTO_
#define _MODIFY_CGRK_BILL_STATE_DTO_

#include "../../GlobalInclude.h"

/**
 * �޸ĵ���״̬
 */
class ModifyCgrkBillStateDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyCgrkBillStateDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
	
};

#endif // !_MODIFY_CGRK_BILL_STATE_DTO_