#include "stdafx.h"
#include "../../GlobalInclude.h"

#ifndef _PUR_QUOT_MOD_BILL_STATUS_VO_
#define _PUR_QUOT_MOD_BILL_STATUS_VO_


//�޸ĵ���״̬
class PurQuotModBillStatusVO
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//���ݽ׶�
	CC_SYNTHESIZE(int, billStage, BillStage);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�Ƿ��ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);

public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotModBillStatusVO, billNo, billStage, isEffective, isClosed, isVoided);
};


#endif // !_PUR_QUOT_MOD_BILL_STATUS_VO_
