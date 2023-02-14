#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _QueryBillList_DO_
#define _QueryBillList_DO_
#include "../DoInclude.h"

/**
 * ��ѯ�����б����ݿ�ʵ����
 */
class QueryBillListDO
{
	//// ���ݱ��
	//CC_SYNTHESIZE(uint64_t, id, Id);
	//// ��������-��ʼ
	//CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	//// ��������-����
	//CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	//// ��������
	//CC_SYNTHESIZE(string, subject, Subject);
	//// ��Ӧ��
	//CC_SYNTHESIZE(string, supplierId, SupplierId);
	//// ���ݽ׶�
	//CC_SYNTHESIZE(string, billStage, BillStage);
	//// �Ƿ���Ч
	//CC_SYNTHESIZE(uint64_t, isEffective, IsEffective);
	//// �Ƿ�ر�
	//CC_SYNTHESIZE(uint64_t, isClosed, IsClosed);
	//// �Ƿ�����
	//CC_SYNTHESIZE(uint64_t, isVoided, IsVoided);
	// ���ݱ��
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ��������-��ʼ
	CC_SYNTHESIZE(string, bill_date_start, Bill_Date_Start);
	// ��������-����
	CC_SYNTHESIZE(string, bill_date_end, Bill_Date_End);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_Id);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_Stage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(uint64_t, is_effective, Is_effective);
	// �Ƿ�ر�
	CC_SYNTHESIZE(uint64_t, is_closed, Is_closed);
	// �Ƿ�����
	CC_SYNTHESIZE(uint64_t, is_voided, Is_voided);
public:
	QueryBillListDO() {
		id = 0;
		bill_date_start = "";
		bill_date_end = "";
		subject = -1;
		supplier_id = "";
		bill_stage = "";
		is_effective =0;
		is_closed = 1;
		is_voided = 1;
	}
};

#endif // !_QueryBillList_DO_
