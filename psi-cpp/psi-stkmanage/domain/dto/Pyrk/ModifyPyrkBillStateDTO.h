#pragma once
#ifndef _MODIFY_PYRK_BILL_STATE_DTO_
#define _MODIFY_PYRK_BILL_STATE_DTO_

#include "../../GlobalInclude.h"

/**
* �޸���ӯ��ⵥ��״̬�������
*/
class ModifyPyrkBillStateDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, id, Id);
	// ��Ҫ�޸�Ϊ����״̬�ı��(1:�ر�, 2:����, 3:���ر�)
	CC_SYNTHESIZE(uint64_t, toState, ToState);
public:
	ModifyPyrkBillStateDTO() {
		id = "PYRK-220801-023";
		toState = 1;
	}
	// ��JSONת������
	friend void from_json(const json& j, ModifyPyrkBillStateDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_ULL(j, t, toState);
	}

};

#endif // !_MODIFY_PYRK_BILL_STATE_DTO_