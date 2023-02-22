#pragma once
#ifndef _QUERY_CGRK_BILL_LISTS_VO_
#define _QUERY_CGRK_BILL_LISTS_VO_

#include "../../GlobalInclude.h"
class QueryCgrkBillListsVO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// �������
	CC_SYNTHESIZE(std::string, stockIoType, StockIoType);
	// Դ����
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// ҵ����
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// ҵ��Ա
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// ������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// �ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	// �ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	// ��Ʊ����
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
	// ���Ƕ�
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// �ѹر�
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
public:
	BIND_TO_JSON
	(
		QueryCgrkBillListsVO, billNo, billDate, subject, stockIoType, srcNo, supplierId, 
		opDept, srcOperator, settleAmt, settledAmt, invoicedAmt, invoiceType, hasSwell, isClosed
	);
};

#endif // !_QUERY_CGRK_BILL_LISTS_VO_
