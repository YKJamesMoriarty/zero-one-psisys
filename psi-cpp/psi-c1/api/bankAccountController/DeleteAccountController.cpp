#include "stdafx.h"
#include "DeleteAccountController.h"
#include "domain/service/bankAccountService/DeleteAccountService.h"
#include "domain/dto/IDDTO.h"

/*
* �˻������
* @Author: Oxygen
* @Date: 2023/2/14 16:39:40
*/
JsonVO<std::string> DeleteAccountController::execRemoveBankAccount(const StringID& id)
{
	DeleteAccountService service;
	JsonVO<std::string> result;
	//ִ������ɾ��
	if (service.removeData(id.getId())) {
		result.success(id.getId());
	}
	else
	{
		result.fail(id.getId());
	}
	//��Ӧ���
	return result;
}
