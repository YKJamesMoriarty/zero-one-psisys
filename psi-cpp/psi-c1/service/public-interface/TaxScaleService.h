#ifndef _TAXSCALE_SERVICE_
#define _TAXSCALE_SERVICE_

#include<list>
#include "../../domain/vo/public-interface/TaxScaleVO.h"

class TaxScaleService
{
public:
	//��ѯ�ɹ���ʽ�б�
	list<TaxScaleVO> listAll();
};

#endif // !_TAXSCALE_SERVICE_