#pragma once
#ifndef _SUPPLIERCATEGORYDO_H_
#define _SUPPLIERCATEGORYDO_H_

class SupplierCategoryDO
{
	//��Ӧ������
	CC_SYNTHESIZE(std::string, name, Name);
	//��Ӧ��id
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	SupplierCategoryDO()
	{
		name = "";
		id = 0;
	}
};

#endif // _SUPPLIERCATEGORYDO_H_