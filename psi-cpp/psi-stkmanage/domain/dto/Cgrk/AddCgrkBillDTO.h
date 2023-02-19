#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _ADD_CGRK_BILL_DTO_
#define _ADD_CGRK_BILL_DTO_

#include "../../GlobalInclude.h"
#include "CgrkBillEntryDTO.h"
#include "../FileDTO.h"

/**
 * �޸Ĳɹ���ⵥ������/���/�ύ��
 */
class AddCgrkBillDTO : public FileDTO
{


	//����
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);//�Զ�����
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);//��ȡϵͳʱ��

	//ѡ��############
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator1);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);

	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);

	//������######################
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//������ 
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//�Ƶ���*******
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//�Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ֵ���
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//��Ӧ��
	CC_SYNTHESIZE(int, hasRp, HasRp);

	//������ϸ
	CC_SYNTHESIZE(list<CgrkBillEntryDTO>, entry, Entry);

public:
	// ��JSONת������
	friend void from_json(const json& j, AddCgrkBillDTO& t); // NOLINT

};

#endif // !_ADD_CGRK_BILL_DTO_