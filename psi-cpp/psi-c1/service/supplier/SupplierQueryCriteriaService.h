#ifndef _SUPPLIERQUERYCRITERIA_SERVICE_
#define _SUPPLIERQUERYCRITERIA_SERVICE_

#include <list>
#include "../../domain/vo/supplier/SupplierQueryCriteriaVO.h"

/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
*/

class SupplierQueryCriteriaService
{
public:
	list<SupplierQueryCriteriaVO> listAll();
};
#endif // !_SUPPLIERQUERYCRITERIA_SERVICE_