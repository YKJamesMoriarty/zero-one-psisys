#ifndef _EXPORT_CGTHCK_FILE_DTO_
#define _EXPORT_CGTHCK_FILE_DTO_
#include "../../GlobalInclude.h"

/**
* * �ɹ��˻�����(����), �����ɹ��˻����ⵥ���ݴ������
*/
class ExporCgthckFileDTO
{
	CC_SYNTHESIZE(std::list<std::string>, ids, Ids);
public:
	// ��Jsonת������
	friend void from_json(const json& j, ExporCgthckFileDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, ids, std::list<std::string>);
	}
};

#endif // !_EXPORT_CGTHCK_FILE_DTO_

