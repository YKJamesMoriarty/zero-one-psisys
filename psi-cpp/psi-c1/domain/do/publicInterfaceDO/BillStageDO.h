#ifndef _BILLSTAGE_DO_
#define _BILLSTAGE_DO_
#include "../DoInclude.h"

/*
���ݽ׶������б�
Author C1-��ľ
*/

class BillStageDO
{
	// �׶α��
	CC_SYNTHESIZE(string, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	BillStageDO() {
		id = "";
		name = "";
	}
};


#endif // !_BILLSTAGE_DO_
