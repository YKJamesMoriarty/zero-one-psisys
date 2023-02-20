#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/14 15:18:04
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
#ifndef _CURRENCY_DTO_
#define _CURRENCY_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * �������ϱ��ִ������
 */
class CurrencyDTO : public FileDTO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, localCurrency, LocalCurrency);
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
	friend void from_json(const json& j, CurrencyDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, localCurrency);
		BIND_FROM_TO_NORMAL(j, t, start);
		BIND_FROM_TO_NORMAL(j, t, remarks);
		BIND_FROM_TO_NORMAL(j, t, creationTime);
		BIND_FROM_TO_NORMAL(j, t, creationPeo);
		BIND_FROM_TO_NORMAL(j, t, modiTime);
		BIND_FROM_TO_NORMAL(j, t, modiPeo);
	}

	BIND_TO_JSON(CurrencyDTO, id, name, localCurrency, start, remarks, creationTime, creationPeo, modiTime, modiPeo);
};

#endif // !_CURRENCY_DTO_
