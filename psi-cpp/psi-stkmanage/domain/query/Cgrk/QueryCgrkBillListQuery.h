#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _QUERY_CGRK_BILL_LIST_QUERY_
#define _QUERY_CGRK_BILL_LIST_QUERY_

#include "../PageQuery.h"

class QueryCgrkBillListQuery : public PageQuery
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�������ڣ���ʼ��
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	//�������ڣ�������
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);

public:
	QueryCgrkBillListQuery()
	{
		billNo = "";
		billDateStart = "";
		billDateEnd = "";
		subject = "";
		supplierId = "";
		billStage = "";
		isEffective = -1;
		isVoided = -1;
		isClosed = -1;
	}


	// ��from_json
	friend void from_json(const json& j, QueryCgrkBillListQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateStart);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, billStage);

		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_I(j, t, isClosed);
	}
};

#endif // !_CGRK_QUERY_