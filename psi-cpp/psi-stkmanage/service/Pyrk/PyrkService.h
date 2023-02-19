#pragma once

#ifndef _PYRK_SERVICE_
#define _PYRK_SERVICE_
#include <list>
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../psi-stkmanage/domain/query/Pyrk/QueryPyrkBillListQuery.h"

class PyrkService {
public:
	// ��ҳ��ѯ�����б�
	PageVO<QueryPyrkBillListVO> queryAllFitBill(const QueryPyrkBillListQuery& query);
};






#endif