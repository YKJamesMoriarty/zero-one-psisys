#pragma once

#ifndef _PUR_REQ_DAO_
#define _PUR_REQ_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pur-req/PurReqAdamDO.h"
#include "../../domain/do/pur-req/PurReqEntryAdamDO.h"
#include "../../domain/do/pur-req/PurReqDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class PurReqDAO : public BaseDAO
{
public:
	// �������(����/�ύ) ��������
	uint64_t insert(const PurReqAdamDO& obj);

	// �����ϸ����(����/�ύ) ��������
	uint64_t insertEntry(const PurReqEntryAdamDO& obj);

	// �޸�״̬����
	int update(const PurReqAdamDO& obj);

	// ͨ��billNoɾ������
	int deleteByBillNo(string billNo);

	//ͨ��BillNo������������ ��������ֻ��һ������ֻ����һ��
	list<PurReqAdamDO> selectByBillNo(const string& billNo);

	//ͨ��BillNo������ϸ������
	list<PurReqEntryAdamDO> selectEntryByBillNo(const string& billNo);


	// ͳ����������
	uint64_t count(const PurReqDO& iObj);
	// ��ҳ��ѯ����
	list<PurReqDO> selectWithPage(const PurReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ͨ����Ų鿴��ϸ��Ϣ
	list<PurReqDO> selectByNo(const string& no);

};
#endif // !_PUR_REQ_DAO_
