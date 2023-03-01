#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
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
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderDO.h"
#include "../../domain/do/PurOrder/PurOrderEntryDO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"

/**
 *  �ɹ������б�,�ɹ�������¼�б�,ɾ���ɹ�Ԥ�����뵥
 */
class PrepaymentDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PurOrderDO& iObj);
	// ��ҳ��ѯ����
	list<PurOrderDO> selectWithPage(const PurOrderDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ��ѯָ��������ϸ��Ϣ-ͨ�����ݱ�Ų�ѯ����
	list<PurOrderDO> selectByBill_no(const PurOrderDO& obj);
	// ָ��������ϸ��¼
	list<PurOrderEntryDO> selectEntryByBill_no(const PurOrderEntryDO& obj);
	// ͨ��IDɾ������
	int deleteById(const PrepaymentDO& uObj);


};
#endif // !_PREPAYMENT_DAO_