#include "stdafx.h"
#include "PurReqController.h"
#include "../../service/req-eleanor/PurReqService.h"

//����
nlohmann::json PurReqController::execPurReqExportInfo(const PurReqExportDTO& dto, const PayloadDTO& payload)
{
	//��Ӧ���
	return JsonVO<std::string>();
}

//����
JsonVO<PurReqIntoVO> PurReqController::execPurReqIntoInfo(const PurReqIntoDTO& dto)
{
	//��Ӧ���
	return JsonVO<PurReqIntoVO>();
}
