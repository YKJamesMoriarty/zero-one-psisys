#pragma once
#include "../arch-demo/Macros.h"
#include "../DoInclude.h"

#ifndef _EXPORTACCOUNTDO_H_
#define _EXPORTACCOUNTDO_H_

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/22 10:43:14
*/
class ExportAccountDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// �˺�
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	// �˻���
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, currency, Currency);
	// ��ʼ���
	CC_SYNTHESIZE(double, init_bal, Init_bal);
	// �к�
	CC_SYNTHESIZE(string, bankNo, BankNo);
	// ���е�ַ
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	// �˻�����Ա
	CC_SYNTHESIZE(string, manager, Manager);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ�����
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
public:
	ExportAccountDO() {
	}
};

#endif // _EXPORTACCOUNTDO_H_