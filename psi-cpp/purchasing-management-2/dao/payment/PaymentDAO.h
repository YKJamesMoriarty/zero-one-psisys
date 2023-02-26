#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurReq/PurReqDO.h"

/**
 * �ɹ�Ԥ�������ݿ����ʵ��
 */
class PaymentDAO : public BaseDAO
{
public:
	// ���Ԥ�����뵥����
	uint64_t insertPrepay(const PurReqDO& iObj);
	//�޸ĵ���״̬
	int ChangeStatusClose(const PurReqDO& uObj);
	int ChangeStatusCancel(const PurReqDO& uObj);
	// ͨ��IDɾ������
	int deleteById(const PurReqDO& uObj);

};
#endif // !_PREPAYMENT_DAO_