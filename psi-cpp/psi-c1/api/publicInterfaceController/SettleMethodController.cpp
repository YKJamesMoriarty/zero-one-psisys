#include "stdafx.h"
#include "SettleMethodController.h"
#include "../../service/publicInterfaceService/SettleMethodService.h"

/**
 *Author c1-ruizi
 * 2023/2/13  16:40
 * �ӿڣ����㷽ʽ
 */

JsonVO<list<SettleMethodVO>> SettleMethodController::executequerySettleMethod()
{
	SettleMethodService service;
	list<SettleMethodVO> data = service.listAll();
	//JsonVO<list<SettleMethodVO>> res;
	return JsonVO<list<SettleMethodVO>>(data, RS_SUCCESS);
}