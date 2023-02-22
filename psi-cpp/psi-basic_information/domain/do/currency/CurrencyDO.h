#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/21 21:46:32
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
#ifndef _CURRENCY_DO_
#define _CURRENCY_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class CurrencyDO
{
	// ���� name
	CC_SYNTHESIZE(string, name, Name);
	// ���� code
	CC_SYNTHESIZE(string, id, Id);
	// ���� is_functional
	CC_SYNTHESIZE(string, localCurrency, LocalCurrency);
	// ���� is_enabled
	CC_SYNTHESIZE(string, start, Start);
	// ������ create_by
	CC_SYNTHESIZE(string, creationPeo, CreationPeo);
	// ����ʱ�� create_time
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	// �޸��� update_by
	CC_SYNTHESIZE(string, modiPeo, ModiPeo);
	// �޸�ʱ�� update_time
	CC_SYNTHESIZE(string, modiTime, ModiTime);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
public:
	CurrencyDO() {
		id = "1";
		name = "";
		localCurrency = "1";
		start = "1";
		remarks = "";
		creationTime = "";
		creationPeo = "";
		modiTime = "";
		modiPeo = "";
	}
};

#endif // !_CURRENCY_DO_
