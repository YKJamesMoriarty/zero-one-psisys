#pragma once

#ifndef _CGTHRK_SERVICE_
#define _CGTHRK_SERVICE_
#include <list>
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthrkDetailedBillVO.h"
#include"../../domain/dto/Cgthck/CgthckBillDetailedDTO.h"
#include"../../domain/do/Cgthck/QueryCgthrkBillDetailedReturnDO.h"

class CgthckService {
public:
	// ��ҳ��ѯ�����б�
	PageVO<QueryCgthckBillVO> queryAllFitBill(const QueryCgthckBillQuery& query);

	// ��ѯ��ϸ��Ϣ
	QueryCgthrkDetailedBillVO queryBillDetial(const CgthckBillDetailedDTO& query);
};



#endif
