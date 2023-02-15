#pragma once

#ifndef _BANKACCOUNTDTO_H_
#define _BANKACCOUNTDTO_H_
#include "../../GlobalInclude.h"

/*
* �����˻���Ϣ
* @Author: Oxygen
* @Date: 2023/2/13 21:13:11
*/
class BankAccountDTO
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
	CC_SYNTHESIZE(string, isEnabled, IsEnabled);
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
	// ��JSONת������
	friend void from_json(const json& j, BankAccountDTO& t); // NOLINT
	BIND_TO_JSON(BankAccountDTO, accountNo, name, currency, bankNo,
		bankAddress, manager, isEnabled, remark, createBy, createTime,
		updateBy, updateTime);
};

#endif // _BANKACCOUNTDTO_H_