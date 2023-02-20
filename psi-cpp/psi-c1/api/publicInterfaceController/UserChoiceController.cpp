#include "stdafx.h"
#include "UserChoiceController.h"
#include "../../service/publicInterfaceService/UserChoiceService.h"


JsonVO<PageVO<UserVO>> UserChoiceController::execQueryUser(const UserQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<UserVO>>rs;
	UserChoiceService service;
	PageVO<UserVO> result = service.listAll(query);
	//��Ӧ���
	return JsonVO<PageVO<UserVO>>(result, RS_SUCCESS);
}
