#pragma once

#ifndef _EXPORTACCOUNTCONTROLLER_H_
#define _EXPORTACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "domain/query/BankAccountQuery/SpecifiedBankAccountQuery.h"
#include "api/ApiHelper.h"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/14 19:07:31
*/
class ExportAccountController
{
public:
	CREATE_API_FUN_QUERY(exportAccountExecl, execExportAccountExecl, SpecifiedBankAccountQuery);
private:
	JsonVO<std::string> execExportAccountExecl(const SpecifiedBankAccountQuery& query);
};

#endif // _EXPORTACCOUNTCONTROLLER_H_