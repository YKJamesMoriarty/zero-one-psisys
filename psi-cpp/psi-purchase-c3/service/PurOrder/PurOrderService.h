#pragma once

#ifndef _PUR_ORDER_SERVICE_H_
#define _PUR_ORDER_SERVICE_H_
#include <list>
#include "../../domain/vo/PageVO.h"
//vo
#include "../../domain/vo/PurOrder/PurOrderDividedListVO.h"
//query
#include "../../domain/query/PurOrder/PurOrderDividedListQuery.h"



/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PurOrderService
{
public:

	//��ȡ���PurQuotDividedListVO����
	list<PurOrderDividedListVO> listPurOrderDividedListDO(const PurOrderDividedListQuery& query);
};

#endif // !_SAMPLE_SERVICE_

