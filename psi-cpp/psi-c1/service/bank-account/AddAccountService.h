#pragma once
#ifndef _ADDACCOUNTSERVICE_H_
#define _ADDACCOUNTSERVICE_H_
#include <list>
#include "../../domain/dto/bank-account/BankAccountDTO.h"

/*
* �˻����
* @Author: Oxygen
* @Date: 2023/2/22 12:50:51
*/
class AddAccountService
{
public:
	// ��������
	int saveData(const BankAccountDTO& dto, const PayloadDTO& pdto);
};

#endif // _ADDACCOUNTSERVICE_H_