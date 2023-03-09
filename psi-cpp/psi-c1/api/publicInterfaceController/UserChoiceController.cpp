#include "stdafx.h"
#include "UserChoiceController.h"
#include "../../service/publicInterfaceService/UserChoiceService.h"


JsonVO<PageVO<UserVO>> UserChoiceController::execQueryUser(const UserQuery& query, const PayloadDTO& payload)
{
	//pageindex��pagesize���쳣����
	if (query.getPageIndex() < 0 || query.getPageSize() <= 0)
		return JsonVO<PageVO<UserVO>>(PageVO<UserVO>(), RS_PARAMS_INVALID);
	UserChoiceService service;
	PageVO<UserVO> result = service.listAll(query);
	//��Ӧ���
	JsonVO<PageVO<UserVO>> rs(result, RS_SUCCESS);
	return rs;
}
