#pragma once

#ifndef _PURINQUIRYFINDDETAILBILL_DTO_
#define _PURINQUIRYFINDDETAILBILL_DTO_

#include "../../GlobalInclude.h"


//ָ��ѯ�۵���ϸ��Ϣ
class PurInquiryFindDetailBillDTO
{
	//������Ϣ
		//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);   // ��Ӧmysql���ݿ���bill_no�ֶ�

public:
	// ��JSONת������
	friend void from_json(const json& j, PurInquiryFindDetailBillDTO& t); // NOLINT
};



#endif  // !_PURINQUIRYFINDDETAILBIL__DTO_