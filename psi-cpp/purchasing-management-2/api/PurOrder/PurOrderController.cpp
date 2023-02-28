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
JsonVO<PageVO<PurOrderVO>> PurOrderController::execQueryListPurOrder(const PurOrderQuery& query, const PayloadDTO& payload)
{
	PurOrderService service;
	PageVO<PurOrderVO> result=service.listPurOrder(query);
	return JsonVO<PageVO<PurOrderVO>>(result, RS_SUCCESS);
}

// ��ѯ��������byDTO
JsonVO<PurOrderDetailVO> PurOrderController::execGetPurOrder(const PurOrderDTO& dto)
{
	PurOrderService service;
	PurOrderDetailVO result = service.getPurOrder(dto.getBill_no());
	if(result.getBill_no().empty()) return  JsonVO(result, RS_FAIL);
	JsonVO<PurOrderDetailVO> jsresult = JsonVO(result, RS_SUCCESS);

	return jsresult;
}

// ��������
JsonVO<uint64_t> PurOrderController::execAddPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	//����һ��Service
	PurOrderService service;

	//ִ����������
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.setStatus(RS_SUCCESS);
	}
	else if(id == -1)
	{
		result.setStatus(RS_PARAMS_INVALID); // 9995
		return result;
	}
	else
	{
		result.setStatus(RS_FAIL); // 9999
	}
	return result;
}
// �޸�����
JsonVO<uint64_t> PurOrderController::execModifyPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	//����һ��Service
	PurOrderService service;

	JsonVO<uint64_t> result;
	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		result.setStatus(RS_SUCCESS);
	}
	else if (id == -1)
	{
		result.setStatus(RS_PARAMS_INVALID); // 9995
		return result;
	}
	else
	{
		result.setStatus(RS_FAIL); // 9999
	}
	return result;
}

// �޸�״̬
JsonVO<uint64_t> PurOrderController::execStatusPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurOrderService service;

	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		result.setStatus(RS_SUCCESS);
	}
	else if (id == -1)
	{
		result.setStatus(RS_PARAMS_INVALID); // 9995
		return result;
	}
	else
	{
		result.setStatus(RS_FAIL); // 9999
	}
	return result;
}
//ɾ������
JsonVO<uint64_t> PurOrderController::execRemovePurOrder(const PurOrderDTO& dto)
{
	//����һ��Service
	PurOrderService service;

	JsonVO<uint64_t> result;
	//ִ������ɾ��
	//if (service.removeData(dto.getId())) {
	//	result.success(dto.getId());
	//}
	//else
	//{
	//	result.fail(dto.getId());
	//}
	//��Ӧ���
	return result;
}
//ɾ������byId
JsonVO<uint64_t> PurOrderController::execRemoveById(const IntID& id)
{
	PurOrderDTO dto;
	//dto.setId(id.getId());
	return execRemovePurOrder(dto);
}