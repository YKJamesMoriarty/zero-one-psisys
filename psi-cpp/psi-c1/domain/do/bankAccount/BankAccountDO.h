#pragma once
/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * �ӿڣ������˻���ͨ��ѯ
 */

#ifndef _BANKACCOUNT_DO_
#define _BANKACCOUNT_DO_
#include "../DoInclude.h"

class BankAccountDO
{
	// �˺�
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	// ���е�ַ
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	//�к�
	CC_SYNTHESIZE(string, bankNo, BankNo);
	//������
	CC_SYNTHESIZE(string, createBy_dictText, CreateBy_dictText);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ����
	CC_SYNTHESIZE(string, currency_dictText, Currency_dictText);
	//����
	CC_SYNTHESIZE(int, isEnabled_dictText, IsEnabled_dictText);
	//�˻�����Ա
	CC_SYNTHESIZE(string, manager_dictText, Manager_dictText);
	//�˻���
	CC_SYNTHESIZE(string, name, Name);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//updateBy
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//updateTime
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	BankAccountDO() {
		accountNo = "";
		bankAddress = "";
		bankNo = "";
		createBy_dictText = "";
		createTime = "";
		currency_dictText = "";
		isEnabled_dictText = 1;
		manager_dictText = "";
		name = "";
		remark = "";
		updateBy = "";
		updateTime = "";
	}
};

#endif // !_BANKACCOUNT_DO_
