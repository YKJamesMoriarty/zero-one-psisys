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
#ifndef _MATERIALCLASSIFICATION_SERVICE_
#define _MATERIALCLASSIFICATION_SERVICE_
#include "../../domain/vo/MaterialClassification/MaterialClassificationVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/MaterialClassification/MaterialClassificationQuery.h"
#include "../../domain/dto/MaterialClassification/MaterialClassificationDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../lib-common/include/SnowFlake.h"
#include "../../domain/dto/IDDTO.h"
/**
 * ���Ϸ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MaterialClassificationService
{
public:
	// ��ҳ��ѯ�������� #�ƻ��ڸ�������Ƕ������
	PageVO<MaterialClassificationBaseVO> listAll(const MaterialClassificationQuery& query);

	//��ѯ�����б�
	list<MaterialClassificationChildVO> listChildren(const MaterialClassificationQuery& query);

	//��ѯָ��������ϸ��Ϣ
	list<MaterialClassificationDetailVO> listDetail(const MaterialClassificationQuery& query);
	// ��������
	int saveData(const MaterialClassificationDTO& dto, const string& userName);
	// �޸�����
	int updateData(const MaterialClassificationDTO& dto, const PayloadDTO& payload);
	// ͨ��IDɾ������
	int removeData(const MaterialClassificationDTO& dto);

	//��������
	int importData(const MaterialClassificationDTO& dto);

	//��������
	string exportData(const string& id, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_

