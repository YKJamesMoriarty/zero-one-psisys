#pragma once

#ifndef _PYRK_SERVICE_
#define _PYRK_SERVICE_
#include <list>
#include "../../domain/dto/Pyrk/PyrkBillDetailDTO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"
#include "../../domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include "../../domain/query/Pyrk/QueryPyrkBillDetailsQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"



/*
* ��ӯ������
*/
class PyrkService {
public:
	// ������������
	int saveBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload);
	// ��˵���
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	// �޸ĵ���
	int updateBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload);
	// �رյ���
	int updateStateToClose(const string& billNo, const PayloadDTO& payload);
	// ���رյ���
	int updateStateToUnclose(const string& billNo, const PayloadDTO& payload);
	// ���ϵ���
	int updateStateToVoid(const string& billNo, const PayloadDTO& payload);
	// ɾ������
	int removeBillById(const string& billNo);
	// ��ҳ��ѯ��������
	PageVO<QueryPyrkBillListVO> listPyrkBillList(const QueryPyrkBillListQuery& query);

	//��ѯ������ϸ��Ϣ
	QueryPyrkBillDetailsVO getPyrkBillDetails(const QueryPyrkBillDetailsQuery& query);

};

#endif // !_PYRK_SERVICE_