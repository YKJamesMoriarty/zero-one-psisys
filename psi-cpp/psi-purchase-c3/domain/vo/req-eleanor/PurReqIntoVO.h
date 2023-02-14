#pragma once

#ifndef _PURREQINTO_VO_
#define _PURREQINTO_VO_

#include "../../GlobalInclude.h"

//����
class PurReqIntoVO
{
//����������Ϣ - ͬ������Ϣ
	// ��������
	CC_SYNTHESIZE(string, purReqSubject, PurReqSubject);
	// �ɹ�����	�������ӿڣ�
	CC_SYNTHESIZE(string, purReqType, PurReqType);
	// ������	�������ӿڣ�
	CC_SYNTHESIZE(string, purReqRequestDept, PurReqRequestDept);
	// ������	��ѡ���û������ӿڣ�
	CC_SYNTHESIZE(string, purReqRequester, PurReqRequester);
	// ����ʱ�� 
	CC_SYNTHESIZE(string, purReqRequestTime, PurReqRequestTime);

//��ϸ
	// Դ����¼��	
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	// ����	
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);

	// ����ͺţ������ӿڣ�

	// ������λ	
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	// ����	
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	// ˰��% 
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//�ο���˰����
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	//�ο���˰���
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);

	// ���鹩Ӧ�̣������ӿڣ�
	CC_SYNTHESIZE(string, purReqSuggestSupplierId, PurReqSuggestSupplierId);
	// ��ע	
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	// �Զ���1	
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	// �Զ���2	
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);

public:
// ��JSONת������
	BIND_TO_JSON(PurReqIntoVO, purReqSubject, purReqType, purReqRequestDept, purReqRequester, purReqRequestTime,
		purReqSrcEntryNo, purReqMaterialId, purReqUnitId, purReqQty, purReqTaxRate, purReqPrice, purReqAmt,
		purReqSuggestSupplierId, purReqRemark, purReqCustom1, purReqCustom2);

};

#endif // !_PURREQINTO_VO_