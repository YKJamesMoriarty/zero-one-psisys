#pragma once
#ifndef _ADVANCED_VO_
#define _ADVANCED_VO_

#include "../../GlobalInclude.h"
#include"../PageVO.h"

class AdvancedQueryVO 
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
	BIND_TO_JSON(AdvancedQueryVO, code, name, alias, supplierCassification, 
		supplierLevel, taxScale, alternativeSuppliers, enable, remark);
};

#endif // !_SAMPLE_VO_

