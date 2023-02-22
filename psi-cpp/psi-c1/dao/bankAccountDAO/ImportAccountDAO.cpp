#include "stdafx.h"
#include "ImportAccountDAO.h"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/22 12:33:19
*/

uint64_t ImportAccountDAO::insert(const ImportAccountDO& iObj)
{
	string sql = "INSERT INTO `bas_bank_account` (`account_no`, `name`) VALUES (?, ?)";
	return sqlSession->executeInsert(sql, "%s%s", iObj.getCode(), iObj.getName());
}
