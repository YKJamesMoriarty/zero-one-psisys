#pragma once

#ifndef M_C_B_S_DO
#define M_C_B_S_DO  

#include "../../GlobalInclude.h"
class ModifyCgrkBillStatusDO {
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
};
#endif // !M_C_B_S_DO

