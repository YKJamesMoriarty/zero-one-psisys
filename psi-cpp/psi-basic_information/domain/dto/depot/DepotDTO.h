#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Linsky
 @Date: 2023/2/13 20:31:04

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
#ifndef _DEPOT_DTO_
#define _DEPOT_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"


/**
 * �������ϲֿ�ģ�鴫�����
 */
class DepotDTO : public FileDTO
{
	// �ϼ�
	CC_SYNTHESIZE(string, previous, Previous);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ������
	CC_SYNTHESIZE(string, helpName, HelpName);
	// �绰
	CC_SYNTHESIZE(int, phone, Phone);
	// ����
	CC_SYNTHESIZE(string, start, Start);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	// ����ʱ��
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	// ������
	CC_SYNTHESIZE(string, creationPeo, CreationPeo);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, modiTime, ModiTime);
	// �޸���
	CC_SYNTHESIZE(string, modiPeo, ModiPeo);
public:
	// ��JSONת������
	friend void from_json(const json& j, DepotDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, previous);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, helpName);
		BIND_FROM_TO_I(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, start);
		BIND_FROM_TO_NORMAL(j, t, remarks);
		BIND_FROM_TO_NORMAL(j, t, creationTime);
		BIND_FROM_TO_NORMAL(j, t, creationPeo);
		BIND_FROM_TO_NORMAL(j, t, modiTime);
		BIND_FROM_TO_NORMAL(j, t, modiPeo);
	}

	BIND_TO_JSON(DepotDTO, previous, name, id, helpName, phone, start, remarks, creationTime, creationPeo, modiTime, modiPeo);
};

#endif // !_DEPOT_DTO_
