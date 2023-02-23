#pragma once

#ifndef _PUR_QUOT_SERVICE_H_
#define _PUR_QUOT_SERVICE_H_
#include <list>
#include "../../domain/vo/PageVO.h"

//vo
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotListVO.h"
#include "../../domain/vo/pur-quot/PurQuotDividedListVO.h"
//query
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotListQuery.h"
#include "../../domain/query/pur-quot/PurQuotDividedListQuery.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PurQuotService
{
public:
	//��ȡ���PurQuotFindBillVO����
	PageVO<PurQuotFindBillVO> listPurQuotFindBillVO(const PurQuotFindBillQuery& query);

	//��ȡ���PurQuotList����
	list<PurQuotListVO> listPurQuotListVO(const PurQuotListQuery& query);

	//��ȡ���PurQuotDividedListVO����
	list<PurQuotDividedListVO> listPurQuotFindBillVO(const PurQuotDividedListQuery& query);


};

#endif // !_SAMPLE_SERVICE_

