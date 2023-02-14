#pragma once

#ifndef _PURREQ_DTO_
#define _PURREQ_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * ʾ���������
 */


//����
class PurReqExportDTO 
{
	//���������Ϣ ���� ���õ��ݱ�Ų�ѯ�뵼���Ķ���
	CC_SYNTHESIZE(std::list<string>, purReqId, PurReqId);

public:
	// ��JSONת������
	friend void from_json(const json& j, PurReqExportDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, purReqId, std::list<string>);
	}
};

//����
class PurReqIntoDTO : public FileDTO
{
//���������Ϣ
	//CC_SYNTHESIZE(std::list<string>, purReqId, PurReqId);

public:
	// ��JSONת������
	friend void from_json(const json& j, PurReqIntoDTO& t)// NOLINT
	{
		//BIND_FROM_TO_ULL(PurReqInportDTO, purReqId, std::list<string>);          //  ��δ���------------------
	}
};

#endif // !_PURREQ_DTO_