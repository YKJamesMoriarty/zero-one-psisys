#pragma once
#ifndef _DETAIL_DTO_
#define _DETAIL_DTO_

#include "../../GlobalInclude.h"

/*
* ������ϸDTO
*/
class DetailDTO {
	// # (��¼��)
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	// ����
	CC_SYNTHESIZE(string, material, Material);
	// �ֿ�
	CC_SYNTHESIZE(string, warehouse, Warehouse);
	// ��λ
	CC_SYNTHESIZE(string, unit, Unit);
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