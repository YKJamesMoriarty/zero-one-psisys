#pragma once

#ifndef _PURREQEXPORT_DTO_
#define _PURREQEXPORT_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * ������� ���� ���ݱ�ţ����õ��ݱ�Ų�ѯ�뵼���Ķ�����
 */

//����
class PurReqExportDTO 
{
	//���������Ϣ ���� ���õ��ݱ�Ų�ѯ�뵼���Ķ���
	CC_SYNTHESIZE(string, purReqId, PurReqId);

public:
	// ��JSONת������
	friend void from_json(const json& j, PurReqExportDTO& t);
};

#endif // !_PURREQEXPORT_DTO_