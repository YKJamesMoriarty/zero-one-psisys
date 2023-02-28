#pragma once
#include "../DoInclude.h"
#ifndef _BANKACCOUNTDO_H_
#define _BANKACCOUNTDO_H_

/*
* �˻���ӡ��޸�
* @Author: Oxygen
* @Date: 2023/2/22 12:59:24
*/
class BankAccountFunctionDO
{
	// �˺�
	CC_SYNTHESIZE(string, accountNo, AccountNo);
	// �˻���
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, currency, Currency);
	// �к�
	CC_SYNTHESIZE(string, bankNo, BankNo);
	// ���е�ַ
	CC_SYNTHESIZE(string, bankAddress, BankAddress);
	// �˻�����Ա
	CC_SYNTHESIZE(string, manager, Manager);
	// �Ƿ�����
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	BankAccountFunctionDO() {
		accountNo = "1234";
		name = "����";
		currency = "�����";
		bankNo = "23.12";
		bankAddress = "��ΰ·996��";
		manager = "��ҵ��";
		isEnabled = 1;
		remark = "��";
		createBy = "��ҵ��";
		createTime = "2022.2.22";
		updateBy = "��ҵ��";
		updateTime = "2022.2.22";
	}
};

#endif // _BANKACCOUNTDO_H_