#include "stdafx.h"
#include "areaController.h"


//��ʱ������ʵϰ�û�apipost����

JsonVO<PageVO<AreaVO>> AreaController::execQueryArea(const AreaQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<AreaVO>>rs;
	PageVO<AreaVO>data;
	rs.success(data);
	return rs;
}
