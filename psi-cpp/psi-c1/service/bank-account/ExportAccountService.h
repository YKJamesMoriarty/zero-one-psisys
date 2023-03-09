#pragma once
#ifndef _BANKACCOUNTSERVICE_H_
#define _BANKACCOUNTSERVICE_H_
#include <string>
#include "../../domain/do/bank-account/ExportAccountDO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/bank-account/ExportAccountQuery.h"
#include "../../domain/dto/IDDTO.h"

/*
* �����˻�����
* @Author: Oxygen
* @Date: 2023/2/22 10:47:18
*/
class ExportAccountService
{
public:
	// �����˻���������
	JsonVO<std::string> listAll(const StringIDs& query);
};

#endif // _BANKACCOUNTSERVICE_H_