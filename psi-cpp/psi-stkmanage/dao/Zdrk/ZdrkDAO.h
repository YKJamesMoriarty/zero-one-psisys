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
#ifndef _ZDRK_DAO_
#define _ZDRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillDetailsVO.h"
#include "../../domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../../domain/dto/Zdrk/AddZdrkBillDTO.h"

/**
 * �Ƕ�������ݿ����ʵ��
 */
class ZdrkDAO : public BaseDAO
{
public:
	// ��������
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// ��˵��ݸ�������
	int updateApproval(const StkIoDO& iObj);
	// �޸�����
	int update(const StkIoDO& iObj);
	// �޸ĵ���״̬
	int updateState(const StkIoDO& iObj);
	// ������ϸ
	int update(const StkIoEntryDO& iObj);
	// ���ݵ��ݱ��ɾ������
	int deleteBillById(const string& billNo);
	// ���ݵ��ݱ�źͷ�¼��ɾ����ϸ
	int deleteDetailById(const string& billNo, const int& entryNo);
	// ���ݵ��ݱ��ɾ��������ϸ
	int deleteDetailById(const string& billNo); 

	//��ѯ�����б�
	std::list<StkIoDO> selectBillList(const QueryZdrkBillListQuery query);

	//��ѯ���������б���Ϣ
	list<StkIoDO>selectBillListByBillNo(string BillNo);

	//��ѯ������ϸ��Ϣ
	list<StkIoEntryDO> selectBillDetails(string billNo);


};
#endif // !_Zdrk_DAO_
