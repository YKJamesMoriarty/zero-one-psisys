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
#include "../../domain/query/Cgrk/QueryCgrkBillListAdvancedQuery.h"
#include "../../domain/dto/Cgrk/AddCgrkBillDTO.h"

/**
 * �ɹ�������ݿ����ʵ��
 */
class CgrkDAO : public BaseDAO
{
public:

	//��ѯ�����б�
	std::list<StkIoDO> selectBillList(const QueryCgrkBillListQuery query);

	//�߼���ѯ�����б�
	std::list<StkIoDO> selectBillListAnvanced(const QueryCgrkBillListAdvancedQuery& query);

	//��ѯ���������б���Ϣ
	list<StkIoDO>selectBillListByBillNo(string BillNo);


	//��ѯ������ϸ��Ϣ
	list<StkIoEntryDO> selectBillDetails(string billNo);

	//��ѯ�ɹ�������Ϣ
	list<PurOrderDO> selectPurOrderList(const QueryPurOrderListQuery& query);

	//��ѯ�ɹ�������¼�б�
	list<PurOrderEntryDO> selectPurOrderEntry(const QueryPurOrderEntryQuery& query);

	//��Ӳɹ���ⵥ
	int insertCgrkBill(const StkIoDO& iObj);

	//��Ӳɹ���ⵥ��ϸ
	int insertCgrkBillEntry(const StkIoEntryDO& iObj);

	//ͨ��Դ���Ų�ѯԴ��id
	string selectSrcBillIdBySrcNo(const string& srcNo);
	//ͨ��Դ���Ų�ѯԴ������
	string selectSrcBillTypeBySrcNo(const string& srcNo);
	//��ѯ�û�����
	string selectOpDeptById(const string& id);
	//��ѯ����id
	string selectIdBySrcNo(const string& srcNo);

	//�޸Ĳɹ���ⵥ
	int updateCgrkBill(const StkIoDO& iObj);
	//ɾ���ɹ���ⵥ��ϸ
	int deleteCgrkBillEntry(const string& billNo);

	//ɾ���ɹ���ⵥ
	uint64_t deleteCgrkBill(const string& id);


};
#endif // !_SAMPLE_DAO_
