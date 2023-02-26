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
#ifndef _MOD_PAY_APPLY_DTO_
#define _MOD_PAY_APPLY_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

class ModPayApplyDTO :public FileDTO
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
	//��������
	CC_SYNTHESIZE(string, paymentType, paymentType);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, supplierId);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, opDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator, Operator);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//�����������
	CC_SYNTHESIZE(int, approvalResultType, ApprovalResultType);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//�Ƿ��ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��������
	CC_SYNTHESIZE(string, sysOrdCode, SysOrdCode);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, updateTime);

public:
	//��JSONת������
	friend void from_json(const json& j, ModPayApplyDTO& mdt) {
		BIND_FROM_TO_ULL(j, mdt, billNo);
		BIND_FROM_TO_ULL(j, mdt, billDate);
		BIND_FROM_TO_ULL(j, mdt, srcBillType);
		BIND_FROM_TO_ULL(j, mdt, srcBillId);
		BIND_FROM_TO_ULL(j, mdt, srcNo);
		BIND_FROM_TO_ULL(j, mdt, subject);
		BIND_FROM_TO_ULL(j, mdt, paymentType);
		BIND_FROM_TO_ULL(j, mdt, supplierId);
		BIND_FROM_TO_ULL(j, mdt, opDept);
		BIND_FROM_TO_ULL(j, mdt, operator);
		BIND_FROM_TO_ULL(j, mdt, remark);
		BIND_FROM_TO_ULL(j, mdt, billStage);
		BIND_FROM_TO_ULL(j, mdt, approver);
		BIND_FROM_TO_ULL(j, mdt, bpmiInstanceId);
		BIND_FROM_TO_ULL(j, mdt, approvalRemark);
		BIND_FROM_TO_ULL(j, mdt, effectiveTime);
		BIND_FROM_TO_ULL(j, mdt, sysOrdCode);
		BIND_FROM_TO_ULL(j, mdt, createBy);
		BIND_FROM_TO_ULL(j, mdt, createTime);
		BIND_FROM_TO_ULL(j, mdt, updateBy);
		BIND_FROM_TO_ULL(j, mdt, updateTime);

		BIND_FROM_TO_D(j, mdt, amt);
		BIND_FROM_TO_D(j, mdt, paidAmt);

		BIND_FROM_TO_I(j, mdt, isAuto);
		BIND_FROM_TO_I(j, mdt, isEffective);
		BIND_FROM_TO_I(j, mdt, isClosed);
		BIND_FROM_TO_I(j, mdt, isVoided);
	}
};

#endif