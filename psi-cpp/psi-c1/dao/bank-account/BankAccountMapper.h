#pragma once
/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * �ӿڣ������˻���ͨ��ѯ
 */

#ifndef _BANKACCOUNT_MAPPER_
#define _BANKACCOUNT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/bank-account/BankAccountDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class BankAccountMapper : public Mapper<BankAccountDO>
{
public:
	BankAccountDO mapper(ResultSet* resultSet) const override
	{
		BankAccountDO data;
		//data.setId(resultSet->getString(1));
		data.setAccountNo(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setCurrency_dictText(resultSet->getString(3));
		data.setBankNo(resultSet->getString(4));
		data.setBankAddress(resultSet->getString(5));
		data.setManager_dictText(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));
		data.setIsEnabled_dictText(resultSet->getInt(8));
		data.setCreateBy_dictText(resultSet->getString(9));
		data.setCreateTime(resultSet->getString(10));
		data.setUpdateBy(resultSet->getString(11));
		data.setUpdateTime(resultSet->getString(12));
		return data;
	}
};

#endif // !_BANKACCOUNT_MAPPER_