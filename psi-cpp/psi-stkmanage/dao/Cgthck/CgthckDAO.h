#pragma once
#ifndef _CGTHCK_DAO_
#define _CGTHCK_DAO_

#include "BaseDAO.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
#include "../../service/Cgthck/CgthckMapper.h"

constexpr auto DATABASE = "stk_io";
using CgthckDO = CgthckBillListDO;

class CgthckDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CgthckDO& iobj);
	// ��ҳ��ѯ����
	list<CgthckDO> selectById(const string& id);
	// ��������
	uint64_t insert(const CgthckDO& iobj);
	// �޸�����
	int update(const CgthckDO& iobj);
	// ɾ��ͨ����������
	int deleteById(const CgthckDO& iobj);
};

#endif // !_CGTHCK_DAO_