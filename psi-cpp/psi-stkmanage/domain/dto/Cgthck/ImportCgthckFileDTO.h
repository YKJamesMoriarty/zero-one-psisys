#pragma once
#ifndef _IMPORT_CGTHCK_FILE_DTO_
#define _IMPORT_CGTHCK_FILE_DTO_

#include "../FileDTO.h"
/**
* �ɹ��˻���������ݴ���ģ��
*/
class ImportCgthckFileDTO : public FileDTO
{
public:
	// ��jsonת������
	friend void from_json(const json& j, ImportCgthckFileDTO& t) // NOLINT
	{
		// TO DO
	}
};
#endif // !_IMPORT_CGTHCK_FILE_DTO_
