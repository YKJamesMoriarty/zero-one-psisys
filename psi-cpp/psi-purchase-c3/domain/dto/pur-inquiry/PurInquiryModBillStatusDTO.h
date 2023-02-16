#include "stdafx.h"
#include "../../GlobalInclude.h"
#ifndef __PURINQUIRYMODBILLSTATUSDTO_H__
#define __PURINQUIRYMODBILLSTATUSDTO_H__


//����״̬DTO
class PurInquiryModBillStatusDTO
{
	//�ѹر�			;
	CC_SYNTHESIZE(int, is_close, Is_close);
	//�Ƿ�����			;
	CC_SYNTHESIZE(int, is_voided, Is_voided);
public:
	friend void from_json(const json& j, PurInquiryModBillStatusDTO& t)
	{
		BIND_FROM_TO_I(j, t, is_close);
		BIND_FROM_TO_I(j, t, is_voided);
	}


};
#endif  //__PURINQUIRYMODBILLSTATUSDTO_H__
