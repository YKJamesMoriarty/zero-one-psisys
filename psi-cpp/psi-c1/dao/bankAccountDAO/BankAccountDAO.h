#pragma once
#ifndef _BANKACCOUNTDAO_H_
#define _BANKACCOUNTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/bankAccountDO/BankAccountDO.h"

/*
* �˻����
* @Author: Oxygen
* @Date: 2023/2/22 13:06:57
*/
class BankAccountDAO : public BaseDAO
{
public:
	// ��������
	int insertAccount(const BankAccountDO& iObj, uint64_t ID);
	// �޸�����
	int updateAccount(const BankAccountDO& uObj);
	// ͨ��IDɾ������
	int deleteAccount(std::string id);
};

#endif // _BANKACCOUNTDAO_H_