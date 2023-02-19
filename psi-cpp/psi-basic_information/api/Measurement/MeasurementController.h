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
#ifndef _Measurement_CONTROLLER_
#define _Measurement_CONTROLLER_

#include "../../domain/query/Measurement/MeasurementQuery.h"
#include "../../domain/dto/Measurement/MeasurementDTO.h"
#include "../../domain/dto/IDDTO.h"
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
	CREATE_API_FUN_QUERY_PAYLOAD(queryMeasurement, execQueryMeasurement, MeasurementQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryKidMeasuremnet, execQueryKidMeasurement, MeasurementQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailMeasurement, execQueryDetailMeasurement, MeasurementQuery);
	CREATE_API_FUN_BODY(addMeasurement, execAddMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY(modifyMeasurement, execModifyMeasurement, MeasurementDTO);
	CREATE_API_FUN_BODY(removeMeasurement, execRemoveMeasurement, MeasurementQuery);
	CREATE_API_FUN_BODY_FILE(addFileMeasurements, execAddFileMeasurements, MeasurementDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, MeasurementQuery);

private:
	//��˴����ǰ��JsonVO
	//��ͨ��ѯ(��ҳ��ѯ)
	JsonVO<PageVO<MeasurementVO>> execQueryMeasurement(const MeasurementQuery& query, const PayloadDTO& payload);
	//��ѯָ����λ�Ӽ��б�
	JsonVO<MeasurementVO> execQueryKidMeasurement(const MeasurementQuery& query, const PayloadDTO& payload);
	//��ѯָ����λ��ϸ��Ϣ
	JsonVO<MeasurementVO> execQueryDetailMeasurement(const MeasurementQuery& query, const PayloadDTO& payload);
	//��Ӽ�����λ
	JsonVO<PageVO<MeasurementVO>> execAddMeasurement(const MeasurementDTO& dto);
	//�޸ļ�����λ
	JsonVO<PageVO<MeasurementVO>> execModifyMeasurement(const MeasurementDTO& dto);
	//ɾ��������λ(ͨ������ɾ��)
	JsonVO<PageVO<MeasurementVO>> execRemoveMeasurement(const MeasurementDTO& dto);
	//�ļ�����
	JsonVO<PageVO<MeasurementVO>> execAddFileMeasurements(const MeasurementDTO& dto);
	//�ļ�����
	JsonVO<string> execExportExecl(const MeasurementQuery& query, const PayloadDTO& payload);
};

#endif // _Measurement_CONTROLLER_