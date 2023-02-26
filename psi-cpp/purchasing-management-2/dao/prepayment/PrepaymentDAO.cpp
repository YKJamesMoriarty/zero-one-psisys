#include "stdafx.h"
#include "PrepaymentDAO.h"
#include "PrepaymentMapper.h"
#include <sstream>

//�������뵥-fin_payment_req

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \
if (!obj.getBill_date().empty()) { \
	sql << " AND bill_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_date()); \
} \
if (obj.getAmt() != -1) { \
	sql << " AND amt=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getAmt()); \
} \


//ҳ��ͳ��
uint64_t PrepaymentDAO::count(const PrepaymentDO & iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `fin_payment_req`";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//��ѯ������Ϣ
std::list<PrepaymentDO> PrepaymentDAO::selectWithPage(const PrepaymentDO & obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM `fin_payment_req`";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PrepaymentMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PrepaymentDO, PrepaymentMapper>(sqlStr, mapper, params);
}

//��ѯָ��������ϸ��Ϣ
std::list<PrepaymentDO> PrepaymentDAO::selectByBill_no(const string& bill_no)
{
	string sql = "SELECT * FROM `fin_payment_req` WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PrepaymentMapper mapper;
	return sqlSession->executeQuery<PrepaymentDO, PrepaymentMapper>(sql, mapper, "%s", bill_no);

}


//��ѯָ��������ϸ
std::list<PrepaymentEntryDO> PrepaymentDAO::selectBillEntry(const PrepaymentEntryDO& obj)
{
	string sql = "SELECT * FROM `fin_payment_req_entry` WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PrepaymentEntryMapper mapper;
	return sqlSession->executeQuery<PrepaymentEntryDO, PrepaymentEntryMapper>(sql, mapper, "%s", obj.getEntry_bill_no());

}

// ɾ��Ԥ�����뵥
int PrepaymentDAO::deleteById(const PrepaymentDO& uObj)
{
	string sql = "DELETE FROM `fin_payment_req` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}

