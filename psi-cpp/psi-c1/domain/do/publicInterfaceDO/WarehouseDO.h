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
	CC_SYNTHESIZE(string, id, Id);
	// �ֿ���
	CC_SYNTHESIZE(string, name, Name);
public:
	WarehouseDO() {
		id = "";
		name = "";
	}
};

#endif // !_WAREHOUSE_DO_