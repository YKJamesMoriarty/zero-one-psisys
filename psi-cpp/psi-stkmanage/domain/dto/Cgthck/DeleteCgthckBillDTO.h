#ifndef _DELETE_CGTHCK_BILL_DTO_
#define _DELETE_CGTHCK_BILL_DTO_

#include "../../GlobalInclude.h"
/**
* �ɹ��˻�����(����), ɾ���ɹ��˻����ⵥ���ݴ������
*/

class DeleteCgthckBillDTO
{
	CC_SYNTHESIZE(std::list<std::string>, ids, Ids);
public:
	// ��JSONת������
	friend void from_json(const json& j, DeleteCgthckBillDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, ids, std::list<std::string>);
	}
};

#endif // !_DELETE_CGTHCK_BILL_DTO_

