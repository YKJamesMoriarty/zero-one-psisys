#pragma once

#ifndef _PUR_QUOT_SERVICE_H_
#define _PUR_QUOT_SERVICE_H_
#include <list>
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PurQuotService
{
public:
	// ��ҳ��ѯ��������
	PageVO<PurQuotFindBillVO> listPurQuotFindBill(const PurQuotFindBillQuery& query);

};

#endif // !_SAMPLE_SERVICE_

