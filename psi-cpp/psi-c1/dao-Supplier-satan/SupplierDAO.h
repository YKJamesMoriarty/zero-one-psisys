#pragma once
#pragma once
/*
 @Author: Satan
 @Date: 2023/2/17
*/
#ifndef _SUPPLIER_DAO_
#define _SUPPLIER_DAO_
#include "BaseDAO.h"
#include "../psi-c1/domain/do/SupplierDO-satan/SupplierDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SupplierDAO : public BaseDAO
{
public:
	// �߼���ѯ-��ҳ��ѯ
	list<SupplierDO> AdvancedSelectWithPage(const SupplierDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ��ѯָ����Ӧ��
	list<SupplierDO> SpecifiedSelect(const uint64_t& code);
	// ��������
	uint64_t SupplierInsert(const SupplierDO& iObj);
	// �޸�����
	int SupplierUpdateById(const SupplierDO& uObj);
	// ͨ��IDɾ������
	int SupplierDeleteById(uint64_t id);
};
#endif // !_SUPPLIER_DAO_

