#pragma once

#ifndef _PURREQ_VO_
#define _PURREQ_VO_

#include "../../GlobalInclude.h"

//����
class PurReqExportVO
{
//�����������Ϣ
	// �ɹ�����	
	// ������	
	// ������	
	// ����ʱ��	
	// ����	
	// �ο����	
	// �Ѷ�������	
	// ��ϸ																	
	// �Ƿ���Ч	
	// ����	
	// Դ��id	
	// ��������	
	// ���ݽ׶�	
	// Դ����	
	// �Ƿ��Զ�����	
	// ��ע	
	// ����ʵ��id	
	// ������	
	// ���ݱ��	
	// �Ƿ����	
	// Դ������	
	// �Ƶ�ʱ��	
	// ��Чʱ��	
	// ������	
	// �޸���	
	// �Ƶ�����	
	// �ѹر�	
	// �����������	
	// ��������	
	// �Ƶ���	
	// �������
//��ϸ
	// ����	
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);
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
	// ���鹩Ӧ��	
	// �Ѷ�������	
	// �Զ���1	
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	// Դ����¼��	
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	// ��¼��	
	// �Զ���2	
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);
	// Դ����¼id	
	// Դ������	
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	// ��ע	
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	// ���ݱ��	
	// Դ��id
	

public:
	// ��JSONת������
		//BIND_TO_JSON();
};




//����
class PurReqIntoVO
{
//����������Ϣ - ͬ������Ϣ



public:
// ��JSONת������
	//BIND_TO_JSON();
};


#endif // !_PURREQ_VO_
