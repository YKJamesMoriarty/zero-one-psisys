#include "stdafx.h"
#include "TransportMethodController.h"

/**
 *Author c1-ruizi
 * 2023/2/13  16:46
 * �ӿڣ����䷽ʽ
 */

JsonVO<list<TransportMethodVO>> TransportMethodController::executequeryTransportMethod()
{
	list<TransportMethodVO> data;
	TransportMethodVO vo;
	vo.setId(1);
	vo.setName(u8"�����");
	data.push_back(vo);
	JsonVO<list<TransportMethodVO>> res;
	res.success(data);
	return res;
}