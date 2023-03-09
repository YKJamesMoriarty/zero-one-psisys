#include"stdafx.h"
#include"MaterialQueryController.h"
#include "../../service/public-interface/MaterialService.h"

JsonVO<PageVO<MaterialVO>>MaterialQueryController::execQueryMaterial(const MaterialQuery& query, const PayloadDTO& payload)
{
	//pageindex��pagesize���쳣����
	if (query.getPageIndex() < 0 || query.getPageSize() <= 0)
		return JsonVO<PageVO<MaterialVO>>(PageVO<MaterialVO>(), RS_PARAMS_INVALID);
	MaterialService service;
	PageVO<MaterialVO> result = service.listAll(query);
	//��Ӧ���
	return JsonVO<PageVO<MaterialVO>>(result, RS_SUCCESS);
}