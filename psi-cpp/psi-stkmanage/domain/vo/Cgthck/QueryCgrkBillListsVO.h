#pragma once
#ifndef _QUERY_CGRK_BILL_LISTS_VO_
#define _QUERY_CGRK_BILL_LISTS_VO_

#include "../../GlobalInclude.h"
class QueryCgrkBillListsVO
{
	//��¼��
	CC_SYNTHESIZE(string, entryNo, EntryNo);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//���κ�
	CC_SYNTHESIZE(string, batchNo, BatchNo);
	//������λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	//��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//˰��%
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//��˰����
	CC_SYNTHESIZE(double, price, Price);
	//�ۿ���
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//˰��
	CC_SYNTHESIZE(double, tax, Tax);
	//�������˰�ϼƣ�
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//�ɱ�
	CC_SYNTHESIZE(double, cost, Cost);
	//�ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	BIND_TO_JSON
	(
		QueryCgrkBillListsVO, entryNo, srcNo, materialId, warehouseId, batchNo, unitId, settleQty, 
		taxRate, price, discountRate, tax, settleAmt, qty, cost, invoicedQty, invoicedAmt, remark, 
		custom1, custom2
	);
};

#endif // !_QUERY_CGRK_BILL_LISTS_VO_
