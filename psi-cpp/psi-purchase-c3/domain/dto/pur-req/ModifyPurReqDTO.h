#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: adam
 @Date: 2023/2/24 10:24

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
#ifndef _MODIFY_PUR_REQ_DTO_H_
#define _MODIFY_PUR_REQ_DTO_H_

#include "../../GlobalInclude.h"
#include "PurReqEntryDTO.h"

//���ǵ��޸ĺ����Ӳɹ������Ĳ����������Ժϲ�Ϊһ��DTO
//���Ӷ�����DTO(��������ϸ����),ͬʱ�����и������ݿ�������,���Լ̳�FileDTO
class ModifyPurReqDTO
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
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//��������
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
	//��ϸ�б�
	CC_SYNTHESIZE(list<PurReqEntryDTO>, detail, Detail);

public:
	//��JSONת������
	friend void from_json(const json& j, ModifyPurReqDTO& t);
};

#endif // !_MODIFY_PUR_REQ_DTO_