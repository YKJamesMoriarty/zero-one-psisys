#pragma once
#ifndef _QTRK_SERVICE_
#define _QTRK_SERVICE_

#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"

/*
* ����������
*/
class QtrkService {
public:
	// ������������
	int saveBillData(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// �޸ĵ�������
	int updateBillDate(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
};

#endif // !_QTRK_SERVICE_