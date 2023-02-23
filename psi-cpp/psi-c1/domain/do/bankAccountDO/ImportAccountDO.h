#pragma once
#ifndef _IMPORTACCOUNTDO_H_
#define _IMPORTACCOUNTDO_H_
#include "../DoInclude.h"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/22 12:29:45
*/
class ImportAccountDO
{
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
	ImportAccountDO() {
		accountNo = "1";
		name = "1";
		currency = "�����";
		init_bal = 23.00;
		bankNo = "23.12";
		bankAddress = "��־·996��";
		manager = "��ҵ��";
		remark = "��";
		isEnabled = 1;
	}
};

#endif // _IMPORTACCOUNTDO_H_