/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * �ӿڣ������˻���ͨ��ѯ
 */

#ifndef _BANKACCOUNT_DAO_
#define _BANKACCOUNT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/bankAccount/BankAccountDO.h"

 /**
  * ʾ�������ݿ����ʵ��
  */
class BankAccountDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count();
	// ��ҳ��ѯ����
	list<BankAccountDO> selectWithPage(uint64_t pageIndex, uint64_t pageSize);
};
#endif // !_BANKACCOUNT_DAO_