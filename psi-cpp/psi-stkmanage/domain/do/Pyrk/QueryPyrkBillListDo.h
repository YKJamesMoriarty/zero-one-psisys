#pragma once
#ifndef _Q_P_B_L_DO
#define _Q_P_B_L_DO

#include "../../GlobalInclude.h"
/*
* ���ڵ����б��ѯ��������װ��
*/
class QueryPyrkBillListDo {
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
};
#endif
