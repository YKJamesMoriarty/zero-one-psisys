/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ���Ʊ��ʽ
 */

#pragma once
#ifndef _INVOICEMETHOD_MAPPER_
#define _INVOICEMETHOD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/publicInterfaceDO/InvoiceMethodDo.h"

class InvoiceMethodMapper : public Mapper<InvoiceMethodDO>
{
public:
	InvoiceMethodDO mapper(ResultSet* resultSet) const override
	{
		InvoiceMethodDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_INVOICEMETHOD_MAPPER_