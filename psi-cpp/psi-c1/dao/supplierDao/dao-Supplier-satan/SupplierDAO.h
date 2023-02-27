#pragma once
#pragma once
/*
 @Author: Satan
 @Date: 2023/2/17
*/
#ifndef _SUPPLIER_DAO_
#define _SUPPLIER_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/SupplierDO-satan/SupplierDO.h"
#include "../../../domain/query/supplierQuery/AdvancedQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class SupplierDAO : public BaseDAO
{
public:
	// ͳ������������������service��д��ҳ��ѯ��ʱ����Ҫ�õ�
	uint64_t count(const  AdvancedQuery condition);
	// �߼���ѯ-��ҳ��ѯ
	list<SupplierDO> AdvancedSelectWithPage(uint64_t pageIndex, uint64_t pageSize, const AdvancedQuery &condition);
	// ��ѯָ����Ӧ�̡������Ǹ���id
	SupplierDO SpecifiedSelect(const string& id);//ʵ������û�б�Ҫʹ��list����Ϊͬһ��codeֻ�ܲ��һ����Ӧ�̣������㿴DAO.cpp�ͷ���������Ҫ�ĺ����ķ���ֵ����list���͵�û�취
	// ��������
	uint64_t SupplierInsert(const SupplierDO& iObj);
	// �޸�����
	int SupplierUpdateByCode(const SupplierDO& uObj);
	// ͨ�������ɾ�����ݡ������Ǹ���id
	int SupplierDeleteByCode(string code);
};
#endif // !_SUPPLIER_DAO_

