#ifndef _SETTLEMETHOD_VO_
#define _SETTLEMETHOD_VO_

#include "../../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/13  15:46
 * �ӿڣ����㷽ʽ
 */

class SettleMethodVO
{
	// ��ʽ���
	CC_SYNTHESIZE(int, id, Id);
	// ��ʽ����
	CC_SYNTHESIZE(string, name, Name);

public:
	// ��JSONת������
	BIND_TO_JSON(SettleMethodVO, id, name);
};

#endif //_SETTLEMETHOD_VO_