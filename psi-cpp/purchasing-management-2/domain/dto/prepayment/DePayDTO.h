#pragma once
#ifndef _DE_PAY_DTO_
#define _DE_PAY_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//ɾ��������DTO ǰ��ֻ��Ҫ����һ�����ݱ�Ÿ��Ҽ��ɽ����޸�
class DePayDTO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	//��JSONת������
	friend void from_json(const json& j, DePayDTO& t);
};

#endif // !_DELETE_PUR_REQ_DTO_