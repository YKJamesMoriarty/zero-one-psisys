#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/14 15:40:13
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
#ifndef _Currency_VO_
#define _Currency_VO_

#include "../../GlobalInclude.h"

/**
 * �������ϱ���ģ��
 */
class CurrencyVO
{
	// ���ݿ��ڱ�� Id
	CC_SYNTHESIZE(string, id, Id);
	// ���� 
	CC_SYNTHESIZE(string, code, Code);
	// ���� 
	CC_SYNTHESIZE(string, name, Name);
	// ���� 
	CC_SYNTHESIZE(int, isFunctional, IsFunctional);
	// ���� 
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	// ������ 
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ�� 
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸��� 
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
public:
	// ��JSONת������
	BIND_TO_JSON(CurrencyVO, id, code, name, isFunctional, isEnabled, createBy, createTime, updateBy, updateTime, remarks);
};
#endif // !_Currency_VO_
