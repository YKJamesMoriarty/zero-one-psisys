
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/14 20:21:24

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
#include "MaterialClassificationController.h"
#include"../../service/MaterialClassification/MaterialClassificationService.h"

//payload��ʹ���ߵ���Ϣ
JsonVO<PageVO<MaterialClassificationBaseVO>> MaterialClassificationController::execQueryMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	MaterialClassificationService service;
	//��ѯ����
	PageVO<MaterialClassificationBaseVO> result = service.listAll(query);
	//��Ӧ���

	//����У��
	if (query.getCode() == "")
		return JsonVO<PageVO< MaterialClassificationBaseVO>>({}, RS_PARAMS_INVALID);

	return JsonVO<PageVO<MaterialClassificationBaseVO>>(result, RS_SUCCESS);

}

//��ѯ�����б�
JsonVO<list<MaterialClassificationChildVO>> MaterialClassificationController::execQueryMaterialClassificationChild(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	MaterialClassificationService service;

	//��ѯ�Ӽ�����

	list<MaterialClassificationChildVO> result = service.listChildren(query);
	//��Ӧ���
	if (query.getCode() == "")
		return JsonVO<list<MaterialClassificationChildVO>>({}, RS_PARAMS_INVALID);

	return JsonVO<list<MaterialClassificationChildVO>>(result, RS_SUCCESS);
}

JsonVO<list<MaterialClassificationDetailVO>> MaterialClassificationController::execQueryMaterialClassificationDetail(const MaterialClassificationQuery& query, const PayloadDTO& payload)
{

	//����һ��Service
	MaterialClassificationService service;

	//��ѯ��ϸ���ݣ��о����Ǳ༭���
	list<MaterialClassificationDetailVO> result = service.listDetail(query);

	//��Ӧ���
	if (query.getCode() == "")
		return JsonVO<list<MaterialClassificationDetailVO>>({}, RS_PARAMS_INVALID);

	return JsonVO<list<MaterialClassificationDetailVO>>(result, RS_SUCCESS);;
}

JsonVO<uint64_t> MaterialClassificationController::execAddMaterialClassification(const MaterialClassificationDTO& dto)
{
	JsonVO<uint64_t> result;
	MaterialClassificationService service;
	//ִ���������� #���ص����кţ�
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���

	return result;
}

JsonVO<uint64_t> MaterialClassificationController::execModifyMaterialClassification(const MaterialClassificationDTO& dto)
{
	JsonVO<uint64_t> result;
	MaterialClassificationService service;
	uint64_t id = service.updateData(dto);
	if (id>0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}

	return result;

}

JsonVO<uint64_t> MaterialClassificationController::execRemoveMaterialClassification(const MaterialClassificationDTO& dto)
{
	JsonVO<uint64_t> result;
	MaterialClassificationService service;
	uint64_t id = service.removeData(dto.getId());
	//ִ������ɾ��
	if (id>0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	return result;

}

//�ļ�����
JsonVO<PageVO<MaterialClassificationBaseVO>> MaterialClassificationController::execImportMaterialClassification(const MaterialClassificationDTO& dto) {
	JsonVO<PageVO<MaterialClassificationBaseVO>> result;
	//��Ӧ���
	return result;
}

JsonVO<string> MaterialClassificationController::execExportMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload) {
	JsonVO<string> result;
	//��Ӧ���
	return result;
}
