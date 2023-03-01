#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: douhao
 @Date: 2022/10/25 11:08:56

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
#ifndef _CURRENCY_SERVICE_
#define _CURRENCY_SERVICE_
#include <list>
#include "../../domain/vo/currency/CurrencyVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/currency/CurrencyQuery.h"
#include "../../domain/dto/currency/CurrencyDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CurrencyService
{
public:
	// ��ҳ��ѯ��������
	PageVO<CurrencyVO> listAll(const CurrencyQuery& query);
	CurrencyVO listByName(const OnlyValueCurrencyQuery& query);
	// ��������
	uint64_t saveData(const CurrencyDTO& dto, const PayloadDTO& payload);
	
	// �޸�����
	bool updateData(const CurrencyDTO& dto, const PayloadDTO& payload);
	
	// ͨ��IDɾ������
	bool removeData(string code);
	//�����ļ�
	bool saveFile(const std::list<CurrencyDTO>& dto, const PayloadDTO& payload);
	//�����ļ�
	bool getData(const CurrencyQuery& query, vector<vector<string>>& data);
	
};

#endif // !_CURRENCY_SERVICE_

