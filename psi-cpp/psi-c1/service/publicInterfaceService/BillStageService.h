#ifndef _BILLSTAGE_SERVICE_
#define _BILLSTAGE_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/BillStageVO.h"

/*
���ݽ׶������б�
Author C1-��ľ
*/

class BillStageService
{
public:
	list<BillStageVO> listAll();
};
#endif // !_BILLSTAGE_SERVICE_