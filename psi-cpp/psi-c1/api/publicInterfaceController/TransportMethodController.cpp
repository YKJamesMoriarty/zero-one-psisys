#include "stdafx.h"
#include "TransportMethodController.h"
#include "../../service/publicInterfaceService/TransportMethodService.h"

/**
 *Author c1-ruizi
 * 2023/2/13  16:46
 * �ӿڣ����䷽ʽ
 */

JsonVO<list<TransportMethodVO>> TransportMethodController::executequeryTransportMethod()
{
	TransportMethodService service;
	list<TransportMethodVO> data = service.listAll();
	//JsonVO<list<SettleMethodVO>> res;
	return JsonVO<list<TransportMethodVO>>(data, RS_SUCCESS);
}