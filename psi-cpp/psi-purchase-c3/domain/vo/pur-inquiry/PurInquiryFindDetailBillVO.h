#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PUR_INQUIRY_FIND_DETAIL_BILL_VO_
#define _PUR_INQUIRY_FIND_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� ָ���ɹ�ѯ�۵�����
 */


//ָ��ѯ�۵���ϸ��Ϣ
class PurInquiryFindDetailBillVO
{
	//���ݱ��  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//��������
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);
	//���ݽ׶Σ������ӿڣ�
	CC_SYNTHESIZE(string, purInquiryBillStage, purInquiryBillStage);
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
	BIND_TO_JSON(PurInquiryFindDetailBillVO, purInquiryBillNo, purInquiryBillDate, purInquiryBillStage, purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquirySubject, purInquiryPaymentMethod, purInquiryDeliveryPlace, purInquiryContact,
		purInquiryPhone, purInquiryFax, purInquiryEmail, purInquiryQuotCount, purInquiryRemark, purInquiryApprovalRemark,
		purInquiryApprovalResultType);

};


#endif // !_PUR_INQUIRY_FIND_DETAIL_BILL_VO_
