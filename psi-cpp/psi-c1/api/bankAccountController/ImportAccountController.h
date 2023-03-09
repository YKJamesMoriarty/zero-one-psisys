#pragma once

#ifndef _IMPORTACCOUNTCONTROLLER_H_
#define _IMPORTACCOUNTCONTROLLER_H_
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/FileDTO.h"
#include "api/ApiHelper.h"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/14 16:42:51
*/
class ImportAccountController
{
public:
	CREATE_API_FUN_BODY_FILE(modifyAccountInfo, execModifyAccountInfo, FileDTO);
private:
	// ����boolֵ����ʾ�ɹ��������
	JsonVO<bool> execModifyAccountInfo(const FileDTO& dto);
};

#endif // _IMPORTACCOUNTCONTROLLER_H_