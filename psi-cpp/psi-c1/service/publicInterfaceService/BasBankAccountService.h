#pragma once
/*
* ��Ӧ���ʽ��˻������б�
* @Author: kiva
* @Date: 2023/2/23
*/

#ifndef _BASBANKACCOUNTSERVICE_H_
#define _BASBANKACCOUNTSERVICE_H_
#include "../../domain/vo/bankAccountVO/BasBankAccountVO.h"
class BasBankAccountService {
public:
	list<BasBankAccountVO> listAll();
};
#endif // ! _BASBANKACCOUNTSERVICE_H_


