#pragma once

#ifndef _DELETE_DTO_
#define _DELETE_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class DeleteSupplierDTO
{
	// ɾ����Ӧ����Ҫ������
	CC_SYNTHESIZE(string, code, Code);
	
public:
	// ��JSONת������
	friend void from_json(const json& j, DeleteSupplierDTO& t); // NOLINT
};

#endif // !_ADD_DTO_
