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
	list<list<ExportSupplierDO>> listAll(const list<ExportSupplierQuery>& query);
};
#endif // !_WAREHOUSE_SERVICE_