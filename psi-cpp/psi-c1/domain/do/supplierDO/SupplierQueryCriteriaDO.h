#ifndef _SUPPLIERQUERYCRITERIA_DO_
#define _SUPPLIERQUERYCRITERIA_DO_
#include "../DoInclude.h"

/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
*/

class SupplierQueryCriteriaDO
{
	// �׶α��
	CC_SYNTHESIZE(string, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	SupplierQueryCriteriaDO() {
		id = "";
		name = "";
	}
};


#endif // !_SUPPLIERQUERYCRITERIA_DO_