#pragma once

#ifndef _PYRK_SERVICE_
#define _PYRK_SERVICE_
#include <list>
#include "../../domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include "../../domain/query/Pyrk/QueryPyrkBillDetailsQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"




class PyrkService {
public:
	// ��ҳ��ѯ��������
	PageVO<QueryPyrkBillListVO> listPyrkBillList(const QueryPyrkBillListQuery& query);

	//��ѯ������ϸ��Ϣ
	QueryPyrkBillDetailsVO getPyrkBillDetails(const QueryPyrkBillDetailsQuery& query);


};






#endif