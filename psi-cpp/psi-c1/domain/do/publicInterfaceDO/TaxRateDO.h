#ifndef _TAXRATE_DO_
#define _TAXRATE_DO_
#include "../DoInclude.h"

/*
�ɹ����������б�
Author C1-��ľ
*/

class TaxRateDO
{
	// �׶α��
	CC_SYNTHESIZE(int, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	TaxRateDO() {
		id = 0;
		name = "";
	}
};


#endif // !_TAXRATE_DO_