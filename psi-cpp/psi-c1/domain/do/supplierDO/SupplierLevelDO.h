#ifndef _SUPPLIERLEVEL_DO_
#define _SUPPLIERLEVEL_DO_
#include "../DoInclude.h"

/*
��Ӧ�̵ȼ������б�
Author C1-��ľ
*/

class SupplierLevelDO
{
	// �׶α��
	CC_SYNTHESIZE(string, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	SupplierLevelDO() {
		id = "";
		name = "";
	}
};


#endif // !_SUPPLIERLEVEL_DO_