#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _CGRK_CONTROLLER_
#define _CGRK_CONTROLLER_

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

//#include "../../domain/vo/user/UserVO.h"

/**
 * CgrkController
 */
class CgrkController
{
public:
	CREATE_API_FUN_QUERY(queryCgrkBillList, execQueryCgrkBillList, QueryCgrkBillListQuery);
	CREATE_API_FUN_QUERY(queryCgrkBillListAdvanced, execQueryCgrkBillListAdvanced, QueryCgrkBillListAdvancedQuery);
	CREATE_API_FUN_QUERY(queryCgrkBillDetails, execQueryCgrkBillDetails, QueryCgrkBillDetailsQuery);

	CREATE_API_FUN_QUERY(queryPurOrderList, execQueryPurOrderList, QueryPurOrderListQuery);
	CREATE_API_FUN_QUERY(queryPurOrderEntry, execQueryPurOrderEntry, QueryPurOrderEntryQuery);

	CREATE_API_FUN_BODY(addCgrkBill, execAddCgrkBill, AddCgrkBillDTO);
	CREATE_API_FUN_BODY(modifyCgrkBill, execModifyCgrkBill, ModifyCgrkBillDTO);
	CREATE_API_FUN_BODY(removeCgrkBill, execRemoveCgrkBill, RemoveCgrkBillDTO);
	CREATE_API_FUN_BODY(modifyCgrkBillState, execModifyCgrkBillState, ModifyCgrkBillStateDTO);
	CREATE_API_FUN_BODY_FILE(importCgrkFile, execImportCgrkFile, ImportCgrkFileDTO);
	CREATE_API_FUN_QUERY3(exportCgrkFile, execExportCgrkFile);
	//CREATE_API_FUN_JSON(jsonSample, execJsonSample, SampleDTO);

private:
	//��ѯ�ɹ�����
	JsonVO<PageVO<QueryCgrkBillListVO>> execQueryCgrkBillList(const QueryCgrkBillListQuery& query);
	//�߼���ѯ�ɹ�����
	JsonVO<PageVO<QueryCgrkBillListVO>> execQueryCgrkBillListAdvanced(const QueryCgrkBillListAdvancedQuery& query);
	//��ѯ������ϸ��Ϣ
	JsonVO<PageVO<QueryCgrkBillDetailsVO>> execQueryCgrkBillDetails(const QueryCgrkBillDetailsQuery& query);
	//��ѯ�ɹ������б�
	JsonVO<PageVO<QueryPurOrderListVO>> execQueryPurOrderList(const QueryPurOrderListQuery& query);
	//�鿴�ɹ�������¼�б�
	JsonVO<PageVO<QueryPurOrderEntryVO>> execQueryPurOrderEntry(const QueryPurOrderEntryQuery& query);
	//��ӵ�����Ϣ
	JsonVO<uint64_t> execAddCgrkBill(const AddCgrkBillDTO& dto);
	//�޸ĵ�����Ϣ
	JsonVO<uint64_t>  execModifyCgrkBill(const ModifyCgrkBillDTO& dto);
	//ɾ������
	JsonVO<uint64_t> execRemoveCgrkBill(const RemoveCgrkBillDTO& dto);
	//�޸ĵ���״̬
	JsonVO<uint64_t> execModifyCgrkBillState(const ModifyCgrkBillStateDTO& dto);
	// ����
	JsonVO<uint64_t> execImportCgrkFile(const ImportCgrkFileDTO& dto);
	// ����
	JsonVO<std::string> execExportCgrkFile( );

	//JsonVO<uint64_t> execRemoveById(const IntID& id);
	////��ʾJSON�ύ
	//JsonVO<SampleVO> execJsonSample(const SampleDTO& dto);
	////��ʾ�ļ��ϴ�
	//JsonVO<UserVO> execModifyUserInfo(const UserDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_