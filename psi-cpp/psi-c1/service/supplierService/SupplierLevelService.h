#ifndef _SUPPLIERLEVEL_SERVICE_
#define _SUPPLIERLEVEL_SERVICE_

#include <list>
#include "../../domain/vo/supplierVO/SupplierLevelVO.h"

/*
��Ӧ�̵ȼ������б�
Author C1-��ľ
*/

class SupplierLevelService
{
public:
	list<SupplierLevelVO> listAll();
};
#endif // !_SUPPLIERLEVEL_SERVICE_