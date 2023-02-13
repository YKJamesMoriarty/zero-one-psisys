#ifndef _REMOVE_DOC_LIST_DTO_
#define _REMOVE_DOC_LIST_DTO_

#include "../../GlobalInclude.h"
/**
* �ɹ��˻�����(����), ɾ���ɹ��˻����ⵥ���ݴ������
*/

class RemoveDocListDTO
{
	CC_SYNTHESIZE(std::list<std::string>, ids, Ids);
public:
	// ��JSONת������
	friend void from_json(const json& j, RemoveDocListDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, ids, std::list<std::string>);
	}
};

#endif // !_REMOVE_DOC_LIST_DTO_

