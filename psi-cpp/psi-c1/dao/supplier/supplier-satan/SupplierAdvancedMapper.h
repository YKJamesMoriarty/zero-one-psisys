#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: satan
 xxxMapper��dao�㡣
��ҳ��ѯ��Ҫ�õ�mapper
mapper�������Ƕ�DO����ģ���е��ֶ���һ��ת��(ӳ��)
Mapper.h���ֶ�˳����ݷ�ҳ��ѯʱ��ʾ���ֶε�˳����д���������Լ��������
class SupplierAdvancedMapper������ֶεģ�������������DO�ж�Ӧ�ֶε���ţ�����data.setCode(resultSet->getString(2));---��
��ΪCode��DO��������Ǵ��ϵ��µĵڶ��������������mapper���棬code����д(2)
ע�⣬�����Ų��ǿ����ݿ��ж�Ӧ�ֶ������ݿ��ֶ��е�˳�򣡣���
*/
#ifndef _SUPPLIER_MAPPER_
#define _SUPPLIER_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/supplier/SupplierDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class SupplierAdvancedMapper : public Mapper<SupplierDO>
{
public:
	SupplierDO mapper(ResultSet* resultSet) const override
	{
		SupplierDO data;
		data.setID(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setAux_Name(resultSet->getString(4));
		data.setSupplier_Category(resultSet->getString(5));
		data.setSupplier_Level(resultSet->getString(6));
		data.setTax_Scale(resultSet->getString(7));
		data.setHeadQuarters(resultSet->getString(8));
		data.setArea(resultSet->getString(9));
		data.setBiz_Area(resultSet->getString(10));
		data.setAddress(resultSet->getString(11));
		data.setWebsite(resultSet->getString(12));
		data.setAlter_Suppliers(resultSet->getString(13));
		data.setIs_Enabled(resultSet->getInt(14));
		data.setRemark(resultSet->getString(15));
		data.setCreate_By(resultSet->getString(16));
		data.setUpdate_Time(resultSet->getString(17));
		data.setUpdate_By(resultSet->getString(18));
		return data;
	}
};

#endif // !_SUPPLIER_MAPPER_