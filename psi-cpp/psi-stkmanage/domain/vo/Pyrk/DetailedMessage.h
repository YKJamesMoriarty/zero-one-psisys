#pragma once
#ifndef _D_M_
#define _D_M_
#include "../../GlobalInclude.h"
class DetailedMessage {
	// Դ����¼��
	CC_SYNTHESIZE(string, sourceBillId, SourceBillId);
	// ����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	// �ֿ�
	CC_SYNTHESIZE(string, warehouse, Warehouse);
	// ��λ
	CC_SYNTHESIZE(string, unit, Unit);
	// �������
	CC_SYNTHESIZE(double, inNum, InNum);
	// �����
	CC_SYNTHESIZE(double, inMoney, InMoney);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
};





#endif