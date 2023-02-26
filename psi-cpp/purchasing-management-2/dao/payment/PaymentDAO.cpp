#include "stdafx.h"
#include "PaymentDAO.h"
#include "PaymentMapper.h"
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

////����Ԥ�����뵥
//uint64_t PrepaymentDAO::insertPrepay(const PrepaymentDO& iObj)
//{
//	string sql = "INSERT INTO `fin_payment_req` (`bill_no`, `bill_date`, `amt`) VALUES (?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getBill_no(), iObj.getBill_date(), iObj.getAmt());
//}

//�޸ĵ���״̬
int PaymentDAO::ChangeStatusClose(const PurReqDO& uObj)
{
	string sql = "UPDATE `pur_req` SET `is_closed`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s", uObj.getIs_closed(), uObj.getId());
}

int PaymentDAO::ChangeStatusCancel(const PurReqDO& uObj)
{
	string sql = "UPDATE `pur_req` SET `is_voided`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i%s", uObj.getIs_voided(), uObj.getId());
}

// ɾ��Ԥ�����뵥
int PaymentDAO::deleteById(const PurReqDO& uObj)
{
	string sql = "DELETE FROM `pur_req` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}