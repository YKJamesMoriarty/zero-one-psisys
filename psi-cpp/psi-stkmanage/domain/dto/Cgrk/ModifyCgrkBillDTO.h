
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
#ifndef _MODIFY_CGRK_BILL_DTO_
#define _MODIFY_CGRK_BILL_DTO_

#include "../../GlobalInclude.h"

/**
 * �޸Ĳɹ���ⵥ������/���/�ύ��
 */
class ModifyCgrkBillDTO
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
	CC_SYNTHESIZE(string, operatoR, Operator);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//��ϸ*********
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//�����
	CC_SYNTHESIZE(string, unitId, UnitId);
	//�Ƕ�����
	CC_SYNTHESIZE(double, swellQty, SwellQty);
	//�����
	CC_SYNTHESIZE(double, inCost, InCost);
	//��ϸ����ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

	//��ע
	CC_SYNTHESIZE(string, remark1, Remark1);
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
	//����ʵ��***
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

public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyCgrkBillDTO& t); // NOLINT

};

#endif // !_ADD_CGRK_BILL_DTO_