#include "stdafx.h"
#include "InvoiceTypeController.h"
#include "../../service/publicInterfaceService/InvoiceTypeService.h"

/**
 *Author c1-ruizi
 * 2023/2/13  16:40
 * �ӿڣ���Ʊ����
 */

JsonVO<list<InvoiceTypeVO>> InvoiceTypeController::executequeryInvoiceType()
{
	InvoiceTypeService service;
	list<InvoiceTypeVO> data = service.listAll();
	//JsonVO<list<SettleMethodVO>> res;
	return JsonVO<list<InvoiceTypeVO>>(data, RS_SUCCESS);
}