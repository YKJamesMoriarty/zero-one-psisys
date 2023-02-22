#pragma once
#ifndef _CGTHCK_MAPPER_
#define _CGTHCK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
using CgthckDO = StkIoDO;
using CgthckEntryDO = StkIoEntryDO;
/**
* �ɹ��˻������ֶ�ƥ��ӳ����
*/
class CgthckMapper : public Mapper<CgthckDO>
{
public:
	CgthckDO mapper(ResultSet* resultSet) const override
	{
		CgthckDO data;
		data.setBillNo(resultSet->getString(1));
		data.setBillDate(resultSet->getString(2));
		data.setSupplierId(resultSet->getString(3));
		return data;
	}
};
#endif // !_CGTHCK_MAPPER_
