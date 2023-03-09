#pragma once

#ifndef _PYRK_BILL_ENTRY_VO_
#define _PYRK_BILL_ENTRY_VO_

#include "../../GlobalInclude.h"

/**
 * ������ϸ
 */
class PyrkBillEntryVO
{
	//���κ�
	CC_SYNTHESIZE(string, batchNo, BatchNo);
	//���ݺ�
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�ɱ�
	CC_SYNTHESIZE(double, cost, Cost);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�ۿ���
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//������óɱ�
	CC_SYNTHESIZE(double, expense, Expense);
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//�ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//����
	CC_SYNTHESIZE(string, mid, Mid);
	//��˰����
	CC_SYNTHESIZE(double, price, Price);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�������˰�ϼƣ�
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//Դ��id���ɹ�������
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ�����ͣ��ɹ�������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ����¼id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//���뷽��
	CC_SYNTHESIZE(string, stockIoDirection, StockIoDirection);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//�Ƕ�����+/-
	CC_SYNTHESIZE(double, swellQty, SwellQty);
	//˰��
	CC_SYNTHESIZE(double, tax, Tax);
	//˰��%
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//������λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	//�汾
	CC_SYNTHESIZE(string, version, Version);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
public:
	PyrkBillEntryVO() {
		batchNo = "";
		billNo = "";
		cost = -1;
		custom1 = "";
		custom2 = "";
		discountRate = -1;
		entryNo = -1;
		expense = -1;
		id = "";
		invoicedAmt = -1;
		invoicedQty = -1;
		materialId = "";
		mid = "";
		price = -1;
		qty = -1;
		remark = "";
		settleAmt = -1;
		settleQty = -1;
		srcBillId = "";
		srcEntryId = "";
		srcNo = "";
		stockIoDirection = "";
		supplierId = "";
		swellQty = -1;;
		tax = -1;
		taxRate = -1;
		unitId = "";
		version = "";
		warehouseId = "";

	}
	// ��JSONת������
	BIND_TO_JSON(PyrkBillEntryVO, batchNo, billNo, cost, custom1, custom2, discountRate, entryNo, expense, id, invoicedAmt, invoicedQty,
		materialId, mid, price, qty, remark, settleAmt, settleQty, srcBillId, srcBillType, srcEntryId, srcNo, stockIoDirection, supplierId, swellQty, tax,
		taxRate, unitId, version, warehouseId);
};

#endif // !_CGRK_BILL_Entry_VO_
