#ifndef _SUPPLIERQUERYCRITERIA_CONTROLLER_
#define _SUPPLIERQUERYCRITERIA_CONTROLLER_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/supplierVO/SupplierQueryCriteriaVO.h"
#include "api/ApiHelper.h"

/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
2023.2.13 21��10��
*/
class SupplierQueryCriteriaController
{
public:
	CREATE_API_FUN_QUERY3(querySupplierQueryCriteria, executequerySupplierQueryCriteria);
private:
	JsonVO<list<SupplierQueryCriteriaVO>> executequerySupplierQueryCriteria();
};

#endif //_SUPPLIERQUERYCRITERIA_CONTROLLER_