#ifndef _ADD_PUR_COM_DTO_
#define _ADD_PUR_COM_DTO_



#pragma once
#ifndef _PUR_COMPARE_DTO_
#define _PUR_COMPARE_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"




#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class DelPurComDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);

public:
	// ��JSONת������
	friend void from_json(const json& j, DelPurComDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billId);
	}

};

#endif // !_ADD_PUR_COM_DTO_

