#ifndef _BANKACCOUNTLIST_VO_
#define _BANKACCOUNTLIST_VO_

#include "../../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/14  0.27
 * �����˻��б�
 */

class BankAccountListVO
{
	//��дĿǰ����б��ܿ�����
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
	//id
	CC_SYNTHESIZE(string, id, Id);

	//��Щ���б��￴������
	
	//attachment
	CC_SYNTHESIZE(string, attachment, Attachment);
	//createBy
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//currency
	CC_SYNTHESIZE(string, currency, Currency);
	//initBal
	CC_SYNTHESIZE(string, initBal, InitBal);
	//isEnabled
	CC_SYNTHESIZE(string, isEnabled, IsEnabled);
	//manager
	CC_SYNTHESIZE(string, manager, Manager);
	//version
	CC_SYNTHESIZE(string, version, Version);

public:
	// ��JSONת������
	BIND_TO_JSON(BankAccountListVO, updateBy, updateTime, accountNo, bankAddress, bankNo, createBy_dictText, createTime, currency_dictText, isEnabled_dictText, manager_dictText, name, remark);
	/*
	BIND_TO_JSON(BankAccountListVO, accountNo, bankAddress, bankNo, createBy_dictText, createTime, currency_dictText, isEnabled_dictText, manager_dictText, name, remark, id, attachment, createBy, currency, initBalisEnabled, manager, updateBy, updateTime, version);
	*/
};

#endif //_BANKACCOUNTLIST_VO_