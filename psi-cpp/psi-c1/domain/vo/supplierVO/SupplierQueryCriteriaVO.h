#pragma once
#ifndef _SUPPLIERQUERYCRITERIA_VO_
#define _SUPPLIERQUREYCRITERIA_VO_

#include "../../GlobalInclude.h"

/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
2023.2.13 21��00��
*/
class SupplierQueryCriteriaVO
{
	// ��ѯ�������
	CC_SYNTHESIZE(string, id, Id);
	// ��ѯ��������
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(SupplierQueryCriteriaVO, id, name);
};

#endif // _SUPPLIERQUERYCRITERIA_VO_
		