#include "stdafx.h"
#include "PyrkDAO.h"
#include <sstream>
#include "../../dao/Cgrk/StkIoMapper.h"
#include "../../dao/Cgrk/StkIoEntryMapper.h"
#include "../../dao/StringMapper.h"

// �������������꣬����UPDATE stk_io �������������ظ�����
#define UPDATE_STKIO_TEARM_PARSE(obj, sql) \
if (!obj.getHandler().empty()) { \
    sql << " ,`handler`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getHandler()); \
} \
if (!obj.getBillStage().empty()) { \
    sql << " ,`bill_stage`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getBillStage()); \
} \
if (!obj.getApprover().empty()) { \
    sql << " ,`approver`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprover()); \
} \
if (!obj.getApprovalResultType().empty()) { \
    sql << " ,`approval_result_type`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprovalResultType()); \
} \
if (!obj.getApprovalRemark().empty()) { \
    sql << " ,`approval_remark`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getApprovalRemark()); \
} \
if (obj.getIsEffective() != -1) { \
    sql << " ,`is_effective`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsEffective()); \
} \
if (!obj.getEffectiveTime().empty()) { \
    sql << " ,`effective_time`=?"; \
    SQLPARAMS_PUSH(params, "s", string, obj.getEffectiveTime()); \
} \
if (obj.getIsClosed() != -1) { \
    sql << " ,`is_closed`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
} \
sql << " WHERE `bill_no`=?"; \
SQLPARAMS_PUSH(params, "s", string, iObj.getBillNo());

// �������������꣬����UPDATE stk_io ״̬�������������ظ�����
#define UPDATE_STKIO_STATE_TEARM_PARSE(obj, sql) \
sql << "UPDATE `stk_io` SET `update_by`=?,`update_time`=?"; \
SqlParams params; \
SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateBy()); \
SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateTime()); \
if (obj.getIsClosed() != -1) { \
    sql << " ,`is_closed`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
} \
if (obj.getIsVoided() != -1) { \
    sql << " ,`is_voided`=?"; \
    SQLPARAMS_PUSH(params, "i", int, obj.getIsVoided()); \
} \
sql << " WHERE `bill_no`=?"; \
SQLPARAMS_PUSH(params, "s", string, iObj.getBillNo());

//�����
#define BILL_LIST_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1 AND LEFT(bill_no,4)='PYRK' "; \
if (!obj.getBillNo().empty()) { \
	sql << " AND bill_no=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillNo()); \
} \
if ((!obj.getBillDateStart().empty())&&(!obj.getBillDateEnd().empty())) { \
	sql << " AND DATE(bill_date) BETWEEN ? "; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillDateStart()); \
	sql << "AND ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillDateEnd()); \
} \
if (!obj.getSubject().empty()) { \
	sql << " AND subject=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSubject()); \
} \
if (!obj.getSupplierId().empty()) { \
	sql << " AND supplier_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSupplierId()); \
} \
if (!obj.getBillStage().empty()) { \
	sql << " AND bill_stage=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBillStage()); \
} \
if (obj.getIsEffective() != -1) { \
	sql << " AND is_effective=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIsEffective()); \
} \
if (obj.getIsVoided() != -1) { \
	sql << " AND is_voided=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIsVoided()); \
} \
if (obj.getIsClosed() != -1) { \
	sql << " AND is_closed=?"; \
	SQLPARAMS_PUSH(params, "i", int, obj.getIsClosed()); \
}


int PyrkDAO::insert(const StkIoDO& iObj)
{
    string sql = "INSERT INTO `stk_io` (`id`,`bill_no`,`bill_date`,`subject`,`stock_io_type`, `handler`,`cost`,`remark`,`bill_stage`,`attachment`,`sys_org_code`,`create_by`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%d%s%s%s%s%s%s",
        iObj.getId(), iObj.getBillNo(), iObj.getBillDate(), iObj.getSubject(),iObj.getStockIoType(),iObj.getHandler(),iObj.getCost(),iObj.getRemark(),iObj.getBillStage(), iObj.getAttachment(),iObj.getSysOrgCode(), iObj.getCreateBy(), iObj.getCreateTime());
}

int PyrkDAO::insert(const StkIoEntryDO& iObj)
{
    string sql = "INSERT INTO `stk_io_entry` (`id`,`mid`,`bill_no`,`entry_no`,`material_id`,`batch_no`,`warehouse_id`,`stock_io_direction`,`unit_id`,`qty`,`cost`,`remark`,`custom1`,`custom2`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%d%d%s%s%s",
        iObj.getId(),iObj.getMid(),iObj.getBillNo(),iObj.getEntryNo(), iObj.getMaterialId(), iObj.getBatchNo(), iObj.getWarehouseId(), iObj.getStockIoDirection(), iObj.getUnitId(), iObj.getQty(), iObj.getCost(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2());
}

