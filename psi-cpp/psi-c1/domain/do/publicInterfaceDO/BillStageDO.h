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
	CC_SYNTHESIZE(int, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	BillStageDO() {
		id = 0;
		name = "";
	}
};


#endif // !_BILLSTAGE_DO_
