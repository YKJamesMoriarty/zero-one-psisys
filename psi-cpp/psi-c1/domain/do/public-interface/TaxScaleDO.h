#ifndef _TAXSCALE_DO_
#define _TAXSCALE_DO_
#include "../DoInclude.h"

/*
��˰��ģ�����б�
Author C1-��ľ
*/

class TaxScaleDO
{
	// �׶α��
	CC_SYNTHESIZE(string, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	TaxScaleDO() {
		id = "";
		name = "";
	}
};


#endif // !_TAXSCALE_DO_