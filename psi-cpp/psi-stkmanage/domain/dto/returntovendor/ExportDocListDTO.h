#ifndef _EXPORT_DOC_LIST_DTO_
#define _EXPORT_DOC_LIST_DTO_
#include "../../GlobalInclude.h"

/**
* * �ɹ��˻�����(����), �����ɹ��˻����ⵥ���ݴ������
*/
class ExportDocListDTO
{
	CC_SYNTHESIZE(std::list<std::string>, ids, Ids);
public:
	// ��Jsonת������
	friend void from_json(const json& j, ExportDocListDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, ids, std::list<std::string>);
	}
};

#endif // !_EXPORT_DOC_LIST_DTO_

