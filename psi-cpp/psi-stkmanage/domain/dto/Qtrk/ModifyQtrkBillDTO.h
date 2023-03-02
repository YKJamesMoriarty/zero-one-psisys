#pragma once

#ifndef _ModifyQtrkBill_DTO_
#define _ModifyQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * �޸�������ⵥ�������
 */
class ModifyQtrkBillDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyQtrkBillDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
};

#endif // !_ModifyQtrkBill_DTO_