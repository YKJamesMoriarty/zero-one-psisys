#pragma once
#pragma once
#ifndef _QUERYDOCLIST_QUERY_
#define _QUERYDOCLIST_QUERY_

#include "../PageQuery.h"

/**
 * ��ѯ������ϸ��Ϣ
 */
class QueryDocListQuery		:public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);


public:
	// ��from_json
	friend void from_json(const json& j, QueryDocListQuery& t) { // NOLINTq
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t,isVoided);
	}
};

#endif // !_QUERYDOCLIST_QUERY_