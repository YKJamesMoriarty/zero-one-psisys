#pragma once

#ifndef _PURINQUIRYFINDDETAILBILL_QUERY_
#define _PURINQUIRYFINDDETAILBILL_QUERY_

#include "../PageQuery.h"

/**
 * ʾ����ѯ���� ���� ָ���ɹ�ѯ�۵����飨���ݵ��ݱ�Ų�ѯ��
 */

class PurInquiryFindDetailBillQuery : public PageQuery
{
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // ��Ӧmysql���ݿ���bill_no�ֶ�

public:
	// ��from_json
	friend void from_json(const json& j, PurInquiryFindDetailBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
	}
};

#endif // !_PURINQUIRYFINDDETAILBILL_QUERY_