#pragma once

#ifndef _PURINQUIRYFINDDETAILBILL_VO_
#define _PURINQUIRYFINDDETAILBILL_VO_

#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� ָ���ɹ�ѯ�۵�����
 */


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


#endif // !_PURINQUIRYFINDDETAILBILL_VO_
