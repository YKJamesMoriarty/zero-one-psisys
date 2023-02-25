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
#ifndef _PUR_INQUIRY_FIND_DETAIL_BILL_VO_H_
#define _PUR_INQUIRY_FIND_DETAIL_BILL_VO_H_

#include "../../GlobalInclude.h"
#include "EntryPurInquiryVO.h"
#include<list>

/**
 * ��ʾ���� ���� ָ���ɹ�ѯ�۵�����
 */


//ָ��ѯ�۵���ϸ��Ϣ
class PurInquiryFindDetailBillVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//���ݽ׶Σ������ӿڣ�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective)
	// �Ƿ�ر�
	CC_SYNTHESIZE(int,  is_closed, Is_closed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	// �����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	// ��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, phone, Phone);
	// ����
	CC_SYNTHESIZE(string, fax, Fax);
	// �����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	// ���۵���
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	// ��ϸ�б�
	CC_SYNTHESIZE(list<EntryPurInquiryVO>, detailslist, DetailsList);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// �������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);

public:
	// ��JSONת������
	BIND_TO_JSON(PurInquiryFindDetailBillVO, bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided,
		subject, payment_method, delivery_place, contact, phone, fax, email, quot_count, detailslist, remark, 
		approval_remark,attachment, approval_result_type);

};


#endif // !_PUR_INQUIRY_FIND_DETAIL_BILL_VO_
