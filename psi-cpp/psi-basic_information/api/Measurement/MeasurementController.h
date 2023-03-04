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
#ifndef _MEASUREMENT_CONTROLLER_
#define _MEASUREMENT_CONTROLLER_

#include "../../domain/query/Measurement/MeasurementQuery.h"
#include "../../domain/dto/Measurement/MeasurementDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/Measurement/MeasurementVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * �������ϼ�����λģ��ӿ�
 */
class MeasurementController
{
public:
	//ǰ�˴������˵ĸ�������
	CREATE_API_FUN_QUERY(queryMeasurement, execQueryMeasurement, MeasurementQuery);
	CREATE_API_FUN_QUERY(queryKidMeasurement, execQueryKidMeasurement, MeasurementKidQuery);
	CREATE_API_FUN_QUERY(queryDetailMeasurement, execQueryDetailMeasurement, MeasurementAppQuery);
	CREATE_API_FUN_BODY_PAYLOAD(addMeasurement, execAddMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyMeasurement, execModifyMeasurement, MeasurementModifyDTO);
	CREATE_API_FUN_BODY(removeMeasurement, execRemoveMeasurement, MeasurementDeleteDTO);
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addFileMeasurement, execImportFileMeasurement, MeasurementDTO);
	CREATE_API_FUN_JSON(exportExecl, execExportExcel, StringIDs);
private:
	//��˴����ǰ��JsonVO
	//��ͨ��ѯ(��ҳ��ѯ)
	JsonVO<PageVO<MeasurementVO>> execQueryMeasurement(const MeasurementQuery& query);
	//��ѯָ����λ�Ӽ��б�
	JsonVO<list<MeasurementVO>> execQueryKidMeasurement(const MeasurementKidQuery& query);
	//��ѯָ����λ��ϸ��Ϣ
	JsonVO<MeasurementVO> execQueryDetailMeasurement(const MeasurementAppQuery& query);
	//����������λ
	JsonVO<MeasurementVO> execAddMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload);
	//����������λ���Ӽ�������λ
	//JsonVO<MeasurementVO> execAddKidMeasurement(const MeasurementKidDTO& dto, const PayloadDTO& payload);
	//�޸ļ�����λ
	JsonVO<MeasurementVO> execModifyMeasurement(const MeasurementModifyDTO& dto, const PayloadDTO& payload);
	//ɾ��������λ
	JsonVO<string> execRemoveMeasurement(const MeasurementDeleteDTO& dto);
	//�ļ�����
	//JsonVO<string> execImportFileMeasurement(const MeasurementImportFileDTO& dto, const PayloadDTO& payload);
	JsonVO<bool> execImportFileMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload);
	//�ļ�����
	JsonVO<string> execExportExcel(const StringIDs& dto);
};

#endif // !_MEASUREMENT_CONTROLLER_