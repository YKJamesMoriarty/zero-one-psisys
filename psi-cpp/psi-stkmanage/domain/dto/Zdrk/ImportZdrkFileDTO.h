#pragma once
#include "../FileDTO.h"

#ifndef _IMPORTZDRKFILE_DTO_
#define _IMPORTZDRKFILE_DTO_
/**
 * �Ƕ��������ݴ���ģ��
 */
class ImportZdrkFileDTO : public FileDTO
{

public:
	// ��JSONת������
	friend void from_json(const json& j, ImportZdrkFileDTO& t) { // NOLINT
	}
};

#endif // _IMPORTZDRKFILE_DTO_
