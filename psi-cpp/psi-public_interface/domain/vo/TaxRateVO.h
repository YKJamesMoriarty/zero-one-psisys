#ifndef _TAXRATE_VO_
#define _TAXRATE_VO_

#include "../GlobalInclude.h"

/*
˰��
Author C1-��ľ
2023.2.11 18��34��
*/
class TaxRateVO
{
	// ˰�ʱ��
	CC_SYNTHESIZE(int, id, Id);
	// ˰�ʵȼ�
	CC_SYNTHESIZE(string, rate, Rate);
public:
	// ��JSONת������
	BIND_TO_JSON(TaxRateVO, id, rate);
};

#endif // _TAXRATE_VO_
