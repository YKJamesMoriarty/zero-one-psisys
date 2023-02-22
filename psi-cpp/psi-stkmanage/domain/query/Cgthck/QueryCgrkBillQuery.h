#pragma once
#ifndef _QUERY_CGRK_BILL_QUERY_
#define _QUERY_CGRK_BILL_QUERY_

#include "../PageQuery.h"

/**
* �ɹ��˻������µĲ�ѯ�ɹ���ⵥ��¼�б����
*/
class QueryCgrkBillQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ���ݿ�ʼ����
	CC_SYNTHESIZE(std::string, billDateStart, BillDateStart);
	// ���ݽ�������
	CC_SYNTHESIZE(std::string, billDateEnd, BillDateEnd);
	// ��Ʊ����
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
public:
	// ��from_json
	friend void from_json(const json& j, QueryCgrkBillQuery& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateStart);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, invoiceType);
	}
};
#endif // !_QUERY_CGRK_BILL_QUERY_
