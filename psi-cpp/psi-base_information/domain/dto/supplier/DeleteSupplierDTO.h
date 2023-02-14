#pragma once

#ifndef _DELETE_DTO_
#define _DELETE_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class DeleteSupplierDTO
{
	// ����ƥ������
	CC_SYNTHESIZE(string, rule, Rule);
	//��ѯ�ֶ�
	CC_SYNTHESIZE(string, name, Name);
	//	�ֶβ�ѯ���������ڡ������������ڡ�����....
	CC_SYNTHESIZE(string, condition, Condition);
	//�û��������Ҫ��ѯ���ֶε�ֵ
	CC_SYNTHESIZE(string, value, Value);
	public:
	// ��JSONת������
	friend void from_json(const json& j, DeleteSupplierDTO& t); // NOLINT
	BIND_TO_JSON(DeleteSupplierDTO, rule, name, condition, value);
};

#endif // !_ADD_DTO_
