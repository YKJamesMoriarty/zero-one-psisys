#pragma once
#ifndef __PUR_QUOT_FIND_BILL_QUERY_H_
#define __PUR_QUOT_FIND_BILL_QUERY_H_

#include "../PageQuery.h"

class PurQuotFindBillQuery : public PageQuery
{

	// ���ݱ��
	CC_SYNTHESIZE(string, receiptId, ReceiptId);
	// �������� ��ʼ
	CC_SYNTHESIZE(string, receiptTimeBegin, ReceiptTimeBegin);
	// �������� ����
	CC_SYNTHESIZE(string, receiptTimeEnd, ReceiptTimeEnd);
	// ��������
	CC_SYNTHESIZE(string, receiptTheme, ReceiptTheme);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, receiptStage, ReceiptStage);
	// ����Ч
	CC_SYNTHESIZE(string, isWork, IsWork);
	// �ѹر�
	CC_SYNTHESIZE(string, isClose, IsClose);
	// ������
	CC_SYNTHESIZE(string, isAbolish, IsAbolish);
public:
	friend void from_json(const json& j, PurQuotFindBillQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, receiptId);
		BIND_FROM_TO_NORMAL(j, t, receiptTimeBegin);
		BIND_FROM_TO_NORMAL(j, t, receiptTimeEnd);
		BIND_FROM_TO_NORMAL(j, t, receiptTheme);
		BIND_FROM_TO_NORMAL(j, t, receiptStage);
		BIND_FROM_TO_NORMAL(j, t, isWork);
		BIND_FROM_TO_NORMAL(j, t, isClose);
		BIND_FROM_TO_NORMAL(j, t, isAbolish);
	}
};

#endif
