#pragma once

#ifndef _ZDRK_SERVICE_
#define _ZDRK_SERVICE_
#include <list>
#include "../../domain/dto/IDDTO.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Zdrk/QueryZdrkBillListVO.h"
#include "../psi-stkmanage/domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../psi-stkmanage/domain/dto/Zdrk/AddZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillStateDTO.h"
class PyrkService {
public:
	// ������������
	int saveBillData(const AddZdrkBillDTO& dto, const PayloadDTO& payload);
	// �޸ĵ���
	int updateBillData(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload);
	// ɾ������
	int removeBillById(const StringID& billNo);
	//�޸ĵ���״̬
	int updateBillState(const ModifyZdrkBillStateDTO& dto, const PayloadDTO& payload);
	//����

	//����

};






#endif // !_ZDRK_SERVICE_