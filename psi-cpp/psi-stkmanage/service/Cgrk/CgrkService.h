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
#include <list>
#include "../../domain/query/Cgrk/QueryCgrkBillListQuery.h"
#include "../../domain/query/Cgrk/QueryCgrkBillListAdvancedQuery.h"
#include "../../domain/query/Cgrk/QueryCgrkBillDetailsQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Cgrk/QueryCgrkBillListVO.h"
#include "../../domain/vo/Cgrk/QueryCgrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/Cgrk/AddCgrkBillDTO.h"
#include "../../domain/dto/Cgrk/ModifyCgrkBillDTO.h"
#include "../../domain/dto/Cgrk/ModifyCgrkBillStateDTO.h"
#include "../../domain/dto/Cgrk/RemoveCgrkBillDTO.h"
#include "../../domain/dto/Cgrk/ImportCgrkFileDTO.h"
#include "../../domain/query/Cgrk/QueryPurOrderListQuery.h"
#include "../../domain/vo/Cgrk/QueryPurOrderListVO.h"
#include "../../domain/query/Cgrk/QueryPurOrderEntryQuery.h"
#include "../../domain/vo/Cgrk/QueryPurOrderEntryVO.h"
#include "../../domain/vo/Cgrk/QueryPurOrderEntryListVO.h"
#include"../../domain/dto/Cgrk/ModifyCgrkBillStateDTO.h"

#ifndef CGRK_SERVERICE
#define CGRK_SERVERICE
/**
 * �ɹ�������ʵ��
 */
class CgrkService
{
public:
	// ��ҳ��ѯ��������
	PageVO<QueryCgrkBillListVO> listCgrkBillList(const QueryCgrkBillListQuery& query);

	//�߼���ҳ��ѯ����
	PageVO<QueryCgrkBillListVO>  listCgrkBillListAdvanced(const QueryCgrkBillListAdvancedQuery& query);

	//��ѯ������ϸ��Ϣ
	QueryCgrkBillDetailsVO getCgrkBillDetails(const QueryCgrkBillDetailsQuery& query);


	//��ѯ�ɹ������б�
	PageVO<QueryPurOrderListVO> listPurOrderList(const QueryPurOrderListQuery& query);
	
	//�ɹ�������¼�б�
	PageVO<QueryPurOrderEntryVO> listPurOrderEntry(const QueryPurOrderEntryQuery& query);

	//��Ӳɹ���ⵥ
	int saveCgrkBill(const AddCgrkBillDTO& dto, const PayloadDTO& payload);

	//�޸Ĳɹ���ⵥ
	int updateCgrkBill(const ModifyCgrkBillDTO dto, const PayloadDTO& payload);

	//ɾ���ɹ���ⵥ
	bool removeCgrkBill(string id);

	//�޸ĵ���״̬
	bool updataBillStatus(const ModifyCgrkBillStateDTO& dto);
};


#endif // !CGRK_SERVERICE

