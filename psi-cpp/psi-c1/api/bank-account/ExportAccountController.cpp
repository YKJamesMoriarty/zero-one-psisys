#include "stdafx.h"
#include "ExportAccountController.h"
#include "service/bank-account/ExportAccountService.h"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/15 11:20:02
*/
JsonVO<std::string> ExportAccountController::execExportAccountExecl(const StringIDs& query, PayloadDTO payload)
{
	//�������ص�ַ
	ExportAccountService service;
	return service.listAll(query);
}