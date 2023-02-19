#pragma once

#ifndef _QueryQtrkBillList_VO_
#define _QueryQtrkBillList_VO_

#include "../../GlobalInclude.h"

/**
 * ��ѯ�����б���ʾ����
 */
class QueryQtrkBillListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, id, Id);
	// ��������-��ʼ
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	// ��������-����
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(uint64_t, isEffective, IsEffective);
	// �Ƿ�ر�
	CC_SYNTHESIZE(uint64_t, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(uint64_t, isVoided, IsVoided);
public:
	QueryQtrkBillListVO()
	{
		id ="123";
		billDateStart = "2023 - 2 - 17";
		billDateEnd = "2023 - 2 - 18";
		subject = "sgrg";
		supplierId = "wangwu";
		billStage = "ing";
		isEffective = 0;
		isClosed = 0;
		isVoided = 0;
	}
	// ��JSONת������
	friend void from_json(const json& j, QueryQtrkBillListVO& t); // NOLINT
	BIND_TO_JSON(QueryQtrkBillListVO, id, billDateStart, billDateEnd, subject,supplierId, billStage, isEffective, isClosed, isVoided);
		
};

#endif // !_QueryQtrkBillList_VO_