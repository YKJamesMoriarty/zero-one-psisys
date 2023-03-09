#pragma once

#ifndef _ZDRK_SERVICE_
#define _ZDRK_SERVICE_
#include <list>
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Zdrk/QueryZdrkBillListVO.h"
#include "../psi-stkmanage/domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../../domain/query/Zdrk/QueryZdrkBillDetailsQuery.h"
#include "../psi-stkmanage/domain/dto/Zdrk/AddZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillStateDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ApprovalDTO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillDetailsVO.h"

class ZdrkService {
public:
	// ������������
	int saveBillData(const AddZdrkBillDTO& dto, const PayloadDTO& payload);
	// �޸ĵ���
	int updateBillData(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload);
	// ��˵���
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	// �رյ���
	int updateStateToClose(const string& billNo, const PayloadDTO& payload);
	// ���رյ���
	int updateStateToUnclose(const string& billNo, const PayloadDTO& payload);
	// ���ϵ���
	int updateStateToVoid(const string& billNo, const PayloadDTO& payload);
	// ɾ������
	int removeBillById(const string& billNo);
	
	// ��ҳ��ѯ��������
	PageVO<QueryZdrkBillListVO> listZdrkBillList(const QueryZdrkBillListQuery& query);

	//��ѯ������ϸ��Ϣ
	QueryZdrkBillDetailsVO getZdrkBillDetails(const QueryZdrkBillDetailsQuery& query);

};

#endif // !_ZDRK_SERVICE_
