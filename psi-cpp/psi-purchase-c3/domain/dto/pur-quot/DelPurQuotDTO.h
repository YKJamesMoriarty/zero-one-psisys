#pragma once
#ifndef _DEL_PUR_QUOT_DTO_H_
#define _DEL_PUR_QUOT_DTO_H_

#include "../../GlobalInclude.h"


class DelPurQuotDTO
{
	//������һЩ�ֶΣ��Ҳ�ȷ���Ƿ���Ļ��õ������֮��д���룬���ֻ���Ҫ�����ֶΣ��������ȥ������Ҫ��ɾ����
	// ����id
	CC_SYNTHESIZE(long, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	

public:
	//��JSONת������
	friend void from_json(const json& j, DelPurQuotDTO& t) {
		BIND_FROM_TO_L(j, t, id);

		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_DEL_PUR_QUOT_DTO_