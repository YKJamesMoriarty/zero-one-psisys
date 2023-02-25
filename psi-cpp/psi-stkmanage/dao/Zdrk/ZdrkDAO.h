#pragma once

#ifndef _ZDRK_DAO_
#define _ZDRK_DAO_
#include "BaseDAO.h"
#include "../psi-stkmanage/domain/do/Zdrk/QueryZdrkBillDO.h"
#include "../psi-stkmanage/domain/do/Zdrk/QueryZdrkBillListDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ZdrkDAO : public BaseDAO
{
	// ͳ����������
public:
	uint64_t count(const queryZdrkBillListDO& iObj);
	// ��ҳ��ѯ����
	list<queryZdrkBillListDO> selectWithPage(const queryZdrkBillListDO& obj, uint64_t pageIndex, uint64_t pageSize);
	
	/*
	// ͨ��������ѯ����
	list<SampleDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const SampleDO& iObj);
	// �޸�����
	int update(const SampleDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	*/
};
#endif // _ZDRK_DAO_
