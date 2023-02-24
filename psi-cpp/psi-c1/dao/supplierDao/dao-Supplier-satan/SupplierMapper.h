#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: satan
 xxxMapper��dao�㡣
��ҳ��ѯ��Ҫ�õ�mapper
mapper�������Ƕ�DO����ģ���е��ֶ���һ��ת��(ӳ��)
Mapper.h���ֶ�˳����ݷ�ҳ��ѯʱ��ʾ���ֶε�˳����д
*/
#ifndef _SUPPLIER_MAPPER_
#define _SUPPLIER_MAPPER_

#include "Mapper.h"
#include"domain/do/SupplierDO-satan/SupplierDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class SupplierMapper : public Mapper<SupplierDO>
{
public:
	SupplierDO mapper(ResultSet* resultSet) const override
	{
		SupplierDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setAux_Name(resultSet->getString(3));
		data.setSupplier_Category(resultSet->getString(4));
		data.setSupplier_Level(resultSet->getString(5));
		data.setTax_Scale(resultSet->getString(6));
		data.setHeadQuarters(resultSet->getString(7));
		data.setBiz_Area(resultSet->getString(8));
		data.setArea(resultSet->getString(9));
		data.setAddress(resultSet->getString(10));
		data.setWebsite(resultSet->getString(11));
		data.setAlter_Suppliers(resultSet->getString(12));
		data.setIs_Enabled(resultSet->getInt64(13));
		data.setRemark(resultSet->getString(14));
		data.setCreate_By(resultSet->getString(15));
		data.setCreate_Time(resultSet->getString(16));
		data.setUpdate_Time(resultSet->getString(17));
		return data;
	}
};

#endif // !_SUPPLIER_MAPPER_