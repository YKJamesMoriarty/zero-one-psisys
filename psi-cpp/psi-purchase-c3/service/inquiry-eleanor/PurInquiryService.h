#pragma once

#ifndef _PURINQUIRY_SERVICE_
#define _PURINQUIRY_SERVICE_
#include <list>
#include "../../domain/vo/inquiry-eleanor/PurInquiryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/inquiry-eleanor/PurInquiryQuery.h"
#include "../../domain/dto/inquiry-eleanor/PurInquiryDTO.h"

/**
 * ʾ������ʵ��
 */
class PurInquiryService
{
public:
	// ��ҳ��ѯ��������
	PageVO<PurInquiryFindBillVO> listAll(const PurInquiryFindBillQuery& query);
};

#endif // !_PURINQUIRY_SERVICE_