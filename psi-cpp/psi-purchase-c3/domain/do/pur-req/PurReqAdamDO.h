#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2022/2/21 8:50:55

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
#ifndef _PUR_REQ_ADAM_DO_H_
#define _PUR_REQ_ADAM_DO_H_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class PurReqAdamDO
{
	//����id
	CC_SYNTHESIZE(string, id, Id);
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
	//�Ƿ����
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//�ɹ�����
	CC_SYNTHESIZE(string, purType, PurType);

	//������
	CC_SYNTHESIZE(string, requestDept, RequestDept);
	//������
	CC_SYNTHESIZE(string, requester, Requester);
	//����ʱ��
	CC_SYNTHESIZE(string, requestTime, RequestTime);

	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//�ο����
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѷ�����
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);

	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);

	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//����id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);

	//�����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
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
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);

	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�汾
	CC_SYNTHESIZE(int, version, Version);

public:
	PurReqAdamDO() {
		//Դ������
		srcBillType = "";
		//Դ��id
		srcBillId = "";
		//Դ����
		srcNo = "";
		//��������
		subject = "";
		//�Ƿ����
		isRubric = 0;
		//�ɹ�����
		purType = "";
		//����
		qty = 0.000000;
		//�ο����
		amt = 0.00;
		//�Ѷ�����
		orderedQty = 0.000000;
		//����
		attachment = "";
		//��ע
		remark = "";
		//�Ƿ��Զ�����
		isAuto = 0;
		//�����
		approver = "";
		//����id
		bpmiInstanceId = "";
		//�����������
		approvalResultType = "";
		//�������
		approvalRemark = "";
		//�Ƿ���Ч
		isEffective = 0;
		//��Чʱ��
		effectiveTime = "";
		//�Ƿ��ѹر�
		isClosed = 0;
		//�Ƿ�����
		isVoided = 0;
		//�޸���
		updateBy = "";
		//�޸�ʱ��
		updateTime = "";
		//�汾
		version = -1;
	}
};

#endif // !_PUR_REQ_ADAM_DO_H_
