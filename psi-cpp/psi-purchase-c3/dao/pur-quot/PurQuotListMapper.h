#pragma once
#ifndef _PUR_QUOT_LIST_MAPPER_H_
#define _PUR_QUOT_LIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class PurQuotListMapper : public Mapper<PurQuotEntryDO>
{
public:
	PurQuotEntryDO mapper(ResultSet* resultSet) const override
	{
		PurQuotEntryDO data;
		data.setSrc_no(resultSet->getString(1));
		data.setMaterial_id(resultSet->getString(2));
		data.setUnit_id(resultSet->getString(3));
		data.setQty(resultSet->getDouble(4));
		data.setTax_rate(resultSet->getDouble(5));
		data.setPrice(resultSet->getDouble(6));
		data.setDiscount_rate(resultSet->getDouble(7));
		data.setAmt(resultSet->getDouble(8));
		data.setRemark(resultSet->getString(9));
		data.setCustom1(resultSet->getString(10));
		data.setCustom2(resultSet->getString(11));
		return data;
	}
};

#endif
