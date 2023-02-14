#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/01/14 21:30:00

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
#ifndef __EXESTATUS_QUERY__
#define __EXESTATUS_QUERY__

#include "../PageQuery.h"

/**
* �ɹ�����ִ�����Query����ģ��
*/
class ExeStatusQuery : public PageQuery
{
	CC_SYNTHESIZE(std::string, column, Column); // �������
	CC_SYNTHESIZE(std::string, order, Order); // ��ѯ˳��
	CC_SYNTHESIZE(std::string, field, Field); // ��ѯ���ز�����
public:
	// ��JSONת������
	friend void from_json(const json& j, ExeStatusQuery& esq) // NOLINT
	{
		BIND_FROM_TO_ULL(j, esq, pageIndex);
		BIND_FROM_TO_ULL(j, esq, pageSize);
		BIND_FROM_TO_NORMAL(j, esq, column);
		BIND_FROM_TO_NORMAL(j, esq, order);
		BIND_FROM_TO_NORMAL(j, esq, field);
	}
};

#endif