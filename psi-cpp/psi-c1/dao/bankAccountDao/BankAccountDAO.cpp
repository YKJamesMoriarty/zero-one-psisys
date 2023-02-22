/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * �ӿڣ������˻���ͨ��ѯ
 */

#include "stdafx.h"
#include "BankAccountDAO.h"
#include "BankAccountMapper.h"
#include <sstream>


 //�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getSex().empty()) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSex()); \
} \
if (obj.getAge() != -1) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getAge()); \
}

uint64_t BankAccountDAO::count()
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_bank_account";

	string sqlStr = sql.str();

	return sqlSession->executeQueryNumerical(sqlStr);
}

std::list<BankAccountDO> BankAccountDAO::selectWithPage(uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT account_no,name,currency,bank_no,bank_address,manager,remark,is_enabled,create_by,create_time,update_by,update_time FROM bas_bank_account";
	//SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	BankAccountMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BankAccountDO, BankAccountMapper>(sqlStr, mapper);
}