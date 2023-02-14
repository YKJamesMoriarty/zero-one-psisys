#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 10:50:01

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
#ifndef _PUR_RER_FIND_BILL_VO_
#define _PUR_RER_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/*
��ѯ�����б���ʾ����
*/
//��ע:��ĺ�������ֶ�������Ҫ����
class PurReqFindBillVO {
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	// Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	// �ɹ�����
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// ������
	CC_SYNTHESIZE(string, request_dept, Request_dept);
	// ������
	CC_SYNTHESIZE(string, requester, Requester);
	// ��������
	CC_SYNTHESIZE(string, request_time, Request_time);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);
	// �Ѷ�����
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	// �ο����
	CC_SYNTHESIZE(double, amt, Amt);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч			
	CC_SYNTHESIZE(int, is_effective, Is_effective);
		//�ѹر�			
		CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������			
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ���ֵ���
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// ��Чʱ��
	CC_SYNTHESIZE(int, effective_time, Effective_time);
	// ������
	CC_SYNTHESIZE(string, approver, approver);
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
	BIND_TO_JSON(PurReqFindBillVO, bill_no, bill_date, subject, src_no, pur_type,
		request_dept, requester, request_time, qty, ordered_qty, amt, bill_stage,
		is_effective, is_closed, is_voided, remark, is_auto, is_rubric, effective_time,
		approver, create_time, create_by, sys_org_code, update_time, update_by);
};
#endif // !

