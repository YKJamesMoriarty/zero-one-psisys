#ifndef _SUPPLIERLEVEL_DO_
#define _SUPPLIERLEVEL_DO_
#include "../DoInclude.h"

/*
���ݽ׶������б�
Author C1-��ľ
*/

class SupplierLevelDO
{
	// �׶α��
	CC_SYNTHESIZE(int, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	SupplierLevelDO() {
		id = 0;
		name = "";
	}
};


#endif // !_SUPPLIERLEVEL_DO_