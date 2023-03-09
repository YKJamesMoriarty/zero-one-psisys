/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * �ӿڣ������˻���ͨ��ѯ
 */
#ifndef _BANKACCOUNT_SERVICE_
#define _BANKACCOUNT_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/bank-account/BankAccountListVO.h"
#include "../../domain/query/bank-account/BankAccountQuery.h"

 /**
  * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
  */
class BankAccountService
{
public:
	// ��ҳ��ѯ��������
	PageVO<BankAccountListVO> listAll(const BankAccountQuery& query);
};

#endif // !_BANKACCOUNT_SERVICE_