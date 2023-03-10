#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Papillon
 @Date: 2023/02/16 22:00:00
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
#ifndef _ADD_PAYMENT_REQ_DTO_
#define _ADD_PAYMENT_REQ_DTO_

#include "../../GlobalInclude.h"
#include "finPaymentReqEntryDTO.h"
#include "../FileDTO.h"

class AddPaymentReqDTO :public FileDTO
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator);
	//��������
	CC_SYNTHESIZE(string, paymentType, PaymentType);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//�Ƿ��ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
	//��ϸ�б�
	CC_SYNTHESIZE(list<FinPaymentReqEtryDTO>, detail, Detail);
public:
	//��JSONת������
	friend void from_json(const json& j, AddPaymentReqDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, opDept);
		BIND_FROM_TO_NORMAL(j, t, operator1);
		BIND_FROM_TO_NORMAL(j, t, paymentType);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, effectiveTime);
		BIND_FROM_TO_I(j, t, version);

		BIND_FROM_TO_D(j, t, amt);

		BIND_FROM_TO_I(j, t, isAuto);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);

		BIND_FROM_TO_OBJ(j, t, detail, list<FinPaymentReqEtryDTO>);
	}
};

#endif //_ADD_PAYMENT_REQ_DTO_
