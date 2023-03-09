#pragma once
#ifndef _BANKACCOUNTDAO_H_
#define _BANKACCOUNTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/bankAccountDO/BankAccountFunctionDO.h"

/*
* �˻���ӡ��޸ĺ�ɾ��
* @Author: Oxygen
* @Date: 2023/2/22 13:06:57
*/
class BankAccountFunctionDAO : public BaseDAO
{
public:
	// ��������
	int insertAccount(const BankAccountFunctionDO& iObj, uint64_t ID);
	// �޸�����
	int updateAccount(const BankAccountFunctionDO& uObj);
	// ͨ��IDɾ������
	int deleteAccount(std::string id);
};

#endif // _BANKACCOUNTDAO_H_