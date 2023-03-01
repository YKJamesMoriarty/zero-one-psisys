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
#ifndef _PREPREPAYMENT_ENTRY_DO_
#define _PREPREPAYMENT_ENTRY_DO_
#include "../DoInclude.h"


/**
 * ʾ�����ݿ�ʵ����-�ɹ�Ԥ��ʵ����-fin_payment_req_entry
 */

class PrepaymentEntryDO {
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//����
	CC_SYNTHESIZE(string, mid, Mid);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��¼��
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//Դ������id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);
	//���㷽ʽ
	CC_SYNTHESIZE(string, settle_method, Settle_method);
	//�ʽ��˻�
	CC_SYNTHESIZE(string, bank_account_id, Bank_account_id);
	//������
	CC_SYNTHESIZE(int, amt, Amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(int, version, Version);

public:
	PrepaymentEntryDO() {
		id = "";
		mid = "";
		bill_no = "";
		entry_no = "";
		src_bill_type = "";
		src_bill_id = "";
		src_entry_id = "";
		src_no = "";
		settle_method = "";
		bank_account_id = "";
		amt = 0;
		remark = "";
		custom1 = "test";
		custom2 = "";
		version = 0;

	}
};

#endif // !_PREPAYMENT_DO_