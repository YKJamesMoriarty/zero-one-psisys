#include "stdafx.h"
#include "../../GlobalInclude.h"
#ifndef __PURINQUIRYREMOVEDTO_H__
#define __PURINQUIRYREMOVEDTO_H__

//ɾ��DTO
class PurInquiryRemoveDTO
{
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);

public:
	friend void from_json(const json& j, PurInquiryRemoveDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};


#endif  //__PURINQUIRYREMOVEDTO_H__