#pragma once

#ifndef _REQELEANOR_DTO_
#define _REQELEANOR_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class ReqEleanorDTO
{
//���������Ϣ

public:
	// ��JSONת������
	friend void from_json(const json& j, ReqEleanorDTO& t); // NOLINT
	//BIND_TO_JSON(ReqEleanorDTO, ,  ,  );
};

#endif // !_ReqELEANOR_DTO_