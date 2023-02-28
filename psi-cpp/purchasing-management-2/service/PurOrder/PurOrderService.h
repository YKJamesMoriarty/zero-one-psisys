#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _PUR_ORDER_SERVICE_
#define _PUR_ORDER_SERVICE_
#include <list>
#include "../../domain/vo/PurOrder/PurOrderVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/PurOrder/PurOrderQuery.h"
#include "../../domain/dto/PurOrder/PurOrderDTO.h"

/**
 * �ɹ���������ʵ�֣������ɹ���������ʵ��
 */
class PurOrderService
{
public:
	// �޸ĵ���״̬(�ر�/���ر�/����)
	// �����ˣ�Andrew
	bool updateStatus(const PurOrderDTO& dto, const PayloadDTO& payload);
	
	// ɾ���ɹ�����-ID
	bool removeData(string id);
};

#endif // !_PUR_ORDER_SERVICE_
