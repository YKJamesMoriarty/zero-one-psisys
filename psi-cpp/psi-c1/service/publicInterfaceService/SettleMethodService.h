/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * �ӿڣ����㷽ʽ
 */

#ifndef _SETTLEMETHOD_SERVICE_
#define _SETTLEMETHOD_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/SettleMethodVO.h"


class SettleMethodService
{
public:
	//�����б�
	list<SettleMethodVO> listAll();
};
#endif // !_SETTLEMETHOD_SERVICE_