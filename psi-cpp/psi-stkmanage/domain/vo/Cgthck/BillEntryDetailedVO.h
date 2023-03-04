#pragma once
#ifndef _BILL_DEILED_VO_
#define _BILL_DEILED_VO_

#include "../../GlobalInclude.h"


class BillEntryDetailedVO {
	//Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//����ͺ�
	CC_SYNTHESIZE(string, size, Size);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//��λ
	CC_SYNTHESIZE(string, unit, Unit);
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
	//�������
	CC_SYNTHESIZE(int, inNum, InNum);
	//�ɹ�����
	CC_SYNTHESIZE(double, buyCost, BuyCost);
	//�����
	CC_SYNTHESIZE(double, inMoney, InMoney);
	//�ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

	BIND_TO_JSON
	(
		BillEntryDetailedVO, srcNo, size, warehouseId, unit, settleQty, taxRate, price,
		discountRate, tax, settleAmt, inNum, buyCost, inMoney, invoicedQty, invoicedAmt,
		remarks, custom1, custom2
	);
};

#endif