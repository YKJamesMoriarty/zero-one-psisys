#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"

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
	// ���Ԥ�����뵥����
	uint64_t insertPrepay(const PrepaymentDO& iObj);
	// �޸�Ԥ�����뵥����
	int updatePrepay(const PrepaymentDO& uObj);
	
	// �޸ĵ���״̬(�ر�/���ر�/����)
	// �����ˣ�Andrew
	int updateStatusClose(const PrepaymentDO& uObj);
	int updateStatusCancel(const PrepaymentDO& uObj);
	
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	// ���浼������
	uint64_t insertInfo(const PrepaymentDO& iObj);
	// ��������

};
#endif // !_PREPAYMENT_DAO_