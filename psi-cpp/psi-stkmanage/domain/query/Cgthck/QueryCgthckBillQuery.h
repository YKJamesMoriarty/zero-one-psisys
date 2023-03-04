#ifndef _QUERY_CGTHCK_BILL_QUERY_
#define _QUERY_CGTHCK_BILL_QUERY_
#include "../PageQuery.h"

/**
* �ɹ��˻������ҳ��ѯ����
*/
class QueryCgthckBillQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ������ʼ����
	CC_SYNTHESIZE(string, beginData, BeginData);
	// ���ݽ�������
	CC_SYNTHESIZE(string, endData, EndData);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, isEff, IsEff);
	// �Ƿ�ر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// ��from_json
	friend void from_json(const json& j, QueryCgthckBillQuery& t)
	{
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, beginData);
		BIND_FROM_TO_NORMAL(j, t, endData);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEff);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
};


#endif // !_QUERY_CGTHCK_BILL_QUERY_

