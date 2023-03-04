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
#ifndef _MEASUREMENT_SERVICE_
#define _MEASUREMENT_SERVICE_
#include <list>
#include "../../domain/vo/measurement/MeasurementVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/query/measurement/MeasurementQuery.h"
#include "../../domain/dto/Measurement/MeasurementDTO.h"
#include "../../../lib-http/include/JWTUtil.h"

/**
 * ������λ����ʵ��
 */
class MeasurementService
{
public:
	// ��ҳ��ѯ��������
	PageVO<MeasurementVO> listAll(const MeasurementQuery& query);
	//��ѯָ����λ���Ӽ��б�
	list<MeasurementVO> queryKidData(const MeasurementKidQuery& query);
	//��ѯָ����λ����ϸ��Ϣ
	MeasurementVO queryDetailData(const MeasurementAppQuery& query);
	// ������¼��λ
	MeasurementVO save(const MeasurementDTO& dto, const PayloadDTO& payload);
	// ����������λ
	string saveData(const MeasurementDTO& dto, const PayloadDTO& payload);
	// ����������λ���Ӽ�������λ
	string saveKidData(const MeasurementDTO& dto, const PayloadDTO& payload);
	// �޸�����
	MeasurementVO updateData(const MeasurementModifyDTO& dto, const PayloadDTO& payload);
	//ɾ������
	bool removeData(const string& id);
	//�ļ�����
	bool saveFileData(const MeasurementDTO& dto, const PayloadDTO& payload);
	//�ļ�����
	bool getData(const StringIDs& dto, vector<vector<string>>& data);
};

#endif // !_Measurement_SERVICE_