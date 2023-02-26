#pragma once
#ifndef _EXPORT_SUPPLIER_DO_
#define _EXPORT_SUPPLIER_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class ExportSupplierDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ���
	CC_SYNTHESIZE(string, code, Code);
	// ��Ӧ������
	CC_SYNTHESIZE(string, name, Name);
	// ���
	CC_SYNTHESIZE(string, shortName, ShortName);
	// ������
	CC_SYNTHESIZE(string, auxName, AuxName);
	// ��Ӧ�̷���
	CC_SYNTHESIZE(string, supplierCategory, SupplierCategory);
	// ��Ӧ�̵ȼ�
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	// ��Ӧ���Ƿ�����
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
public:
	ExportSupplierDO() {
		id = "";
		code = "";
		name = "";
		shortName = "";
		auxName = "";
		supplierCategory = "";
		supplierLevel = "";
		isEnabled = 1;
	}
};

#endif // !_EXPORT_SUPPLIER_DO_