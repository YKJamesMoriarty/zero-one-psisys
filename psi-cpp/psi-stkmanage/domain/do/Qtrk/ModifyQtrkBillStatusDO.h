#pragma once

#ifndef M_Q_B_S_DO
#define M_Q_B_S_DO  

#include "../../GlobalInclude.h"
class ModifyQtrkBillStatusDO {
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
};
#endif // !M_Q_B_S_DO
