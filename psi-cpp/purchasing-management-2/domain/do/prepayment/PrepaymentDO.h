#pragma once

/*
 Copyright Zero One Star. All rights reserved.
 @Author: xubuxi
 @Date: 2023/2/18 22:45
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
#pragma once
#ifndef _PREPAYMENT_DO_
#define _PREPAYMENT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����-�ɹ�Ԥ��ʵ����-`fin_payment_req`
 */
class PrepaymentDO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, op, Operator);
	//������
	CC_SYNTHESIZE(int, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
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
	PrepaymentDO() {
		
	}
};
#endif // !_PREPAYMENT_DO_
