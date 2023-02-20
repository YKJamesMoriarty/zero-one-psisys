#pragma once
#ifndef _ADVANCED_VO_
#define _ADVANCED_VO_

#include "../../GlobalInclude.h"
//#include"../PageVO.h"

class AdvancedQueryVO 
{
	// ���
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
	//�����ܹ�˾
	CC_SYNTHESIZE(string, headOffice, HeadOffice);
	//��������
	CC_SYNTHESIZE(string, region, Region);
	//ҵ������
	CC_SYNTHESIZE(string, businessArea, BusinessArea);
	//��Ӧ�̵�ַ
	CC_SYNTHESIZE(string, supplierAddress, SupplierAddress);
	//��Ӧ����վ
	CC_SYNTHESIZE(string, supplierWebsite, SupplierWebsite);
	//��ѡ��Ӧ��
	CC_SYNTHESIZE(string, alternativeSuppliers, AlternativeSuppliers);
	//�Ƿ�����
	CC_SYNTHESIZE(string, enable, Enable);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//������
	CC_SYNTHESIZE(string, createdBy, CreatedBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, modificationTime, ModificationTime);
	//�޸���
	CC_SYNTHESIZE(string, modifiedBy, ModifiedBy);

public:
	// ��JSONת������
	BIND_TO_JSON(AdvancedQueryVO, code, name, alias, supplierCassification, supplierLevel, taxScale, headOffice,
		region, businessArea, supplierAddress, supplierWebsite, alternativeSuppliers,
		enable, remark, createdBy, modificationTime, modifiedBy);
};

#endif // !_SAMPLE_VO_

