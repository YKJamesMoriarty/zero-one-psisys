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
	int insertPrepay(const FinPayReqDO& iObj);
	//�޸ĵ���״̬
	int ChangeStatusClose(const FinPayReqDO& uObj);
	int ChangeStatusCancel(const FinPayReqDO& uObj);
	// ͨ��IDɾ������
	int deleteById(const FinPayReqDO& uObj);

};
#endif // !_PREPAYMENT_DAO_