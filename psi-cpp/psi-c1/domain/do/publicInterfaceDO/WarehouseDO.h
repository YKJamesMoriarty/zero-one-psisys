#pragma once
#ifndef _WAREHOUSE_DO_
#define _WAREHOUSE_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class WarehouseDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �ֿ���
	CC_SYNTHESIZE(string, name, Name);
public:
	WarehouseDO() {
		id = 0;
		name = "";
	}
};

#endif // !_WAREHOUSE_DO_