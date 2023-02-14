#pragma once

#ifndef _PURREQ_SERVICE_
#define _PURREQ_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/req-eleanor/PurReqIntoDTO.h"

/**
 * ʾ������ʵ��
 */
class PurReqService
{
public:
	// ��������
	std::string purReqExportData(PurReqExportDTO dto);
	// ��������
	uint64_t saveData(const PurReqIntoDTO& dto);
};

#endif // !_PURREQ_SERVICE_