#pragma once
#ifndef _PUR_QUOT_LIST_MAPPER_H_
#define _PUR_QUOT_LIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotListDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class PurQuotListMapper : public Mapper<PurQuotListDO>
{
public:
	PurQuotListDO mapper(ResultSet* resultSet) const override
	{
		PurQuotListDO data;
		//do something
		return data;
	}
};

#endif
