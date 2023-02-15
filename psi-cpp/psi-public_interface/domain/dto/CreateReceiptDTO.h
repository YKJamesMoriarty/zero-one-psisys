#pragma once


#ifndef _CREATERECEIPTDTO_H_
#define _CREATERECEIPTDTO_H_
#include"./FileDTO.h"
class CreateReceiptDTO : public FileDTO {

	CC_SYNTHESIZE(std::string, type, Type);
public:
	// ��JSONת������
	friend void from_json(const json& j, CreateReceiptDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, type);

	}
};

#endif