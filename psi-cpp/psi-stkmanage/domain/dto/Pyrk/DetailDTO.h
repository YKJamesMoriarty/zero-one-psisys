#pragma once
#ifndef _DETAIL_DTO_
#define _DETAIL_DTO_

#include "../../GlobalInclude.h"

class DetailDTO {
	// # (��¼��)
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	// ����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// �ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	// ��λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	// �������
	CC_SYNTHESIZE(double, qty, Qty);
	// �����
	CC_SYNTHESIZE(double, cost, Cost);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// ��JSONת������
	friend void from_json(const json& j, DetailDTO& t); // NOLINT
};

#endif // !_DETAIL_DTO_