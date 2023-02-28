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

// �޸ĵ���״̬(�ر�/���ر�)
// �����ˣ�zuichu
int PaymentDAO::ChangeStatusClose(const FinPayReqDO & paydo)
{
	string sql = "UPDATE `fin_payment_req` SET `update_by`=?, `update_time`=?, `is_closed`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s", paydo.getUpdate_by(), paydo.getUpdate_time(), paydo.getIs_closed(), paydo.getId());
}

// �޸ĵ���״̬(����)
// �����ˣ�zuich 
int PaymentDAO::ChangeStatusCancel(const FinPayReqDO& paydo)
{
	string sql = "UPDATE `fin_payment_req` SET `update_by`=?, `update_time`=?, `is_voided`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s", paydo.getUpdate_by(), paydo.getUpdate_time(), paydo.getIs_voided(), paydo.getId());
}

// ɾ�����뵥
int PaymentDAO::deleteById(const FinPayReqDO& uObj)
{
	string sql = "DELETE FROM `fin_payment_req` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}

// �������(����/�ύ) �����ܱ�����
uint64_t PaymentDAO::insertPayment(const FinPayReqDO& obj)
{
	string sql = "INSERT INTO `fin_payment_req` VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? ,? ,? ,?";
	if (obj.getEffective_time() != "") {
		sql += ", '" + obj.getEffective_time() + "'";
	}
	else {
		sql += ", null";
	}
	sql += ", ?, ?, ?, ?, ? ,?";
	if (obj.getUpdate_time() != "") {
		sql += ", '" + obj.getUpdate_time() + "'";
	}
	else {
		sql += ", null";
	}
	if (obj.getVersion() != -1) {
		sql += ", " + to_string(obj.getVersion());
	}
	else {
		sql += ", null";
	}
	sql += ")";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%d%d%s%s%i%s%s%s%s%s%i%i%i%s%s%s%s",
		obj.getId(), obj.getBill_no(), obj.getBill_date(), 
		obj.getSrc_bill_type(),obj.getSrc_bill_id(), obj.getSrc_no(), 
		obj.getSubject(),obj.getIs_rubric(), obj.getPayment_type(), 
		obj.getSupplier_id(),obj.getOp_dept(), obj.getOperator(), 
		obj.getAmt(),obj.getPaid_amt(), obj.getAttachment(),
		obj.getRemark(), obj.getIs_auto(), obj.getBill_stage(),
		obj.getApprover(), obj.getBpmi_instance_id(), obj.getApproval_result_type(),
		obj.getApproval_remark(), obj.getIs_effective(),
		obj.getIs_closed(), obj.getIs_voided(), obj.getSys_org_code(),
		obj.getCreate_by(),obj.getCreate_time(), obj.getUpdate_by());
}