#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 12:15:16

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
#ifndef _PUR_COMPARE_DO_
#define _PUR_COMPARE_DO_
#include "../DoInclude.h"

/**
 * pur_compare���ݿ�ʵ����
 */
class PurCompareDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	// Դ����(�ɹ�ѯ�۵�)
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ���ֵ���
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// ��ѡ���۵�ids
	CC_SYNTHESIZE(string, candidateQuotIds, CandidateQuotIds);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��������
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ�����
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// �������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	// �������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	// ����Ч
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// �ѹر�
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// �Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// �Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// �汾
	CC_SYNTHESIZE(string, version, Version);
	// ��������_��ʼ
	CC_SYNTHESIZE(string, billDateBegin, BillDateBegin);
	// ��������_����
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
public:
	PurCompareDO() {
		billNo = "";
	}
	PurCompareDO(vector<string> vecStr) {
		int i = 0;
		setBillNo(vecStr[i++]);
		setBillDate(vecStr[i++]);
		setSrcBillType(vecStr[i++]);
		setSrcBillId(vecStr[i++]);
		setSrcNo(vecStr[i++]);
		setSubject(vecStr[i++]);
		setIsRubric(vecStr[i++]);
		setCandidateQuotIds(vecStr[i++]);
		setPaymentMethod(vecStr[i++]);
		setDeliveryPlace(vecStr[i++]);
		setDeliveryTime(vecStr[i++]);
		setAttachment(vecStr[i++]);
		setRemark(vecStr[i++]);
		setIsAuto(vecStr[i++]);
		setBillStage(vecStr[i++]);
		setApprover(vecStr[i++]);
		setBpmiInstanceId(vecStr[i++]);
		setApprovalResultType(vecStr[i++]);
		setApprovalRemark(vecStr[i++]);
		setIsEffective(vecStr[i++]);
		setEffectiveTime(vecStr[i++]);
		setIsClosed(vecStr[i++]);
		setIsVoided(vecStr[i++]);
		setSysOrgCode(vecStr[i++]);
		setCreateBy(vecStr[i++]);
		setCreateTime(vecStr[i++]);
		setUpdateBy(vecStr[i++]);
		/*setUpdateTime(vecStr[i++]);*/
	}
	vector<string> purCompareDOToVecStr() {
		vector<string> vecStr{getBillNo(),getBillDate(),getSrcBillType(),getSrcBillId(),getSrcNo(),
			getSubject(),getIsRubric(),getCandidateQuotIds(),getPaymentMethod(),getDeliveryPlace(),
			getDeliveryTime(),getAttachment(),getRemark(),getIsAuto(),getBillStage(),getApprover(),
			getBpmiInstanceId(),getApprovalResultType(),getApprovalRemark(),getIsEffective(),
			getEffectiveTime(),getIsClosed(),getIsVoided(),getSysOrgCode(),getCreateBy(),getCreateTime(),
			getUpdateBy()/*,getUpdateTime()*/};
		return vecStr;
	}
};

#endif 

