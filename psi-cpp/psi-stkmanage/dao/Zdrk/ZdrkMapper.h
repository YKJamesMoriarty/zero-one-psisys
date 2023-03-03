#pragma once

#ifndef _ZDRK_MAPPER_
#define _ZDRK_MAPPER_

#include "Mapper.h"
#include "../psi-stkmanage/domain/do/Zdrk/QueryZdrkBillDO.h" // ��ѯ��ϸ������Ϣ
#include "../psi-stkmanage/domain/do/Zdrk/QueryZdrkBillListDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class SampleMapper : public Mapper<queryZdrkBillDO>
{
public:
	queryZdrkBillDO mapper(ResultSet* resultSet) const override
	{
		queryZdrkBillDO data;
		/*data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));*/
		return data;
	}
};

#endif // !_ZDRK_MAPPER_
