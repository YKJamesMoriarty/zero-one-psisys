#ifndef _SUPPLIERLEVEL_VO_
#define _SUPPLIERLEVEL_VO_

#include "../../GlobalInclude.h"

/*
��Ӧ�̵ȼ������б�
Author C1-��ľ
2023.2.11 21��00��
*/
class SupplierLevelVO
{
	// �ȼ����
	CC_SYNTHESIZE(int, id, Id);
	// �ȼ�����
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(SupplierLevelVO, id, name);
};

#endif // _SUPPLIERLEVEL_VO_

