#include "stdafx.h"
#include "BillStageController.h"
#include "../../service/public-interface/BillStageService.h"
#include "../../domain/vo/public-interface/BillStageVO.h"
/*
���ݽ׶������б�
Author C1-��ľ
*/

JsonVO<list<BillStageVO>> BillStageController::executequeryBillStage()
{
	BillStageService service;
	list<BillStageVO> data = service.listAll();
	JsonVO<list<BillStageVO>> res;
	res.success(data);
	return res;
}
