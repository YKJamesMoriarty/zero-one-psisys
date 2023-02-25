/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/16 0:23:02

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
#include "PurOrderController.h"
#include "../../service/PurOrder/PurOrderService.h"

// ��ѯlist����
JsonVO<PageVO<PurOrderVO>> PurOrderController::execListPurOrder(const PurOrderQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	PurOrderService service;
	//��ѯ����
	//PageVO<PurOrderVO> result = service.listAll(query);
	// ����
	PageVO<PurOrderVO> result;
	list<PurOrderVO> rows;
	rows.push_back(PurOrderVO());
	rows.push_back(PurOrderVO());
	result.setRows(rows);
	//��Ӧ���
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

// ��ѯ��������byDTO
JsonVO<PurOrderVO> PurOrderController::execGetPurOrder(const PurOrderDTO& dto)
{
	PurOrderService service;
	PurOrderVO test;

	JsonVO<PurOrderVO> result = JsonVO(service.getData(dto.getId()), RS_SUCCESS);
	test.setId(dto.getId());
	result = JsonVO(test, RS_SUCCESS);

	return result;
}

// ��������
JsonVO<string> PurOrderController::execAddPurOrder(const PurOrderDTO& dto)
{
	JsonVO<string> result;
	//����һ��Service
	PurOrderService service;

	//ִ����������
	string id = service.saveData(dto);
	if (id != "") {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	return result;
}
// �޸�����
JsonVO<string> PurOrderController::execModifyPurOrder(const PurOrderDTO& dto)
{
	//����һ��Service
	PurOrderService service;

	JsonVO<string> result;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	return result;
}

// �޸�״̬
JsonVO<string> PurOrderController::execStatusPurOrder(const PurOrderDTO& dto)
{
	JsonVO<string> result;
	PurOrderService service;

	if (service.updateStatus(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	return result;
}
//ɾ������
JsonVO<string> PurOrderController::execRemovePurOrder(const PurOrderDTO& dto)
{
	//����һ��Service
	PurOrderService service;

	JsonVO<string> result;
	//ִ������ɾ��
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//��Ӧ���
	return result;
}
//ɾ������byId
JsonVO<string> PurOrderController::execRemoveById(const StringID& id)
{
	// ����У��
	if (id.getId() == "") return JsonVO<string>({}, RS_PARAMS_INVALID);
	PurOrderDTO dto;
	dto.setId(id.getId());
	return execRemovePurOrder(dto);
}