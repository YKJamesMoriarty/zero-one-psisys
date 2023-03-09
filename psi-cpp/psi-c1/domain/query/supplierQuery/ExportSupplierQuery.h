#pragma once
#ifndef _EXPORT_SUPPLIER_QUERY_
#define _EXPORT_SUPPLIER_QUERY_
#include "../PageQuery.h"
class ExportSupplierQuery : public PageQuery
{
	//��Ӧ�̱��
	CC_SYNTHESIZE(std::string, id, Id);
	//��Ӧ�̱��
	CC_SYNTHESIZE(std::string, code, Code);
	//��Ӧ������
	CC_SYNTHESIZE(std::string, name, Name);
public:
	// ��from_json
	friend void from_json(const json& j, ExportSupplierQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, code);
		BIND_FROM_TO_NORMAL(j, t, name);
	}
};
#endif // !_EXPORT_SUPPLIER_QUERY_
