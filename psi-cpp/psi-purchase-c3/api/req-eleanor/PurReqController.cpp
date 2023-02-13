#include "stdafx.h"
#include "PurReqController.h"
#include "../../service/req-eleanor/PurReqService.h"

//����
nlohmann::json PurReqController::execPurReqExportInfo(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	PurReqService service;
	std::string result = service.purReqExportData(dto);

	//��Ӧ���
	return JsonVO<std::string>(result, RS_SUCCESS);
}

//����
nlohmann::json PurReqController::execPurReqIntoInfo(const PurReqIntoDTO& dto)
{
	//����һ������VO
	UserVO vo;


	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}

	//��Ӧ���
	return JsonVO<UserVO>(vo, RS_SUCCESS);
}
