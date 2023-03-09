#pragma once
#pragma once
#ifndef _QUERYQTRKBILLLIST_QUERY_
#define _QUERYQTRKBILLLIST_QUERY_

#include "../PageQuery.h"

/**
 * ��ѯ������ϸ��Ϣ
 */
class QueryQtrkBillListQuery :public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������(��ʼ)
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	//��������(����)
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);


public:
	QueryQtrkBillListQuery()
	{
		billNo = "";
		billDateStart = "";
		billDateEnd = "";
		subject = "";
		billStage = "";
		supplierId = "";
		isEffective = -1;
		isVoided = -1;
		isClosed = -1;
	}
	// ��from_json
	friend void from_json(const json& j, QueryQtrkBillListQuery& t) { // NOLINTq
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateStart);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
	}
};

#endif // !_QUERYZDRKBILLLIST_QUERY_