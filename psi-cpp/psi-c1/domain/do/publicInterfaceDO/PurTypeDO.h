#ifndef _PURTYPE_DO_
#define _PURTYPE_DO_
#include "../DoInclude.h"

/*
�ɹ����������б�
Author C1-��ľ
*/

class PurTypeDO
{
	// �׶α��
	CC_SYNTHESIZE(int, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	PurTypeDO() {
		id = 0;
		name = "";
	}
};


#endif // !_PURTYPE_DO_