#pragma once
#ifndef _DOCSTAT_DTO_
#define _DOCSTAT_DTO_

#include "../../GlobalInclude.h"

/**
 * ���ݱ�Ŵ������
 */
class DocStatDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	// ��JSONת������
	friend void from_json(const json& j, DocStatDTO& t); // NOLINT
	BIND_TO_JSON(DocStatDTO, billNo,isClosed,isVoided);
};

#endif // !_QueryDoc_DTO_