int PyrkDAO::updateApproval(const StkIoDO& iObj)
{
    stringstream sql;
    sql << "UPDATE `stk_io` SET `update_by`=?,`update_time`=?";
    SqlParams params;
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateBy());
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateTime());
    // ��������
    UPDATE_STKIO_TEARM_PARSE(iObj, sql);
    return sqlSession->executeUpdate(sql.str(), params);
}

int PyrkDAO::update(const StkIoDO& iObj)
{
    stringstream sql;
    sql << "UPDATE `stk_io` SET `update_by`=?,`update_time`=?,`bill_date`=?,`subject`=?,`attachment`=?,`remark`=?"; 
    SqlParams params; 
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateBy()); 
    SQLPARAMS_PUSH(params, "s", string, iObj.getUpdateTime()); 
    SQLPARAMS_PUSH(params, "s", string, iObj.getBillDate()); 
    SQLPARAMS_PUSH(params, "s", string, iObj.getSubject()); 
    SQLPARAMS_PUSH(params, "s", string, iObj.getAttachment()); 
    SQLPARAMS_PUSH(params, "s", string, iObj.getRemark()); 
    // ��������
    UPDATE_STKIO_TEARM_PARSE(iObj, sql);
    return sqlSession->executeUpdate(sql.str(), params);
}

int PyrkDAO::updateState(const StkIoDO& iObj)
{
    stringstream sql;
    // ��������
    UPDATE_STKIO_STATE_TEARM_PARSE(iObj, sql);
    return sqlSession->executeUpdate(sql.str(), params);
}

int PyrkDAO::update(const StkIoEntryDO& iObj)
{
    string sql = "UPDATE `stk_io_entry` SET `material_id`=?,`warehouse_id`=?,`unit_id`=?,`qty`=?,`cost`=?,`remark`=?,`custom1`=?,`custom2`=? WHERE `bill_no`=? AND `entry_no`=?";
    return sqlSession->executeUpdate(sql,"%s%s%s%d%d%s%s%s%s%i", iObj.getMaterialId(), iObj.getWarehouseId(), iObj.getUnitId(), iObj.getQty(), iObj.getCost(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2(), iObj.getBillNo(), iObj.getEntryNo());
}

int PyrkDAO::deleteBillById(const string& billNo)
{
    string sql = "DELETE FROM `stk_io` WHERE `bill_no`=?";
    return sqlSession->executeUpdate(sql, "%s", billNo);
}

int PyrkDAO::deleteDetailById(const string& billNo, const int& entryNo)
{
    string sql = "DELETE FROM `stk_io_entry` WHERE `bill_no`=? AND `entry_no`=?";
    return sqlSession->executeUpdate(sql, "%s%i", billNo, entryNo);
}

int PyrkDAO::deleteDetailById(const string& billNo)
{
    string sql = "DELETE FROM `stk_io_entry` WHERE `bill_no`=?";
    return sqlSession->executeUpdate(sql, "%s", billNo);
}

//��ѯ�����б�
std::list<StkIoDO> PyrkDAO::selectBillList(const QueryPyrkBillListQuery query)
{
	stringstream sql;
	sql << "SELECT * FROM stk_io";
	BILL_LIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query.getPageIndex() - 1) * query.getPageSize()) << "," << query.getPageSize();
	StkIoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<StkIoDO, StkIoMapper>(sqlStr, mapper, params);
}

//��ѯ���������б���Ϣ
list<StkIoDO> PyrkDAO::selectBillListByBillNo(string BillNo)
{
	stringstream sql;
	sql << "SELECT * FROM stk_io ";
	SqlParams params;
	if (BillNo != "")
	{
		sql << "WHERE bill_no=?";
		SQLPARAMS_PUSH(params, "s", std::string, BillNo);
	}
	StkIoMapper mapper;
	string sqlStr = sql.str();
	return  sqlSession->executeQuery<StkIoDO, StkIoMapper>(sqlStr, mapper, params);

}

//��ѯ������ϸ��Ϣ����¼��Ϣ��
list<StkIoEntryDO> PyrkDAO::selectBillDetails(string BillNo)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT * FROM stk_io_entry WHERE bill_no =? ";
	SQLPARAMS_PUSH(params, "s", std::string, BillNo);
	string sqlStr = sql.str();
	StkIoEntryMapper mapper;
	return  sqlSession->executeQuery<StkIoEntryDO, StkIoEntryMapper>(sqlStr, mapper, params);

}

////�������������꣬�����ظ�����
////#define SAMPLE_TERAM_PARSE(obj, sql) \
//
//uint64_t PyrkDao::count(const QueryPyrkBillListDo& Obj) {
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM sample";//��Ҫ������飨���޸ģ�
//
//	SqlParams params;
//	sql << "WHERE 1=1";
//	if (!Obj.getId().empty()) {
//			sql << " AND `name`=?"; 
//			params.push_back(SqlParam(__PARAM_KEY__, std::make_shared<__VAL_TYPE__>(__VAL_VAL__)))
//	} 
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}
