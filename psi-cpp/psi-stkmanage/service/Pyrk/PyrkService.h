#pragma once

#ifndef _PYRK_SERVICE_
#define _PYRK_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../../domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include "../../domain/dto/Pyrk/PyrkBillDetailDTO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"

/*
* ��ӯ������
*/
class PyrkService {
public:
	// ��ҳ��ѯ�����б�
	PageVO<QueryPyrkBillListVO> queryAllFitBill(const QueryPyrkBillListQuery& query);
	// ��������
	int saveData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload);
	// �޸ĵ��������Ϣ
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
};

#endif // !_PYRK_SERVICE_