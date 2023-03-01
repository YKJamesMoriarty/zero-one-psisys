#include "stdafx.h"
#include "PrepaymentDAO.h"
#include "PrepaymentMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getBill_no().empty()) { \
	sql << " AND `bill_no`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBill_no()); \
} \


//ҳ��ͳ��
uint64_t PrepaymentDAO::count(const PurOrderDO & iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `pur_order`";
	SAMPLE_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//��ҳ��ѯ�ɹ����б�
list<PurOrderDO> PrepaymentDAO::selectWithPage(const PurOrderDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT * FROM `pur_order`";
	SAMPLE_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurOrderMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurOrderDO, PurOrderMapper>(sqlStr, mapper, params);
}

//��ѯָ��������ϸ��Ϣ
list<PurOrderDO> PrepaymentDAO::selectByBill_no(const PurOrderDO& obj)
{
	string sql = "SELECT * FROM `pur_order` WHERE `bill_no` LIKE CONCAT('%',?,'%')";
	PurOrderDetailMapper mapper;
	return sqlSession->executeQuery<PurOrderDO, PurOrderDetailMapper>(sql, mapper, "%s", obj.getBill_no());
}


// ɾ��Ԥ�����뵥
int PrepaymentDAO::deleteById(const PrepaymentDO& uObj)
{
	string sql = "DELETE FROM `fin_payment_req` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}

