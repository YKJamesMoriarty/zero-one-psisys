#include "AccountController.h"
#include "stdafx.h"

/*
* �����˻��б��ѯ�ӿ�ʵ��
* @Author: Oxygen
* @Date: 2023/2/12 14:48:21
*/
JsonVO<PageVO<AccountListVO>> AccountController::executeQueryAccountList(AccountQuery query)
{
	PageVO<AccountListVO> data;
	JsonVO<PageVO<AccountListVO>> res;
	res.success(data);
	return res;
}
