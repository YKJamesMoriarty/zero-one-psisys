#pragma once
#ifndef _WAREHOUSE_DAO_
#define _WAREHOUSE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/WarehouseDO.h"

class WarehouseDAO : public BaseDAO
{
public:
	// ��ѯ�ֿ�
	list<WarehouseDO> selectWarehouse();
};
#endif // !_WAREHOUSE_DAO_