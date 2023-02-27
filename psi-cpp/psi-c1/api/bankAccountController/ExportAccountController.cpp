#include "stdafx.h"
#include "ExportAccountController.h"
#include "domain/service/bankAccountService/ExportAccountService.h"
#include "nlohmann/json_fwd.hpp"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/15 11:20:02
*/
JsonVO<std::string> ExportAccountController::execExportAccountExecl(const list<ExportAccountQuery>& query, PayloadDTO payload)
{
	//�������ص�ַ
	ExportAccountService service;
	return service.listAll(query);
}