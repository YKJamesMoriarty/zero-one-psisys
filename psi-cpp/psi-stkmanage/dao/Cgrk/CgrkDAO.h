#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _CGRK_DAO_
#define _CGRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/do/Cgrk/PurOrderDO.h"
#include "../../domain/do/Cgrk/PurOrderEntryDO.h"
#include "../../domain/vo/Cgrk/QueryCgrkBillDetailsVO.h"
#include "../../domain/query/Cgrk/QueryCgrkBillListQuery.h"
#include "../../domain/query/Cgrk/QueryPurOrderListQuery.h"
#include "../../domain/query/Cgrk/QueryPurOrderEntryQuery.h"
#include "../../domain/dto/Cgrk/AddCgrkBillDTO.h"

/**
 * �ɹ�������ݿ����ʵ��
 */
class CgrkDAO : public BaseDAO
{
public:
	//��ѯ����������
		// ͳ����������
	uint64_t count(const StkIoDO& iObj);


	//��ѯ�����б�
	std::list<StkIoDO> selectBillList(const QueryCgrkBillListQuery query);

	//��ѯ���������б���Ϣ
	list<StkIoDO>selectBillListByBillNo(string BillNo);


	//��ѯ������ϸ��Ϣ
	list<StkIoEntryDO> selectBillDetails(string billNo);

	//��ѯ�ɹ�������Ϣ
	list<PurOrderDO> selectPurOrderList(const QueryPurOrderListQuery& query);

	//��ѯ�ɹ�������¼�б�
	list<PurOrderEntryDO> selectPurOrderEntry(const QueryPurOrderEntryQuery& query);

	//��Ӳɹ���ⵥ
	uint64_t insertCgrkBill(const AddCgrkBillDTO& obj);

	//ɾ���ɹ���ⵥ
	uint64_t deleteCgrkBill(string id);

	//// ͳ����������
	//uint64_t count(const SampleDO& iObj);
	//// ��ҳ��ѯ����
	//list<SampleDO> selectWithPage(const SampleDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//// ͨ��������ѯ����
	//list<SampleDO> selectByName(const string& name);
	//// ��������
	//uint64_t insert(const SampleDO& iObj);
	//// �޸�����
	//int update(const SampleDO& uObj);
	//// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
