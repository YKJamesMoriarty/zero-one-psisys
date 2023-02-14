#pragma once

#ifndef _ADD_DTO_
#define _ADD_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class AddSupplierDTO
{
	// ����
	CC_SYNTHESIZE(int, code, Code);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	//������
	CC_SYNTHESIZE(string, alias, Alias);
	//��Ӧ�̷���
	CC_SYNTHESIZE(string, supplierCassification, SupplierClassification);
	//��Ӧ�̵ȼ�
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	//��˰��ģ
	CC_SYNTHESIZE(string, taxScale, TaxScale);
	//��ѡ��Ӧ��
	CC_SYNTHESIZE(string, alternativeSuppliers, AlternativeSuppliers);
	//�Ƿ�����
	CC_SYNTHESIZE(string, enable, Enable);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	// ��JSONת������
	friend void from_json(const json& j, AddSupplierDTO& t); // NOLINT
	BIND_TO_JSON(AddSupplierDTO, code, name, alias, supplierCassification, supplierLevel, taxScale, alternativeSuppliers, enable, remark);
};

#endif // !_ADD_DTO_