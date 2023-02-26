/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/25 14:26:52

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
#ifndef _PUR_ORDER_ENTRY_DAO_
#define _PUR_ORDER_ENTRY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderEntryDO.h"
#include "../PurOrderSub/PurOrderEntryMapper.h"

/**
 * �ɹ����������ݿ����ʵ��
 */
class PurOrderEntryDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const PurOrderEntryDO& iObj);
	// ��������
	uint64_t update(const PurOrderEntryDO& iObj);
	// �Ƿ����
	uint64_t count(const PurOrderEntryDO& iObj);

	list<PurOrderEntryDO> selectPurOrderEntry(const string bill_no);
};
#endif // !_PUR_ORDER_DAO_
