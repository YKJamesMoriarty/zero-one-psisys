#pragma once

#ifndef _PYRK_SERVICE_
#define _PYRK_SERVICE_
#include <list>
#include "../../domain/dto/Pyrk/PyrkBillDetailDTO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"

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
};

#endif // !_PYRK_SERVICE_