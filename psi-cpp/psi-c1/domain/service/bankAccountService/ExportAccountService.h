#pragma once
#include <string>
#include "../../query/bankAccountQuery/SpecifiedBankAccountQuery.h"
#include "../../do/bankAccountDO/ExportAccountDO.h"
#ifndef _BANKACCOUNTSERVICE_H_
#define _BANKACCOUNTSERVICE_H_

/*
* �����˻�����
* @Author: Oxygen
* @Date: 2023/2/22 10:47:18
*/
class ExportAccountService
{
public:
	// �����˻���������
	list<ExportAccountDO> listAll(const SpecifiedBankAccountQuery& query);
};

#endif // _BANKACCOUNTSERVICE_H_