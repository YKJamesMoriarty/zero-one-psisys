/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ����䷽ʽ
 */

#ifndef _TRANSPORTMETHOD_SERVICE_
#define _TRANSPORTMETHOD_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/TransportMethodVO.h"


class TransportMethodService
{
public:
	//�����б�
	list<TransportMethodVO> listAll();
};
#endif // !_TRANSPORTMETHOD_SERVICE_