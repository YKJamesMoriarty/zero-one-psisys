#pragma once

/*
* ���ʽ�����б�
* @Author: qiuqiu
* @Date: 2023/2/14
*/

#ifndef PAYMETHODTYPE_H_
#define PAYMETHODTYPE_H_

#include "../../GlobalInclude.h"
class PayMethodType
{
	CC_SYNTHESIZE(uint64_t, dict_id, Dict_id);
	CC_SYNTHESIZE(uint64_t, id, Id);
	CC_SYNTHESIZE(std::string, name, Name);
public:
	BIND_TO_JSON(PayMethodType, dict_id, id, name);
};

#endif
