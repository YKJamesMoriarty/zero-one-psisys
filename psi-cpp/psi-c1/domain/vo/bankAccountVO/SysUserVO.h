#pragma once

#ifndef _SYSUSERVO_H_
#define _SYSUSERVO_H_
#include "../../GlobalInclude.h"

/*
* �˻�����Աѡ��
* @Author: Oxygen
* @Date: 2023/2/12 18:59:32
*/
class SysUserVO
{
	// ���ͱ��
	CC_SYNTHESIZE(int, id, Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(SysUserVO, id, name);
};

#endif // _SYSUSERVO_H_