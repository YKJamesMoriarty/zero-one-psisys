#pragma once
#ifndef _IMPORT_SUPPLIER_DO_
#define _IMPORT_SUPPLIER_DO_
#include "../DoInclude.h"

class ImportSupplierDO
{
	// ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���
	CC_SYNTHESIZE(string, code, Code);
	// ��Ӧ������
	CC_SYNTHESIZE(string, name, Name);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, shortName, ShortName);
	// ��Ӧ��������
	CC_SYNTHESIZE(string, auxName, AuxName);
	// ��Ӧ�̷���
	CC_SYNTHESIZE(string, supplierCategory, SupplierCategory);
	// ��Ӧ�̵ȼ�
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	// ��Ӧ���Ƿ�����
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
public:
	ImportSupplierDO() {
		id = 0;
		code = "";
		name = "";
		shortName = "";
		auxName = "";
		supplierCategory = "";
		supplierLevel = "";
		isEnabled = 1;
	}
};
#endif // !_IMPORT_SUPPLIER_DO_
