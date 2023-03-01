#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/15 10:55:01

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
#ifndef _PUR_ORDER_QUERY_
#define _PUR_ORDER_QUERY_

#include "../PageQuery.h"

/**
 * �ɹ�������ҳ��ѯ����
 */
class PurOrderQuery : public PageQuery {
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// ҵ��Ա
	CC_SYNTHESIZE(string, op_er, Op_er);
	// ���ݽ׶�		
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// �Ƿ�ر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// �Ƿ�����.
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	
public:
	// ��JSONת������
	friend void from_json(const json& j, PurOrderQuery& t) {
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		// ���ݱ��
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		// ��������
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		// ��������
		BIND_FROM_TO_NORMAL(j, t, subject);
		// ��Ӧ��
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		// ҵ��Ա
		BIND_FROM_TO_NORMAL(j, t, op_er);
		// ���ݽ׶�		
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		// �Ƿ���Ч
		BIND_FROM_TO_I(j, t, is_effective);
		// �Ƿ�ر�
		BIND_FROM_TO_I(j, t, is_closed);
		// �Ƿ�����
		BIND_FROM_TO_I(j, t, is_voided);
	}
	PurOrderQuery() {
		is_effective= -1;
		is_closed = -1;
		is_voided = -1;
	}
};
#endif // !_PUR_ORDER_QUERY_




