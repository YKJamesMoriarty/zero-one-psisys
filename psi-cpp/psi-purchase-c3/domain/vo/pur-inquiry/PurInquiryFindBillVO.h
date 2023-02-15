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
#ifndef _PUR_INQUIRY_FIND_BILL_VO_
#define _PUR_INQUIRY_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� �ɹ�ѯ�۵��б�
 */

//�ɹ�ѯ�۵��б� - ������Ϣ
class PurInquiryFindBillVO
{
	//���ݱ��  
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    
	//��������
	CC_SYNTHESIZE(string, purInquiryBillDate, PurInquiryBillDate);  
	//�������� 
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);  
	//Դ����
	CC_SYNTHESIZE(string, purInquirySrcBillId, PurInquirySrcBillId);   
	//��������
	CC_SYNTHESIZE(string, purInquiryDeliveryTime, purInquiryDeliveryTime);   
	//����
	CC_SYNTHESIZE(double, purInquiryQty, purInquiryQty);   
	//�ο����
	CC_SYNTHESIZE(double, purInquiryAmt, purInquiryAmt);   
	//���۵���
	CC_SYNTHESIZE(int, purInquiryQuotCount, purInquiryQuotCount);    
	//���ݽ׶Σ������ӿڣ�
	CC_SYNTHESIZE(string, purInquiryBillStage, purInquiryBillStage);
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
		purInquiryDeliveryTime, purInquiryQty, purInquiryAmt, purInquiryQuotCount, purInquiryBillStage,purInquiryIsEffective, purInquiryIsClosed,
		purInquiryIsVoided, purInquiryDeliveryPlace, purInquiryContact, purInquiryPhone, purInquiryFax, purInquiryEmail,
		purInquiryRemark, purInquiryIsAuto, purInquiryIsRubric, purInquiryEffectiveTime, purInquiryApprover,
		purInquiryCreateTime, purInquiryCreateBy, purInquirySysOrgCode, purInquiryUpdateTime, purInquiryUpdateBy);

};


#endif // !_PUR_INQUIRY_FIND_BILL_VO_
