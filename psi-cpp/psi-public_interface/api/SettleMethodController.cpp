#include "stdafx.h"
#include "SettleMethodController.h"

/**
 *Author c1-ruizi
 * 2023/2/13  16:40
 * �ӿڣ����㷽ʽ
 */

JsonVO<list<SettleMethodVO>> SettleMethodController::executequerySettleMethod()
{
	list<SettleMethodVO> data;
	SettleMethodVO vo;
	vo.setId(1);
	vo.setName(u8"�����");
	data.push_back(vo);
	JsonVO<list<SettleMethodVO>> res;
	res.success(data);
	return res;
}