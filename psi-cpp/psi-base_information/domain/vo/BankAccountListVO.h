#ifndef _BANKACCOUNTLIST_VO_
#define _BANKACCOUNTLIST_VO_

#include "../GlobalInclude.h"

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
	CC_SYNTHESIZE(string, isEnabled_dictText, IsEnabled_dictText);
	//�˻�����Ա
	CC_SYNTHESIZE(string, manager_dictText, Manager_dictText);
	//�˻���
	CC_SYNTHESIZE(string, name, Name);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

	//��Щ���б��￴������
	//id
	CC_SYNTHESIZE(string, id, Id);
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
	//updateBy
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//updateTime
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//version
	CC_SYNTHESIZE(string, version, Version);

public:
	// ��JSONת������
	BIND_TO_JSON(BankAccountListVO, accountNo, bankAddress, bankNo, createBy_dictText, createTime, currency_dictText, isEnabled_dictText, manager_dictText, name, remark);
	/*
	BIND_TO_JSON(BankAccountListVO, accountNo, bankAddress, bankNo, createBy_dictText, createTime, currency_dictText, isEnabled_dictText, manager_dictText, name, remark, id, attachment, createBy, currency, initBalisEnabled, manager, updateBy, updateTime, version);
	*/
};

#endif //_BANKACCOUNTLIST_VO_