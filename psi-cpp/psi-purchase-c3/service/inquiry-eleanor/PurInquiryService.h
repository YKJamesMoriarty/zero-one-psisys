#pragma once

#ifndef _PURINQUIRY_SERVICE_
#define _PURINQUIRY_SERVICE_
#include <list>
#include "../../domain/vo/inquiry-eleanor/PurInquiryFindBillVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/inquiry-eleanor/PurInquiryFindBillQuery.h"
#include "../../domain/dto/inquiry-eleanor/PurInquiryFindBillDTO.h"

/**
 * 示例服务实现
 */
class PurInquiryService
{
public:
	// 分页查询所有数据
	PageVO<PurInquiryFindBillVO> listAll(const PurInquiryFindBillQuery& query);
};

#endif // !_PURINQUIRY_SERVICE_