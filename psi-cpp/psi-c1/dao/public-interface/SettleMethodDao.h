/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * �ӿڣ����㷽ʽ
 */

#ifndef _SETTLEMETHOD_DAO_
#define _SETTLEMETHOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/public-interface/SettleMethodDo.h"

class SettleMethodDAO : public BaseDAO
{
public:
	//��ѯ����
	list<SettleMethodDO> selectSettleMethod();
};
#endif // !_SETTLEMETHOD_DAO_