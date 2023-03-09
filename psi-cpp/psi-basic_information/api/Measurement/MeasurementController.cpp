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
#include "MeasurementController.h"
#include "../../service/Measurement/MeasurementService.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/CharsetConvertHepler.h"
#include "FastDfsClient.h"

//��ͨ��ѯ(��ҳ��ѯ)
JsonVO<PageVO<MeasurementVO>> MeasurementController::execQueryMeasurement(const MeasurementQuery& query)
{
	//����һ��Service
	MeasurementService service;
	//��ѯ����
	JsonVO<PageVO<MeasurementVO>> result;
	PageVO<MeasurementVO> vr = service.listAll(query);
	result.setData(vr);
	//��Ӧ���
	return result;
}


//��ѯָ����λ���Ӽ��б�
JsonVO<list<MeasurementVO>> MeasurementController::execQueryKidMeasurement(const MeasurementKidQuery& query)
{
	//todo:����У��
	if (query.getId() == "")
	{
		return JsonVO<list<MeasurementVO>>({}, RS_PARAMS_INVALID);
	}
	MeasurementService service;
	JsonVO<list<MeasurementVO>> result;
	list<MeasurementVO> rows = service.queryKidData(query);
	result.setData(rows);
	return result;
}

//��ѯָ����λ����ϸ��Ϣ
JsonVO<MeasurementVO> MeasurementController::execQueryDetailMeasurement(const MeasurementAppQuery& query)
{
	//todo:����У��
	if (query.getId() == "")
	{
		return JsonVO<MeasurementVO>({}, RS_PARAMS_INVALID);
	}
	JsonVO<MeasurementVO> result;
	MeasurementService service;
	MeasurementVO vo = service.queryDetailData(query);
	result.success(vo);
	return result;
}

//����������λ
JsonVO<MeasurementVO> MeasurementController::execAddMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	//����У��
	if (dto.getName().empty() ||
		dto.getSymbol().empty() ||
		dto.getFactor() <= 0 ||
		(dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("��")
			&& dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("��")))
	{
		return JsonVO<MeasurementVO>({}, RS_PARAMS_INVALID);
	}

	//ִ������ҵ��
	JsonVO<MeasurementVO> result;
	MeasurementService service;
	MeasurementVO vo = service.save(dto, payload);
	if (vo.getCreate_time().empty())
	{
		result.fail(vo);
	}
	else
	{
		result.success(vo);
	}
	//��Ӧ���
	return result;
}

//�޸ļ�����λ
JsonVO<MeasurementVO> MeasurementController::execModifyMeasurement(const MeasurementModifyDTO& dto, const PayloadDTO& payload)
{
	//����У��
	if (dto.getName().empty() ||
		dto.getSymbol().empty() ||
		dto.getFactor() <= 0 ||
		(dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("��")
			&& dto.getIs_enabled() != CharsetConvertHepler::ansiToUtf8("��")))
	{
		return JsonVO<MeasurementVO>({}, RS_PARAMS_INVALID);
	}
	MeasurementService service;
	MeasurementVO vo = service.updateData(dto, payload);
	JsonVO<MeasurementVO> result;
	result.setData(vo);
	result.success(vo);
	return result;
}

//ɾ��������λ
JsonVO<string> MeasurementController::execRemoveMeasurement(const MeasurementDeleteDTO& dto)
{
	MeasurementService service;
	JsonVO<string> result;
	result.setData(dto.getId());
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

//�ļ�����
JsonVO<bool> MeasurementController::execImportFileMeasurement(const MeasurementDTO& dto, const PayloadDTO& payload)
{
	JsonVO<bool> result;
	MeasurementService service;
	bool flag = service.saveFileData(dto, payload);
	if (flag)
	{
		result.success(true);
	}
	else
	{
		result.fail(false);
	}
	return result;
}

//�ļ�����
JsonVO<string> MeasurementController::execExportExcel(const StringIDs& dto)
{
	MeasurementService service;
	// ����excel��
	string filename = "./public/bas_Unit/bas_Unit.xlsx";
	vector<vector<string>> data;
	data.emplace_back(vector<std::string>({
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ��׼"),
		CharsetConvertHepler::ansiToUtf8("��׼��λ"),
		CharsetConvertHepler::ansiToUtf8("����ϵ��"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ�����"),
		}));
	// ��ѯ����
	if (!service.getData(dto, data))
		return JsonVO<string>(CharsetConvertHepler::ansiToUtf8("����ʧ��"), RS_FAIL);
	string sheetname = CharsetConvertHepler::ansiToUtf8("���㵥λ");
	ExcelComponent excel;
	excel.writeVectorToFile(filename, sheetname, data);
	// �ϴ����ļ�������
#ifdef LINUX
	FastDfsClient client("conf/client.conf", 3);
#else
	FastDfsClient client("1.15.240.108");

#endif // #ifdef LINUX
	filename = client.uploadFile(filename);
	// TODO:����У��
	if (filename.empty())
	{
		JsonVO<string> result(filename, RS_FAIL);
		return result;
	}
	else
	{
		filename = "http://1.15.240.108:8888/" + filename;
		JsonVO<string> result(filename, RS_SUCCESS);
		return result;
	}
}