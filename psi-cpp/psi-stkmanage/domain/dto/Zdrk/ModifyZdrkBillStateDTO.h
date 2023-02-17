#pragma once
#ifndef _MODIFYZDRKBILLSTATEDTO_DTO_
#define _MODIFYZDRKBILLSTATEDTO_DTO_

#include "../../GlobalInclude.h"

/**
 * ���ݱ�Ŵ������
 */
class ModifyZdrkBillStateDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyZdrkBillStateDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
	BIND_TO_JSON(ModifyZdrkBillStateDTO, billNo, isClosed, isVoided);
};

#endif // !_QueryDoc_DTO_

