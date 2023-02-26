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


//if (obj.getIs_effective() != -1) {
//	\
//		sql << " AND is_effective=?"; \
//		SQLPARAMS_PUSH(params, "i", int, obj.getIs_effective()); \
//} \
//if (!obj.getEffective_time().empty()) {
//	\
//		sql << " AND effective_time=?"; \
//		SQLPARAMS_PUSH(params, "s", std::string, obj.getEffective_time()); \
//} \
//if (obj.getIs_closed() != -1) {
//	\
//		sql << " AND is_closed=?"; \
//		SQLPARAMS_PUSH(params, "i", int, obj.getIs_closed()); \
//} \
//if (obj.getIs_voided() != -1) {
//	\
//		sql << " AND is_voided=?"; \
//		SQLPARAMS_PUSH(params, "i", int, obj.getIs_voided()); \
//} \


//ҳ��ͳ��
uint64_t PrepaymentDAO::count(const PrepaymentDO & iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_payment_req";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//��ѯ������Ϣ
std::list<PrepaymentDO> PrepaymentDAO::selectWithPage(const PrepaymentDO & obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM fin_payment_req";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PrepaymentMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PrepaymentDO, PrepaymentMapper>(sqlStr, mapper, params);
}
//��ѯָ��������ϸ��Ϣ
std::list<PrepaymentDO> PrepaymentDAO::selectByBill_no(const string& bill_no)
{
	string sql = "SELECT * FROM fin_payment_req WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PrepaymentMapper mapper;
	return sqlSession->executeQuery<PrepaymentDO, PrepaymentMapper>(sql, mapper, "%s", bill_no);
}
//����Ԥ�����뵥
uint64_t PrepaymentDAO::insertPrepay(const PrepaymentDO& iObj)
{
	string sql = "INSERT INTO `fin_payment_req` (`bill_no`, `bill_date`, `amt`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getBill_no(), iObj.getBill_date(), iObj.getAmt());
}

//�޸�Ԥ�����뵥
int PrepaymentDAO::updatePrepay(const PrepaymentDO& uObj)
{
	string sql = "UPDATE `fin_payment_req` SET `bill_no`=?, `bill_date`=?, `amt`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getBill_no(), uObj.getBill_date(), uObj.getAmt(), uObj.getId());
}


// �޸ĵ���״̬(�ر�/���ر�)
// �����ˣ�Andrew
int PrepaymentDAO::updateStatusClose(const PrepaymentDO& prepaydo)
{
	string sql = "UPDATE `fin_payment_req` SET `is_closed`=?, `update_by`=?, `update_time`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s%s%%s", prepaydo.getIs_closed(), prepaydo.getUpdate_by(), prepaydo.getUpdate_time(), prepaydo.getId());
}

// �޸ĵ���״̬(����)
// �����ˣ�Andrew
int PrepaymentDAO::updateStatusCancel(const PrepaymentDO& prepaydo)
{
	string sql = "UPDATE `fin_payment_req` SET `is_voided`=?, `update_by`=?, `update_time`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s%s%s", prepaydo.getIs_voided(), prepaydo.getUpdate_by(), prepaydo.getUpdate_time(), prepaydo.getId());
}

// ɾ��Ԥ�����뵥
int PrepaymentDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

// ���浼������
uint64_t PrepaymentDAO::insertInfo(const PrepaymentDO& iObj)
{
	string sql = "INSERT INTO `fin_payment_req` (`bill_no`, `bill_date`, `amt`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getBill_no(), iObj.getBill_date(), iObj.getAmt());
}