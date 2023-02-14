#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/14 18:35:30

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




#include "../../domain/query/MaterialClassification/MaterialClassificationQuery.h"
#include "../../domain/dto/MaterialClassification/MaterialClassificationDTO.h"
#include "../../domain/vo/MaterialClassification/MaterialClassificationVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"



/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class MaterialClassificationController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryMaterialClassification, execQueryMaterialClassification, MaterialClassificationQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryMaterialClassificationChild, execQueryMaterialClassificationChild,MaterialClassificationChildQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryMaterialClassificationDetail, execQueryMaterialClassificationDetail,MaterialClassificationDetailQuery);
	CREATE_API_FUN_BODY(addMaterialClassification, execAddMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY(modifyMaterialClassification, execModifyMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY(removeMaterialClassification, execRemoveMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_BODY_FILE(importMaterialClassification, execImportMaterialClassification, MaterialClassificationDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportMaterialClassification, execExportMaterialClassification, MaterialClassificationQuery);
private:

	//��ͨ��ѯ
	JsonVO<PageVO<MaterialClassificationVO>> execQueryMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload);

	//��ѯ�Ӽ��б�   ��ʱ�Ȳ���ҳ��ʾ
	JsonVO<MaterialClassificationVO> execQueryMaterialClassificationChild(const MaterialClassificationChildQuery& query, const PayloadDTO& payload);
	
	//��ѯָ��������ϸ��Ϣ
	JsonVO<MaterialClassificationVO> execQueryMaterialClassificationDetail(const MaterialClassificationDetailQuery& query, const PayloadDTO& payload);


	//��������
	JsonVO<MaterialClassificationVO> execAddMaterialClassification(const MaterialClassificationDTO& dto);
	//�޸ķ���
	JsonVO<MaterialClassificationVO> execModifyMaterialClassification(const MaterialClassificationDTO& dto);
	//ɾ������
	JsonVO<MaterialClassificationVO> execRemoveMaterialClassification(const MaterialClassificationDTO& dto);
	
	//�ļ�����
	JsonVO<PageVO<MaterialClassificationVO>> execImportMaterialClassification(const MaterialClassificationDTO& dto);
	//�ļ�����
	JsonVO<string> execExportMaterialClassification(const MaterialClassificationQuery& query, const PayloadDTO& payload);
};

