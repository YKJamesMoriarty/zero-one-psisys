#pragma once
#ifndef _SUC_VO_
#define _SUC_VO_

#include "../../GlobalInclude.h"

/**
 * ִ���Ƿ�ɹ���ʾ����
 */
class SucVO
{
	// ִ���Ƿ�ɹ�
	CC_SYNTHESIZE(uint64_t, suc, Suc);
public:
	// ��JSONת������
	BIND_TO_JSON(SucVO, suc);
};

#endif