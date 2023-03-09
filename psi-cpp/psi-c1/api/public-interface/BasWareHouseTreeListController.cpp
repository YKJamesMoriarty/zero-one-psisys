#include "stdafx.h"
#include "BasWareHouseTreeListController.h"
#include"../../service/public-interface/BasWareHouseTreeService.h"

JsonVO<PageVO<BasWareHouseTreeListVO>> BasWareHouseTreeListController::execBasWareHouseTreeList(BasWareHouseItemQuery query)
{
	BasWareHouseTreeService service;
	//��ѯ����
	PageVO<BasWareHouseTreeListVO> result = service.listAll(query);
	//��Ӧ���
	return JsonVO<PageVO<BasWareHouseTreeListVO>>(result, RS_SUCCESS);
}
