
#pragma once
#ifndef _DEL_PUR_COM_DTO_H_
#define _DEL_PUR_COM_DTO_H_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class DelPurComDTO{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
public:
	// ��JSONת������
	friend void from_json(const json& j, DelPurComDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billId);
	}

};

#endif // !_ADD_PUR_COM_DTO_

