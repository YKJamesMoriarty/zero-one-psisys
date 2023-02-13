#pragma once

#ifndef _PUR_COMPARE_QUERY_
#define _PUR_COMPARE_QUERY_

#include "../PageQuery.h"

/**
 *  �ȼ۵��б��ѯ����
 */
class PurCompareQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������_��ʼ
	CC_SYNTHESIZE(string, billDateBegin, BillDateBegin);
	// ��������_����
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// ����Ч
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// �ѹر�
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(string, isVoided, IsVoided);
public:
	// ��from_json
	friend void from_json(const json& j, PurCompareQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateBegin);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, isEffective);
		BIND_FROM_TO_NORMAL(j, t, isClosed);
		BIND_FROM_TO_NORMAL(j, t, isVoided);
	}
};

/**
 *  ָ���ıȼ۵���ϸ��Ϣ��ѯ����
 */
class AssignPurCompareQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);	
public:
	// ��from_json
	friend void from_json(const json& j, AssignPurCompareQuery& t) { // NOLINT		
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};
#endif 


