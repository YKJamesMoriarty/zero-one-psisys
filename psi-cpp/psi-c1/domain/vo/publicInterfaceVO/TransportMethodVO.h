#ifndef _TRANSPORTMETHOD_VO_
#define _TRANSPORTMETHOD_VO_

#include "../../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/13  15:46
 * �ӿڣ����䷽ʽ
 */

class TransportMethodVO
{
	// ��ʽ���
	CC_SYNTHESIZE(int, id, Id);
	// ��ʽ����
	CC_SYNTHESIZE(string, name, Name);

public:
	// ��JSONת������
	BIND_TO_JSON(TransportMethodVO, id, name);
};

#endif //_TRANSPORTMETHOD_VO_