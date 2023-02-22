#include "stdafx.h"
#include "ModifyAccountService.h"
#include "../../do/bankAccountDO/BankAccountDO.h"
#include "dao/bankAccountDAO/BankAccountDAO.h"

/*
* �˻���Ϣ�޸�
* @Author: Oxygen
* @Date: 2023/2/22 14:31:16
*/
bool ModifyAccountService::updateData(const BankAccountDTO& dto, const PayloadDTO& pdto)
{
	//��װ��������
	BankAccountDO data;
	data.setAccountNo(dto.getAccountNo());
	data.setName(dto.getName());
	data.setCurrency(dto.getCurrency());
	data.setBankNo(dto.getBankNo());
	data.setBankAddress(dto.getBankAddress());
	data.setManager(dto.getManager());
	data.setIsEnabled(dto.getIsEnabled());
	data.setRemark(dto.getRemark());
	data.setUpdateBy(pdto.getUsername());
	//ִ�������޸�
	BankAccountDAO dao;
	return dao.updateAccount(data) == 1;
}
