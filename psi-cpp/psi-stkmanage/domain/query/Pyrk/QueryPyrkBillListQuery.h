#pragma once
#ifndef _Q_P_B_L_QUERY_
#define _Q_P_B_L_QUERY_
/*
* ��ҳ��ѯ�����б�
*/
#include "../PageQuery.h"
class QueryPyrkBillListQuery : public PageQuery {
	// ���ݱ��
	CC_SYNTHESIZE(string, id, Id);
	// ������ʼ����
	CC_SYNTHESIZE(string, beginData, BeginData);
	// ���ݽ�������
	CC_SYNTHESIZE(string, endData, EndData);
	// ��������
	CC_SYNTHESIZE(string, theme, Theme);
	// ���ݽ׶�
	CC_SYNTHESIZE(int, stage, Stage);
	// ����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// �ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// ��from_json
	friend void from_json(const json& j, QueryPyrkBillListQuery& t);
};



#endif