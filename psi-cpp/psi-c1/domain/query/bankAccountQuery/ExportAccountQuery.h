#pragma once
#ifndef _EXPORTACCOUNTQUERY_H_
#define _EXPORTACCOUNTQUERY_H_
#include"../PageQuery.h"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/23 16:20:34
*/
class ExportAccountQuery : public PageQuery
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

	friend void from_json(const json& j, ExportAccountQuery& f) {
		BIND_FROM_TO_ULL(j, f, pageIndex);
		BIND_FROM_TO_ULL(j, f, pageSize);
		BIND_FROM_TO_NORMAL(j, f, accountNo);
		BIND_FROM_TO_NORMAL(j, f, name);
		BIND_FROM_TO_NORMAL(j, f, currency);
		BIND_FROM_TO_D(j, f, init_bal);
		BIND_FROM_TO_NORMAL(j, f, bankNo);
		BIND_FROM_TO_NORMAL(j, f, bankAddress);
		BIND_FROM_TO_NORMAL(j, f, manager);
		BIND_FROM_TO_NORMAL(j, f, remark);
		BIND_FROM_TO_I(j, f, isEnabled);
	}
};

#endif // _EXPORTACCOUNTQUERY_H_