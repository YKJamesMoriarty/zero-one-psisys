#ifndef _TAXSCALE_CONTROLLER_
#define _TAXSCALE_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/publicInterfaceVO/TaxScaleVO.h"
#include "api/ApiHelper.h"

/*
��˰��ģ�����б�
Author C1-��ľ
2023.2.11 20��55��
*/
class TaxScaleController
{
public:
	CREATE_API_FUN_QUERY3(queryTaxScale, executequeryTaxScale);
private:
	JsonVO<list<TaxScaleVO>> executequeryTaxScale();
};

#endif // _TAXSCALE_CONTROLLER_
