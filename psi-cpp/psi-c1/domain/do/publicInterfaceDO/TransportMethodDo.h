/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ����䷽ʽ
 */

#pragma once
#ifndef _TRANSPORTMETHOD_DO_
#define _TRANSPORTMETHOD_DO_
#include "../DoInclude.h"

 /**
  * ���ݿ�ʵ����
  */
class TransportMethodDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ������
	CC_SYNTHESIZE(string, name, Name);
public:
	TransportMethodDO() {
		id = "";
		name = "";
	}
};

#endif // !_TRANSPORTMETHOD_DO_