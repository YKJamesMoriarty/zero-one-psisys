#pragma once
#ifndef _EXPORT_SUPPLIER_DO_
#define _EXPORT_SUPPLIER_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class ExportSupplierDO
{
	// ���
	CC_SYNTHESIZE(string, code, Code);
	// ��Ӧ������
	CC_SYNTHESIZE(string, name, Name);
public:
	ExportSupplierDO() {
		code = "1";
		name = "1";
	}
};

#endif // !_EXPORT_SUPPLIER_DO_