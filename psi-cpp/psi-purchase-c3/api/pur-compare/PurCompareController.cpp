/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:57:26

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
#include "PurCompareController.h"
#include "../../service/pur-compare/PurCompareService.h"

JsonVO<PageVO<PurComFindBillVO>> PurCompareController::execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload)
{
	//����У��
	//����һ��Service
	PurCompareService service;
	//��ѯ����
	PageVO<PurComFindBillVO> result = service.listPurComFindBill(query);
	//��Ӧ���
	return JsonVO<PageVO<PurComFindBillVO>>(result, RS_SUCCESS);
}

JsonVO<PurComFindDetailBillVO> PurCompareController::execQueryPurComFindDetailBill(const PurComFindDetailBillQuery& query, const PayloadDTO& payload)
{
	PurComFindDetailBillVO result;
	//����У��
	if (query.getBillNo() == "") return JsonVO<PurComFindDetailBillVO>(result, RS_PARAMS_INVALID);
	//����һ��Service
	PurCompareService service;
	//��ѯ����
	result = service.getPurComFindDetailBill(query);
	//��Ӧ���
	return JsonVO<PurComFindDetailBillVO>(result, RS_SUCCESS);
}

JsonVO<list<PurComListVO>> PurCompareController::execQueryPurComList(const PurComListQuery& query, const PayloadDTO& payload)
{
	list<PurComListVO> result;
	//����У��
	if (query.getBillNo()=="") return JsonVO<list<PurComListVO>>(result, RS_PARAMS_INVALID);
	//����һ��Service
	PurCompareService service;
	//��ѯ����
	result = service.listPurComList(query);
	//��Ӧ���
	return JsonVO<list<PurComListVO>>(result, RS_SUCCESS);
}

JsonVO<list<PurComDividedListVO>> PurCompareController::execQueryPurComDividedList(const PurComDividedListQuery& query, const PayloadDTO& payload)
{
	list<PurComDividedListVO> result;
	//����У��
	if (query.getBillNo() == "") return JsonVO<list<PurComDividedListVO>>(result, RS_PARAMS_INVALID);
	//����һ��Service
	PurCompareService service;
	//��ѯ����
	result = service.listPurComDividedList(query);
	//��Ӧ���
	return JsonVO<list<PurComDividedListVO>>(result, RS_SUCCESS);
}

//��ʾ�����ȼ�
JsonVO<uint64_t> PurCompareController::execAddPurCom(const AddPurComDTO& dto, PayloadDTO payload)
{
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.savePurCom(dto, payload);
	if (id > 0)
	{
		result.success(id);
	}
	else
	{
		result.fail(id);
	}

	return result;
}
//��ʾ�޸ıȼ�
JsonVO<uint64_t> PurCompareController::execModifyPurCom(const ModPurComDTO& dto, PayloadDTO payload) {
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.updatePurCom(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}

	return result;
}
//��ʾɾ���ȼ�
JsonVO<uint64_t> PurCompareController::execRemovePurCom(const DelPurComDTO& dto) {
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.removePurCom(dto);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}
	return result;
}
//��ʾ�޸ĵ���״̬
JsonVO<uint64_t> PurCompareController::execPurComModBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload) {
	JsonVO<uint64_t> result;
	PurCompareService service;
	uint64_t id = service.updatePurComBillStatus(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else {
		result.fail(id);
	}

	return result;
}

