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
#ifndef _PUR_INQUIRY_FIND_BILL_VO_H_
#define _PUR_INQUIRY_FIND_BILL_VO_H_

#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� �ɹ�ѯ�۵��б�
 */

//�ɹ�ѯ�۵��б� - ������Ϣ
class PurInquiryFindBillVO
{
	// ID
	//CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// Դ����			
	CC_SYNTHESIZE(string, src_no, Src_no);
	// ��������		   
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	// ����			 
	CC_SYNTHESIZE(double, qty, Qty);
	// �ο����		   
	CC_SYNTHESIZE(double, amt, Amt);
	// ���۵���		   
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	// ���ݽ׶Σ������ӿڣ�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective)
	// �Ƿ�ر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, is_voided, Is_voided);
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
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ���ֵ��� 
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// �Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	// �Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	// �޸���
	CC_SYNTHESIZE(string, update_by, Update_by);

public:
	// ��JSONת������
	BIND_TO_JSON(PurInquiryFindBillVO, bill_no, bill_date, subject, src_no, delivery_time, qty,
		amt, quot_count, bill_stage, is_effective, is_closed, is_voided, delivery_place, contact,
		phone, fax, email, remark, is_auto, is_rubric, effective_time, approver, create_time,
		create_by, sys_org_code, update_time, update_by);

};


#endif // !_PUR_INQUIRY_FIND_BILL_VO_
