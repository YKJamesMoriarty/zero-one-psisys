#pragma once
#ifndef _EXPORT_SUPPLIER_DAO_
#define _EXPORT_SUPPLIER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/supplier/ExportSupplierDO.h"

class ExportSupplierDAO : public BaseDAO
{
public:
	// ��ѯ��Ӧ��
	list<ExportSupplierDO> selectSupplier(const ExportSupplierDO& obj);
};
#endif // !_EXPORT_SUPPLIER_DAO_