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
	//id
	CC_SYNTHESIZE(string, id, Id);
	// �˺�
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	//�˻���
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, currency_dictText, Currency_dictText);
	//�к�
	CC_SYNTHESIZE(string, bankNo, BankNo);
	// ���е�ַ
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	//�˻�����Ա
	CC_SYNTHESIZE(string, manager_dictText, Manager_dictText);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����
	CC_SYNTHESIZE(int, isEnabled_dictText, IsEnabled_dictText);
	//������
	CC_SYNTHESIZE(string, createBy_dictText, CreateBy_dictText);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//updateBy
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//updateTime
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	BankAccountDO() {
		//id = "";
		accountNo = "";
		name = "";
		currency_dictText = "";
		bankNo = "";
		bankAddress = "";
		manager_dictText = "";
		remark = "";
		isEnabled_dictText = 1;
		createBy_dictText = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
	}
};

#endif // !_BANKACCOUNT_DO_
