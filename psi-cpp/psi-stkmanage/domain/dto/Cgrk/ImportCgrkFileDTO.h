#pragma once
#include "../FileDTO.h"

#ifndef _IMPORT_CGRK_FILE_DTO_
#define _IMPORT_CGRK_FILE_DTO_
/**
 * �Ƕ��������ݴ���ģ��
 */
class ImportCgrkFileDTO : public FileDTO
{

public:
	// ��JSONת������
	friend void from_json(const json& j, ImportCgrkFileDTO& t) { // NOLINT

	}
};

#endif // _IMPORT_CGRK_FILE_DTO_