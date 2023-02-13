//��Ϊ�ж�����ͬʱд_PUR_QUOT_��Ĺ��ܣ�����������NAIGUAN���������֣����ⷢ���������
#ifndef _PUR_QUOT_NAIGUAN_QUERY_
#define _PUR_QUOT_NAIGUAN_QUERY_


#include "../PageQuery.h"

class PurQuotNaiguanQUERY : public PageQuery
{
	
	//������һЩ�ֶΣ��Ҳ�ȷ���Ƿ���Ļ��õ������֮��д���룬���ֻ���Ҫ�����ֶΣ��������ȥ������Ҫ��ɾ����
	// ID
	CC_SYNTHESIZE(string, id, ID);
	// ���ݺ�/���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��¼��
	CC_SYNTHESIZE(string, entryNo, EntryNo);
	// Դ����¼��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// Դ������id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	// Դ����¼id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);


public:
	friend void from_json(const json& j, PurQuotNaiguanQUERY& t) {
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_I(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, entryNo);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);
		BIND_FROM_TO_NORMAL(j, t, srcEntryId);
	}
};

#endif // !_PUR_QUOT_NAIGUAN_QUERY_