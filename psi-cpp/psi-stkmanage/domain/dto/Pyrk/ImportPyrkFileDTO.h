#pragma once
#ifndef _IMPORT_PYRK_FILE_DTO
#define _IMPORT_PYRK_FILE_DTO

#include "../FileDTO.h"

/**
* ������ӯ��ⵥ�����ݴ���ģ��
*/
class ImportPyrkFileDTO : public FileDTO
{
public:
	friend void from_json(const json& j, ImportPyrkFileDTO& t) { } // NOLINT
};

#endif // !_IMPORT_PYRK_FILE_DTO