#pragma once

#ifndef _ENTRYPURINQUIRY_VO_
#define _ENTRYPURINQUIRY_VO_
#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� �ɹ�ѯ�۵���ϸ�б����ɹ����뵥��Ϣ
 */


//�ɹ�ѯ�۵���ϸ���ɹ����뵥
class EntryPurInquiryVO
{
	//Դ������
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	//Դ����¼��
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	//����
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);


	//����ͺţ������ӿڣ�


	//��λ
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	//����
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	//˰��%
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//�ο���˰����
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	//�ο���˰���
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);
	//��ע
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	//�Զ���1
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	//�Զ���2
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);

public:
	// ��JSONת������
	BIND_TO_JSON(EntryPurInquiryVO, purReqSrcBillType, purReqSrcEntryNo, purReqMaterialId, purReqUnitId,
					purReqQty, purReqTaxRate, purReqPrice, purReqAmt, purReqRemark, purReqCustom1, purReqCustom2);
};


#endif // !_ENTRYPURINQUIRY_VO_
