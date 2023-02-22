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
	BIND_TO_JSON(CurrencyVO, id, name, localCurrency, start, remarks, creationTime, creationPeo, modiTime, modiPeo);
};

class CurrencyDetailVO
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
public:
	// ��JSONת������
	BIND_TO_JSON(CurrencyDetailVO, id, name, localCurrency, start, remarks);
};

class CurrencyActionInfoVO
{
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
	BIND_TO_JSON(CurrencyActionInfoVO, creationTime, creationPeo, modiTime, modiPeo);
};

#endif // !_Currency_VO_
