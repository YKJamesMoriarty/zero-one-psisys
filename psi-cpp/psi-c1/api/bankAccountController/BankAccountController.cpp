#include "stdafx.h"
#include "BankAccountController.h"
#include "../../service/bankAccountService/BankAccountService.h"

JsonVO<PageVO<SpecifiedBankAccountListVO>> BankAccountController::execSpecifiedBankAccount(SpecifiedBankAccountQuery& query)
{
    PageVO<SpecifiedBankAccountListVO> data(query.getPageIndex(), query.getPageSize(), 100, 10, { SpecifiedBankAccountListVO() });
    JsonVO<PageVO<SpecifiedBankAccountListVO>> res;
    res.success(data);
    return res;
}
/*JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery query)
{
	PageVO<BankAccountListVO> data;
	JsonVO<PageVO<BankAccountListVO>> res;
	//res.success(data);
	return res;
}
*/

JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery& query)
{
	//����һ��Service
	BankAccountService service;
	//��ѯ����
	PageVO<BankAccountListVO> result = service.listAll(query);
	//��Ӧ���
	return JsonVO<PageVO<BankAccountListVO>>(result, RS_SUCCESS);
}
