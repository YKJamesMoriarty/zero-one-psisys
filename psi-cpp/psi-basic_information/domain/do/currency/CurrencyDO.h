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
	// ���� Code
	CC_SYNTHESIZE(string, code, Code);
	// ���� name
	CC_SYNTHESIZE(string, name, Name);
	// ���� isFunctional
	CC_SYNTHESIZE(string, isFunctional, IsFunctional);
	// ���� isEnabled
	CC_SYNTHESIZE(string, isEnabled, IsEnabled);
	// ������ createBy
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ�� createTime
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸��� updateBy
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ�� updateTime
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
public:
	CurrencyDO() {
		code = "1";
		name = "";
		isFunctional = "1";
		isEnabled = "1";
		remarks = "";
		createTime = "";
		createBy = "";
		updateTime = "";
		updateBy = "";
	}
};

#endif // !_CURRENCY_DO_
