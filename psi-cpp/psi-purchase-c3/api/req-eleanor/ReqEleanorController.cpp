#include "stdafx.h"
#include "ReqEleanorController.h"
#include "../../service/req-eleanor/ReqEleanorService.h"



JsonVO<ReqEleanorVO> ReqEleanorController::execModifyReqEleanorInfo(const ReqEleanorDTO& dto)
{
	//����һ������VO
	ReqEleanorVO vo;

	//��������ϴ��ļ�·���б�
	//for (auto file : dto.getFiles()) {
	//	std::cout << "path " << file << std::endl;
	//}

	//��Ӧ���
	return JsonVO<ReqEleanorVO>(vo, RS_API_UN_IMPL);
}
