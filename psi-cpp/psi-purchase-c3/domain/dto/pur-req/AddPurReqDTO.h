#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Adam
 @Date: 2023��2��15��

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
#ifndef _ADD_PUR_REQ_DTO_
#define _ADD_PUR_REQ_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//���ǵ��޸ĺ���Ӳɹ������Ĳ����������Ժϲ�Ϊһ��DTO
//��Ӷ�����DTO(��������ϸ����),ͬʱ�����и������ݿ������,���Լ̳�FileDTO
class AddPurReqDTO :public FileDTO
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
	//�Ƿ����
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//�ɹ�����
	CC_SYNTHESIZE(string, purType, PurType);
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
public:
	//��JSONת������
	friend void from_json(const json& j, AddPurReqDTO& t);
};

#endif // !_ADD_PUR_REQ_DTO_