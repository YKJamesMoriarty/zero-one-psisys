#pragma once

#ifndef _PUR_COMPARE_QUERY_
#define _PUR_COMPARE_QUERY_

#include "../PageQuery.h"

/**
 *  �ȼ۵��б��ѯ����
 */
class PurComFindBillQuery : public PageQuery
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
	friend void from_json(const json& j, PurComFindBillQuery& t) { // NOLINT
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
 *  ָ���ıȼ۵���ϸ��Ϣ/���۵��б��ѯ����
 */
class PurComFindDetailBillQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);	
public:
	// ��from_json
	friend void from_json(const json& j, PurComFindDetailBillQuery& t) { // NOLINT		
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

/**
 *  ���۵���¼�б��ѯ����
 */
class PurComDividedListQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(std::list<std::string>, billNos, BillNos);
public:
	// ��from_json
	friend void from_json(const json& j, PurComDividedListQuery& t) { // NOLINT		
		BIND_FROM_TO_NORMAL(j, t, billNos);
	}
}; 


#endif 


