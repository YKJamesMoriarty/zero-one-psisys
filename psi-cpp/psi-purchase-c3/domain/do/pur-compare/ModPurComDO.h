#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023\02\18 17:23:39

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
#ifndef _MOD_PUR_COM_DO_H_
#define _MOD_PUR_COM_DO_H_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ModPurComDO
{
	// ����id
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// Դ��ID
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);

	// Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// subject
	CC_SYNTHESIZE(string, subject, Subject);
	// �Ƿ����
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// ��ѡ���۵�ids
	CC_SYNTHESIZE(string, candidateQuotIds, CandidateQuotIds);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);

	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ����ʱ��
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);

	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// �����
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// �����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	// �������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);

	// �Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// �ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// ��������
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);

	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// �汾
	CC_SYNTHESIZE(int, version, Version);

	//��ϸ
	CC_SYNTHESIZE(list<PurComDetailDTO>, detail, Detail);
public:
	ModPurComDO() {

	}
};

#endif // !_MOD_PUR_COM_DO_H_
