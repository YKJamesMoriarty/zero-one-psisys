#pragma once

#ifndef _ISENABLEDVO_H_
#define _ISENABLEDVO_H_
#include "../../GlobalInclude.h"

/*
* �Ƿ�����ѡ��
* @Author: Oxygen
* @Date: 2023/2/13 20:24:33
*/
class IsEnabledVO
{
	// ���ͱ��
	CC_SYNTHESIZE(int, id, Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(IsEnabledVO, id, name);
};

#endif // _ISENABLED_H_
