#pragma once
#ifndef _QTRK_BILL_DETAIL_DTO
#define _QTRK_BILL_DETAIL_DTO

#include "../../GlobalInclude.h"

/*
* ������ⵥ��ϸDTO
*/
class QtrkBillDetailDTO
{
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//����
	CC_SYNTHESIZE(string, material, Material);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouse, Warehouse);
	//��λ
	CC_SYNTHESIZE(string, unit, Unit);
	//�������
	CC_SYNTHESIZE(double, qty, Qty);
	// ��λ���
	CC_SYNTHESIZE(double, price, Price);
	//�����
	CC_SYNTHESIZE(double, cost, Cost);
	//��ϸ����ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	friend void from_json(const json& j,QtrkBillDetailDTO& t) {
		BIND_FROM_TO_I(j, t, entryNo);
		BIND_FROM_TO_NORMAL(j, t, material);
		BIND_FROM_TO_NORMAL(j, t, warehouse);
		BIND_FROM_TO_NORMAL(j, t, unit);
		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, cost);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !_QTRK_BILL_DETAIL_DTO