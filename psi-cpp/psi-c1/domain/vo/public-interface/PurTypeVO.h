#ifndef _PURTYPE_VO_
#define _PURTYPE_VO_

#include "../../GlobalInclude.h"

/*
�ɹ����������б�
Author C1-��ľ
2023.2.11 18��40��
*/
class PurTypeVO
{
	// ���ͱ��
	CC_SYNTHESIZE(string, id, Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(PurTypeVO, id, name);
};

#endif // _PurTYPE_VO_
