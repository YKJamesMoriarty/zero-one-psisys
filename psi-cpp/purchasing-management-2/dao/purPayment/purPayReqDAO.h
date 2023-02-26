#pragma once

#ifndef _PUR_PAY_REQ_DAO_
#define _PUR_PAY_REQ_DAO_
#include "BaseDAO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentBillReqDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentEntryDetaillDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class PurPayReqDAO : public BaseDAO
{
public:
	// �������(����/�ύ) ��������
	uint64_t insert(const FinPaymentBillReqDO& obj);

	// �����ϸ����(����/�ύ) ��������
	uint64_t insertEntry(const FinPaymentEntryDetaillDO& obj);

	//ͨ��BillNo������������ ��������ֻ��һ������ֻ����һ��
	list<FinPaymentBillReqDO> selectByBillNo(const string& billNo);

	//ͨ��BillNo������ϸ������
	list<FinPaymentEntryDetaillDO> selectEntryByBillNo(const string& billNo);

	// ͳ����������
	uint64_t count(const FinPaymentReqDO& iObj);
	// ��ҳ��ѯ����
	list<FinPaymentReqDO> selectWithPage(const FinPaymentReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ͨ����Ų鿴��ϸ��Ϣ
	list<FinPaymentReqDO> selectBillNo(const string& billNo);

};
#endif // _PUR_PAY_REQ_DAO_