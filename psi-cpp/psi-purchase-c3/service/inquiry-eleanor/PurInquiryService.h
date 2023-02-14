#pragma once

#ifndef _PURINQUIRY_SERVICE_
#define _PURINQUIRY_SERVICE_
#include <list>
#include "../../domain/vo/inquiry-eleanor/PurInquiryFindBillVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/inquiry-eleanor/PurInquiryFindBillQuery.h"
#include "../../domain/dto/inquiry-eleanor/PurInquiryFindBillDTO.h"

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