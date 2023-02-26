#pragma once

#ifndef _CGRK_DAO_
#define _CGRK_DAO_
#include "BaseDAO.h"
#include"domain/do/Cgthck/QueryCgthrkBillListDO.h"
#include"domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"
#include"list"
class CgthrkDao : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const QueryCgthrkBillListDO& Obj);
	// ��ѯ�����б�
	list<QueryCgthrkBillListReturnDO> selectCgthckBillList(const QueryCgthrkBillListDO& Obj, uint64_t pageIndex, uint64_t pageSize);
};





#endif

