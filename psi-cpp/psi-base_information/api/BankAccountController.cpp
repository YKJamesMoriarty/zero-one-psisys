#include "stdafx.h"
#include "BankAccountController.h"

/*
* c1-ruizi
* 2.14 1.47
* �����˻���ͨ��ѯ�ӿ�
*/

JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery query)
{
	PageVO<BankAccountListVO> data;
	JsonVO<PageVO<BankAccountListVO>> res;
	res.success(data);
	return res;
}
