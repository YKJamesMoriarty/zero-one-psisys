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
#include "../../service/Cgrk/CgrkService.h"



//��ѯ�����б�
JsonVO<PageVO<QueryCgrkBillListVO>> CgrkController::execQueryCgrkBillList(const QueryCgrkBillListQuery& query)
{

	CgrkService service;
	PageVO<QueryCgrkBillListVO> result = service.listCgrkBillList(query);
	return JsonVO<PageVO<QueryCgrkBillListVO>>(result, RS_SUCCESS);


}

//�߼���ѯ�����б�
JsonVO<PageVO<QueryCgrkBillListVO>> CgrkController::execQueryCgrkBillListAdvanced(const QueryCgrkBillListAdvancedQuery& query)
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
JsonVO<QueryCgrkBillDetailsVO> CgrkController::execQueryCgrkBillDetails(const QueryCgrkBillDetailsQuery& query)
{
	CgrkService service;
	QueryCgrkBillDetailsVO result = service.getCgrkBillDetails(query);
	return JsonVO<QueryCgrkBillDetailsVO>(result, RS_SUCCESS);
}




//��ѯ�ɹ������б�
JsonVO<PageVO<QueryPurOrderListVO>> CgrkController::execQueryPurOrderList(const QueryPurOrderListQuery& query)
{
	CgrkService service;
	PageVO<QueryPurOrderListVO> result = service.listPurOrderList(query);
	return JsonVO<PageVO<QueryPurOrderListVO>>(result, RS_SUCCESS);
}
//�鿴�ɹ�������¼�б�
JsonVO<PageVO<QueryPurOrderEntryVO>> CgrkController::execQueryPurOrderEntry(const QueryPurOrderEntryQuery& query)
{
	CgrkService service;
	PageVO<QueryPurOrderEntryVO> result = service.listPurOrderEntry(query);
	return JsonVO<PageVO<QueryPurOrderEntryVO>>(result, RS_SUCCESS);
}

//��Ӳɹ���ⵥ
JsonVO<int> CgrkController::execAddCgrkBill(const AddCgrkBillDTO& dto,const PayloadDTO& payload)
{
	JsonVO<int> result;
	CgrkService service;



	// ִ����������
	int row = service.saveCgrkBill(dto, payload);
	if (row > 0) {
		result.success(row);
	}
	else if (row == -1) {
		result.setData(row);
		result.setStatus(RS_PARAMS_INVALID);
	}
	else {
		result.fail(row);
	}
	return result;

}
//�޸Ĳɹ���ⵥ
JsonVO<uint64_t>  CgrkController::execModifyCgrkBill(const ModifyCgrkBillDTO& dto)
{

	JsonVO<uint64_t> result;
	
	return result;
}

//ɾ���ɹ���ⵥ
JsonVO<std::string> CgrkController::execRemoveCgrkBill(const RemoveCgrkBillDTO& dto)
{

	CgrkService service;
	JsonVO<std::string> result;
	//ִ������ɾ��
	if (service.removeCgrkBill(dto.getBillNo())) {
		result.success(dto.getBillNo());
	}
	else
	{
		result.fail(dto.getBillNo());
	}
	//��Ӧ���
	return result;
}

//�޸ĵ���״̬
JsonVO<uint64_t> CgrkController::execModifyCgrkBillState(const ModifyCgrkBillStateDTO& dto)
{

	JsonVO<uint64_t> result;
	result.success(1);

	return result;
}
// ����
JsonVO<uint64_t> CgrkController::execImportCgrkFile(const ImportCgrkFileDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(1);
	return result;
}
// ����
JsonVO<std::string> CgrkController::execExportCgrkFile()
{
	JsonVO<std::string> result;
	result.success(u8"��������");
	return result;
}


