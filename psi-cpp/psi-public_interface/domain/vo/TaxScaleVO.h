#ifndef _TAXSCALE_VO_
#define _TAXSCALE_VO_

#include "../GlobalInclude.h"

/*
��˰��ģ
Author C1-��ľ
2023.2.11 18��36��
*/
class TaxScaleVO
{
	// ģʽ���
	CC_SYNTHESIZE(int, id, Id);
	// ģʽ����
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(TaxScaleVO, id, name);
};

#endif // _TAXSCALE_VO_
