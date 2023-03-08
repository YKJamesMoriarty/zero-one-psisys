#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurQuot/PurQuotDO.h"

/**
 * �ɹ�Ԥ�������ݿ����ʵ��
 */
class PurQuotDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PurQuotDO& iObj);
	// ��ҳ��ѯ����
	list<PurQuotDO> selectWithPage(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ��ѯָ��������ϸ��Ϣ-ͨ�����ݱ�Ų�ѯ����
	list<PurQuotDO> selectByBill_no(const string& bill_no);


	// ���Ԥ�����뵥����
	uint64_t insertPurQuot(const PurQuotDO& iObj);
	//�޸ĵ���״̬
	int updateStatus(const PurQuotDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);

};
#endif // !_PREPAYMENT_DAO_