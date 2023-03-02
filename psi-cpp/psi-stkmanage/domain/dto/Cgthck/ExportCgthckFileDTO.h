#ifndef _EXPORT_CGTHCK_FILE_DTO_
#define _EXPORT_CGTHCK_FILE_DTO_
#include "../../GlobalInclude.h"

/**
* * �ɹ��˻�����(����), �����ɹ��˻����ⵥ���ݴ������
*/
class ExportCgthckFileDTO
{
	CC_SYNTHESIZE(std::string, billNo, BillNo);
public:
	// ��Jsonת������
	friend void from_json(const json& j, ExportCgthckFileDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_EXPORT_CGTHCK_FILE_DTO_

