/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "stdafx.h"
#include "CgrkController.h"


//��ѯ�����б�
JsonVO<PageVO<QueryCgrkBillListVO>> CgrkController::execQueryCgrkBillList(const QueryCgrkBillListQuery& query)
{
	PageVO<QueryCgrkBillListVO> result;
	list<QueryCgrkBillListVO> rows;
	rows.push_back(QueryCgrkBillListVO());
	rows.push_back(QueryCgrkBillListVO());
	rows.push_back(QueryCgrkBillListVO());
	result.setRows(rows);
	return JsonVO<PageVO<QueryCgrkBillListVO>>(result, RS_SUCCESS);
}
//�鿴ָ��������ϸ��Ϣ
JsonVO<PageVO<QueryCgrkBillDetailsVO>> CgrkController::execQueryCgrkBillDetails(const QueryCgrkBillDetailsQuery& query)
{
	PageVO<QueryCgrkBillDetailsVO> result;
	list<QueryCgrkBillDetailsVO> rows;
	rows.push_back(QueryCgrkBillDetailsVO());
	rows.push_back(QueryCgrkBillDetailsVO());
	rows.push_back(QueryCgrkBillDetailsVO());
	return JsonVO<PageVO<QueryCgrkBillDetailsVO>>(result, RS_SUCCESS);
}
//��ѯ�ɹ������б�
JsonVO<PageVO<QueryPurOrderListVO>> CgrkController::execQueryPurOrderList(const QueryPurOrderListQuery& query)
{
	PageVO<QueryPurOrderListVO> result;

	return JsonVO<PageVO<QueryPurOrderListVO>>(result, RS_FAIL);
}
//�鿴�ɹ�������¼�б�
JsonVO<PageVO<QueryPurOrderEntryVO>> CgrkController::execQueryPurOrderEntry(const QueryPurOrderEntryQuery& query)
{
	PageVO<QueryPurOrderEntryVO> result;
	return JsonVO<PageVO<QueryPurOrderEntryVO>>(result, RS_FAIL);
}

//��Ӳɹ���ⵥ
JsonVO<uint64_t> CgrkController::execAddCgrkBill(const AddCgrkBillDTO& dto)
{
	JsonVO<uint64_t> result;

	return result;
}
//�޸Ĳɹ���ⵥ
JsonVO<uint64_t>  CgrkController::execModifyCgrkBill(const ModifyCgrkBillDTO& dto)
{

	JsonVO<uint64_t> result;

	return result;
}

//ɾ���ɹ���ⵥ
JsonVO<uint64_t> CgrkController::execRemoveCgrkBill(const RemoveCgrkBillDTO& dto)
{

	JsonVO<uint64_t> result;
	//ִ������ɾ��

	//��Ӧ���
	return result;
}

//�޸ĵ���״̬
JsonVO<uint64_t> CgrkController::execModifyCgrkBillState(const ModifyCgrkBillStateDTO& dto)
{

	JsonVO<uint64_t> result;

	return result;
}
// ����
JsonVO<uint64_t> CgrkController::execImportCgrkFile(const ImportCgrkFileDTO& dto)
{
	JsonVO<uint64_t> result;

	return result;
}
// ����
JsonVO<std::string> CgrkController::execExportCgrkFile()
{
	JsonVO<std::string> result;

	return result;
}


