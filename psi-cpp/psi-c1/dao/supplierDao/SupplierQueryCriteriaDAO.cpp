#include "stdafx.h"
#include "SupplierQueryCriteriaDAO.h"
#include "SupplierQueryCriteriaMapper.h"
#include <sstream>

/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
*/

list<SupplierQueryCriteriaDO> SupplierQueryCriteriaDAO::selectSupplierQueryCriteria()
{
	stringstream sql;
	sql << "SELECT * FROM onl_cgform_field where cgform_head_id ='40288383830cc00c01830cc014290001'";
	string sqlStr = sql.str();
	SupplierQueryCriteriaMapper mapper;
	return sqlSession->executeQuery<SupplierQueryCriteriaDO, SupplierQueryCriteriaMapper>(sqlStr, mapper);
}
