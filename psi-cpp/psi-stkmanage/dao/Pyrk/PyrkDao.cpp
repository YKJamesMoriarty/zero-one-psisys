#include "stdafx.h"
#include "PyrkDao.h"
#include "PyrkMapper.h"
#include <sstream>
#include "FastDfsClient.h"
#include "StringMapper.h"
//#include "PyrkDAO.h"
//#include "PyrkMapper.h"
//#include <sstream>
//
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

string PyrkDao::selectOrgCodeByUsername(const string& username)
{
    string sql = "SELECT d.org_code FROM sys_depart d, sys_user u, sys_user_depart ud WHERE d.id = ud.dep_id AND u.id = ud.user_id AND u.username = ?";
    StringMapper mapper;
    return *(sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", username).begin());
}

string PyrkDao::selectBillIdByBillNo(const string& billNo)
{
    string sql = "SELECT id FROM stk_io WHERE bill_no = ?";
    StringMapper mapper;
    return *(sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", billNo).begin());
}

uint64_t PyrkDao::insert(const StkIoDO& iObj)
{
    string sql = "INSERT INTO `stk_io` (`id`,`bill_no`,`bill_date`,`subject`,`stock_io_type`, `handler`,`remark`,`bill_stage`,`attachment`,`sys_org_code`,`create_by`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s",
        iObj.getId(), iObj.getBillNo(), iObj.getBillDate(), iObj.getSubject(),iObj.getStockIoType(),iObj.getHandler(),iObj.getRemark(),iObj.getBillStage(), iObj.getAttachment(),iObj.getSysOrgCode(), iObj.getCreateBy(), iObj.getCreateTime());
}

uint64_t PyrkDao::insert(const StkIoEntryDO& iObj)
{
    string sql = "INSERT INTO `stk_io_entry` (`id`,`mid`,`bill_no`,`entry_no`,`material_id`,`batch_no`,`warehouse_id`,`stock_io_direction`,`unit_id`,`qty`,`cost`,`remark`,`custom1`,`custom2`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%d%d%s%s%s",
        iObj.getId(),iObj.getMid(),iObj.getBillNo(),atoi(iObj.getEntryNo().c_str()), iObj.getMaterialId(), iObj.getBatchNo(), iObj.getWarehouseId(), iObj.getStockIoDirection(), iObj.getUnitId(), iObj.getQty(), iObj.getCost(), iObj.getRemark(), iObj.getCustom1(), iObj.getCustom2());
}

string PyrkDao::insertFile(const string& fileName)
{
#ifdef LINUX
    // ����ͻ��˶���
    FastDfsClient client("conf/client.conf", 3);
#else
    // ����ͻ��˶���
    FastDfsClient client("192.168.235.251");
#endif
    return client.uploadFile(fileName);
}

uint64_t PyrkDao::updateApproval(const StkIoDO& iObj)
{
    return uint64_t();
}

uint64_t PyrkDao::update(const StkIoDO& iObj)
{
    return uint64_t();
}

uint64_t PyrkDao::update(const StkIoEntryDO& iObj)
{
    return uint64_t();
}
