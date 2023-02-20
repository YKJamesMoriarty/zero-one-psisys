#pragma once
#ifndef _WAREHOUSE_SERVICE_
#define _WAREHOUSE_SERVICE_

#include <list>
#include "../../domain/query/supplierQuery/ExportSupplierQuery.h"
#include "../../domain/do/supplierDO/ExportSupplierDO.h"

class ExportSupplierService
{
public:
	//��ѯҪ�����Ĺ�Ӧ������
	list<ExportSupplierDO> listAll(const ExportSupplierQuery& query);
};
#endif // !_WAREHOUSE_SERVICE_