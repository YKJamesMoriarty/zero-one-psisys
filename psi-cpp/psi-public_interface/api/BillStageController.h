#ifndef _BILLSTAGE_CONTROLLER_
#define _BILLSTAGE_CONTROLLER_

#include "domain/vo/JsonVO.h"
#include "domain/vo/BillStageVO.h"
#include "api/ApiHelper.h"

/*
���ݽ׶������б�
Author C1-��ľ
2023.2.11 20��45��
*/
class BillStageController
{
public:
	CREATE_API_FUN_QUERY3(queryBillStage, executequeryBillStage);
private:
	JsonVO<list<BillStageVO>> executequeryBillStage();
};

#endif //_BILLSTAGE_CONTROLLER_