#pragma once

#ifndef _INQUIRYELEANOR_SERVICE_
#define _INQUIRYELEANOR_SERVICE_
#include <list>
#include "../../domain/vo/inquiry-eleanor/InquiryEleanorVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/inquiry-eleanor/InquiryEleanorQuery.h"
#include "../../domain/dto/inquiry-eleanor/InquiryEleanorDTO.h"

/**
 * ʾ������ʵ��
 */
class InquiryEleanorService
{
public:
	// ��ҳ��ѯ��������
	PageVO<InquiryEleanorVO> listAll(const InquiryEleanorQuery& query);
	// ��������
	uint64_t saveData(const InquiryEleanorDTO& dto);
};

#endif // !_INQUIRYELEANOR_SERVICE_