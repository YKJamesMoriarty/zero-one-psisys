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
	CC_SYNTHESIZE(string, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	TaxRateDO() {
		id = "";
		name = "";
	}
};


#endif // !_TAXRATE_DO_