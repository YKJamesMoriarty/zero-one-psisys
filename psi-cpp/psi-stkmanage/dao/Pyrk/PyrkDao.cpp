#include "stdafx.h"
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