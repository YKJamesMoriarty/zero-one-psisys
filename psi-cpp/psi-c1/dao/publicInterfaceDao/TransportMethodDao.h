/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ����䷽ʽ
 */

#ifndef _TRANSPORTMETHOD_DAO_
#define _TRANSPORTMETHOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/TransportMethodDo.h"

class TransportMethodDAO : public BaseDAO
{
public:
	//��ѯ����
	list<TransportMethodDO> selectTransportMethod();
};
#endif // !_TRANSPORTMETHOD_DAO_