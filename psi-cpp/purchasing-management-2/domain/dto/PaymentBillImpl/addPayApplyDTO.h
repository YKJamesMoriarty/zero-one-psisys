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
#ifndef _ADD_PAY_APPLY_DTO_
#define _ADD_PAY_APPLY_DTO_

#include "../../GlobalInclude.h"
#include "PurPayReqEntryDTO.h"

class AddPayApplyDTO :public FileDTO
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
	CC_SYNTHESIZE(string, operator, Operator);
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
	CC_SYNTHESIZE(list<PurPayReqEntryDTO>, detail, Detail);
public:
	//��JSONת������
	friend void from_json(const json& j, AddPayApplyDTO& apt) {
		BIND_FROM_TO_ULL(j, apt, billNo);
		BIND_FROM_TO_ULL(j, apt, billDate);
		BIND_FROM_TO_ULL(j, apt, srcBillType);
		BIND_FROM_TO_ULL(j, apt, srcBillId);
		BIND_FROM_TO_ULL(j, apt, srcNo);
		BIND_FROM_TO_ULL(j, apt, subject);
		BIND_FROM_TO_ULL(j, apt, supplierId);
		BIND_FROM_TO_ULL(j, apt, opDept);
		BIND_FROM_TO_ULL(j, apt, operator);
		BIND_FROM_TO_ULL(j, apt, paymentType);
		BIND_FROM_TO_ULL(j, apt, remark);
		BIND_FROM_TO_ULL(j, apt, billStage);
		BIND_FROM_TO_ULL(j, apt, effectiveTime);
		BIND_FROM_TO_ULL(j, apt, version);

		BIND_FROM_TO_D(j, apt, amt);

		BIND_FROM_TO_I(j, apt, isAuto);
		BIND_FROM_TO_I(j, apt, isEffective);
		BIND_FROM_TO_I(j, apt, isClosed);
		BIND_FROM_TO_I(j, apt, isVoided);

		BIND_FROM_TO_OBJ(j, apt, detail, list<PurPayReqEntryDTO>);
	}
};

#endif
