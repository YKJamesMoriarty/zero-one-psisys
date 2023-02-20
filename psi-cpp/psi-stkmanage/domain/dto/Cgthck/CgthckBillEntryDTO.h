#pragma once
#ifndef _CGTHCK_BILL_ENTRY_DTO_
#define _CGTHCK_BILL_ENTRY_DTO_

#include "../../GlobalInclude.h"
/**
* �ɹ��˻���������ϸ
*/
class CgthckBillEntryDTO
{
	/***����***/
	// ��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	// ˰��
	CC_SYNTHESIZE(double, tax, Tax);
	// ������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// �ɹ�����
	CC_SYNTHESIZE(double, cost, Cost);
	// ���
	CC_SYNTHESIZE(uint64_t, batchNo, BatchNo);

	/***������***/
	// Դ����¼��
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(std::string, model, Model);
	// �ֿ�
	CC_SYNTHESIZE(std::string, warehouseId, WarehouseId);
	// ��λ
	CC_SYNTHESIZE(std::string, unitId, UnitId);
	// ˰��
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	// ��˰����
	CC_SYNTHESIZE(double, price, Price);
	// �ۿ���
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	// �������
	CC_SYNTHESIZE(double, qty, Qty);
	// �����
	CC_SYNTHESIZE(double, inAmt, InAmt);

	/***ѡ��***/
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(std::string, custom2, Custom2);

public:
	// ��Jsonת������
	friend void from_json(const json& j, CgthckBillEntryDTO& t)
	{
		BIND_FROM_TO_D(j, t, settleQty);
		BIND_FROM_TO_D(j, t, tax);
		BIND_FROM_TO_D(j, t, settleAmt);
		BIND_FROM_TO_D(j, t, cost);
		BIND_FROM_TO_I(j, t, batchNo);
		BIND_FROM_TO_D(j, t, taxRate);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, discountRate);
		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, inAmt);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, materialId);
		BIND_FROM_TO_NORMAL(j, t, model);
		BIND_FROM_TO_NORMAL(j, t, warehouseId);
		BIND_FROM_TO_NORMAL(j, t, unitId);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !_CGTHCK_BILL_ENTRY_DTO_
