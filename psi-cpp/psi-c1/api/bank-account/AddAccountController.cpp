#include "stdafx.h"
#include "AddAccountController.h"
#include "service/bank-account/AddAccountService.h"

/*
* �˻����
* @Author: Oxygen
* @Date: 2023/2/13 21:27:42
*/
JsonVO<int> AddAccountController::execAddBankAccount(const BankAccountDTO& dto, const PayloadDTO& pdto)
{
	JsonVO<int> result;
	AddAccountService service;
	//ִ����������
	int id = service.saveData(dto, pdto);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	return result;
}
