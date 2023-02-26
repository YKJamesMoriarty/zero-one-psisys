#pragma once
#ifndef _PAYMENT_DAO_
#define _PAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/FinPayReq/FinPayReqDO.h"

/**
 * �ɹ�Ԥ�������ݿ����ʵ��
 */
class PaymentDAO : public BaseDAO
{
public:
	// ���Ԥ�����뵥����
	uint64_t  insertPayment(const FinPayReqDO& Obj);
	//�޸ĵ���״̬
	int ChangeStatusClose(const FinPayReqDO& uObj);
	int ChangeStatusCancel(const FinPayReqDO& uObj);
	// ͨ��IDɾ������
	int deleteById(const FinPayReqDO& uObj);

};
#endif // !_PREPAYMENT_DAO_