#include "stdafx.h"
#include "InvoiceTypeController.h"

/**
 *Author c1-ruizi
 * 2023/2/13  16:40
 * �ӿڣ���Ʊ����
 */

JsonVO<list<InvoiceTypeVO>> InvoiceTypeController::executequeryInvoiceType()
{
	list<InvoiceTypeVO> data;
	InvoiceTypeVO vo;
	vo.setId(1);
	vo.setName(u8"�����");
	data.push_back(vo);
	JsonVO<list<InvoiceTypeVO>> res;
	res.success(data);
	return res;
}