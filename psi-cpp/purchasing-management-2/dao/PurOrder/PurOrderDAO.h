#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/19 16:41:00

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
#ifndef _PUR_ORDER_DAO_
#define _PUR_ORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderDO.h"
#include "../../dao/PurOrder/PurOrderDetailMapper.h"
/**
 * �ɹ����������ݿ����ʵ��
 */
class PurOrderDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const PurOrderDO& iObj);
	// ��������
	uint64_t update(const PurOrderDO& iObj);
	// ��������
	uint64_t count(const PurOrderDO& iObj);
	// ��ѯ��ϸ��Ϣ
	list<PurOrderDO> selectDetail(const string bill_no);
};
#endif // !_PUR_ORDER_DAO_
