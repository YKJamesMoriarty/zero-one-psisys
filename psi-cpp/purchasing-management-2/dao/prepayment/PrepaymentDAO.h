#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"
#include "../../domain/do/prepayment/PrepaymentEntryDO.h"

/**
 * �ɹ�Ԥ�������ݿ����ʵ��
 */
class PrepaymentDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PrepaymentDO& iObj);
	// ��ҳ��ѯ����
	list<PrepaymentDO> selectWithPage(const PrepaymentDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ��ѯָ��������ϸ��Ϣ-ͨ�����ݱ�Ų�ѯ����
	list<PrepaymentDO> selectByBill_no(const string& bill_no);
	// ָ��������ϸ��¼
	list<PrepaymentEntryDO> selectBillEntry(const PrepaymentEntryDO& obj);
	// ͨ��IDɾ������
	int deleteById(const PrepaymentDO& uObj);


};
#endif // !_PREPAYMENT_DAO_