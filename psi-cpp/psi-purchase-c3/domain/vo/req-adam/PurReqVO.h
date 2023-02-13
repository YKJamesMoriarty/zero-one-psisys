#pragma once
#ifndef _PUR_REQ_VO_
#define _PUR_REQ_VO_

#include "../../GlobalInclude.h"

/**
 * ��ʾ�ɹ�������Ϣ
 */
class PurReqVO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	// ��JSONת������
	BIND_TO_JSON(PurReqVO, id, name, age, sex);
};

#endif // !_PUR_REQ_VO_