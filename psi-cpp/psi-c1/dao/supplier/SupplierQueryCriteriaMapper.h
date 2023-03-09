#ifndef _SUPPLIERQUERYCRITERIA_MAPPER_
#define _SUPPLIERQUERYCRITERIA_MAPPER_

#include "Mapper.h"
#include "../../domain/do/supplier/SupplierQueryCriteriaDO.h"

/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
*/

class SupplierQueryCriteriaMapper : public Mapper<SupplierQueryCriteriaDO>
{
public:
	SupplierQueryCriteriaDO mapper(ResultSet* resultSet) const override
	{
		SupplierQueryCriteriaDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(4));
		return data;
	}
};

#endif // !_SUPPLIERQUERYCRITERIA_MAPPER_