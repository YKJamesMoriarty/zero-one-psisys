#include "stdafx.h"
#include "BasBankAccountController.h"
#include "../../service/public-interface/BasBankAccountService.h"

JsonVO<std::list<BasBankAccountVO>> BasBankAccountController::execQueryBasBankAccount()
{
    list<BasBankAccountVO> data;
	BasBankAccountService service;
	//��ѯ����
	list<BasBankAccountVO> result = service.listAll();
	//��Ӧ���
	return JsonVO<list<BasBankAccountVO>>(result, RS_SUCCESS);
}
