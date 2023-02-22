#include "stdafx.h"
#include "AddAccountService.h"
#include "../../do/bankAccountDO/BankAccountDO.h"
#include "../../../dao/bankAccountDAO/BankAccountDAO.h"


/*
* �˻����
* @Author: Oxygen
* @Date: 2023/2/22 12:56:30
*/
uint64_t AddAccountService::saveData(const BankAccountDTO& dto, const PayloadDTO& pdto)
{
	//��װ����
	BankAccountDO data;
	data.setAccountNo(dto.getAccountNo());
	data.setName(dto.getName());
	data.setCurrency(dto.getCurrency());
	data.setBankNo(dto.getBankNo());
	data.setBankAddress(dto.getBankAddress());
	data.setManager(dto.getManager());
	data.setIsEnabled(dto.getIsEnabled());
	data.setRemark(dto.getRemark());
	data.setCreateBy(pdto.getUsername());
	//ִ���������
	BankAccountDAO dao;
	return dao.insertAccount(data);
}
