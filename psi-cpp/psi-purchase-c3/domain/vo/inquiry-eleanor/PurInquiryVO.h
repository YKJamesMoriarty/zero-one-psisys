#pragma once

#ifndef _PURINQUIRY_VO_
#define _PURINQUIRY_VO_

#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� �ɹ�ѯ�۵��б�ָ���ɹ�ѯ�۵��б�ѯ�۵���ϸ���ɹ����뵥��
 */


//�ɹ�ѯ�۵��б� - ������Ϣ
class PurInquiryFindBillVO
{
	//���ݱ��  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // varchar
	//��������
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);  // varchar
	//�������� 
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);  // varchar
	//Դ����
	CC_SYNTHESIZE(string, purInquirySrcBillId, PurInquirySrcBillId);  // varchar
	//��������
	CC_SYNTHESIZE(string, purInquiryDeliveryTime, purInquiryDeliveryTime);  //datatime
	//����
	CC_SYNTHESIZE(double, purInquiryQty, purInquiryQty);  // decimal
	//�ο����
	CC_SYNTHESIZE(double, purInquiryAmt, purInquiryAmt);  // decimal
	//���۵���
	CC_SYNTHESIZE(int, purInquiryQuotCount, purInquiryQuotCount);   // int


	//���ݽ׶Σ������ӿڣ�


	//�Ƿ���Ч
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);  
	//�Ƿ�ر�
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);  
	//�Ƿ�����
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided); 
	//�����ص�
	CC_SYNTHESIZE(string, purInquiryDeliveryPlace, PurInquiryDeliveryPlace);   
	//��ϵ��
	CC_SYNTHESIZE(string, purInquiryContact, PurInquiryContact);  
	//��ϵ�绰
	CC_SYNTHESIZE(string, purInquiryPhone, PurInquiryPhone);  
	//����
	CC_SYNTHESIZE(string, purInquiryFax, PurInquiryFax);  
	//�����ʼ�
	CC_SYNTHESIZE(string, purInquiryEmail, PurInquiryEmail);   
	//��ע
	CC_SYNTHESIZE(string, purInquiryRemark, PurInquiryRemark);   
	//�Զ�����
	CC_SYNTHESIZE(int, purInquiryIsAuto, PurInquiryIsAuto);   
	//���ֵ��� 
	CC_SYNTHESIZE(int, purInquiryIsRubric, PurInquiryIsRubric);   
	//��Чʱ��
	CC_SYNTHESIZE(string, purInquiryEffectiveTime, PurInquiryEffectiveTime);   
	//������
	CC_SYNTHESIZE(string, purInquiryApprover, PurInquiryApprover);   
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, purInquiryCreateTime, PurInquiryCreateTime);   
	//�Ƶ���
	CC_SYNTHESIZE(string, purInquiryCreateBy, PurInquiryCreateBy);   
	//�Ƶ�����
	CC_SYNTHESIZE(string, purInquirySysOrgCode, PurInquirySysOrgCode);   
	//�޸�ʱ��
	CC_SYNTHESIZE(string, purInquiryUpdateTime, PurInquiryUpdateTime);   
	//�޸���
	CC_SYNTHESIZE(string, purInquiryUpdateBy, PurInquiryUpdateBy);   

public:
	// ��JSONת������
	BIND_TO_JSON(PurInquiryFindBillVO, purInquiryBillNo, purInquiryBillDate, purInquirySubject, purInquirySrcBillId,
		purInquiryDeliveryTime, purInquiryQty, purInquiryAmt, purInquiryQuotCount, purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquiryDeliveryPlace, purInquiryContact, purInquiryPhone, purInquiryFax, purInquiryEmail,
		purInquiryRemark, purInquiryIsAuto, purInquiryIsRubric, purInquiryEffectiveTime, purInquiryApprover,
		purInquiryCreateTime, purInquiryCreateBy, purInquirySysOrgCode, purInquiryUpdateTime, purInquiryUpdateBy);
};


//ָ��ѯ�۵���ϸ��Ϣ
class PurInquiryFindDetailBillVO
{
//������Ϣ
	//���ݱ��  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);     
	//��������
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);   

	
	//���ݽ׶Σ������ӿڣ�


//����״̬
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);  
	//�Ƿ�ر�
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);   
	//�Ƿ�����
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);   
	//��������
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);   
	//���ʽ
	CC_SYNTHESIZE(string, purInquiryPaymentMethod, PurInquiryPaymentMethod);   
	//�����ص�
	CC_SYNTHESIZE(string, purInquiryDeliveryPlace, PurInquiryDeliveryPlace);    
	//��ϵ��
	CC_SYNTHESIZE(string, purInquiryContact, PurInquiryContact);   
	//��ϵ�绰
	CC_SYNTHESIZE(string, purInquiryPhone, PurInquiryPhone);   
	//����
	CC_SYNTHESIZE(string, purInquiryFax, PurInquiryFax);   
	//�����ʼ�
	CC_SYNTHESIZE(string, purInquiryEmail, PurInquiryEmail);   
	//���۵���
	CC_SYNTHESIZE(int, purInquiryQuotCount, purInquiryQuotCount);    

//����
	//��ע
	CC_SYNTHESIZE(string, purInquiryRemark, PurInquiryRemark);   
	//�������
	CC_SYNTHESIZE(string, purInquiryApprovalRemark, PurInquiryApprovalRemark);   
	//����
	CC_SYNTHESIZE(string, purInquiryAttachment, PurInquiryAttachment);   
	//�������
	CC_SYNTHESIZE(string, purInquiryApprovalResultType, PurInquiryApprovalResultType);   

public:
// ��JSONת������
	BIND_TO_JSON(PurInquiryFindDetailBillVO, purInquiryBillNo, purInquiryBillDate, purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquirySubject, purInquiryPaymentMethod, purInquiryDeliveryPlace, purInquiryContact,
		purInquiryPhone, purInquiryFax, purInquiryEmail, purInquiryQuotCount, purInquiryRemark, purInquiryApprovalRemark,
		purInquiryApprovalResultType);
};


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



#endif // !_PURINQUIRY_VO_
