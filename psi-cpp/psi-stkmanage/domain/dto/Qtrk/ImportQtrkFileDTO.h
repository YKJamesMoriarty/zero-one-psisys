#pragma once

#ifndef _ImportQtrkFileDTO_H_
#define _ImportQtrkFileDTO_H_

#include "../FileDTO.h"

/**
 * �����ļ����ݴ���ģ��
 */
class ImportQtrkFileDTO : public FileDTO
{
	// ���ݱ��
	//CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// ��JSONת������
	friend void from_json(const json& j, ImportQtrkFileDTO& t) { // NOLINT
		//BIND_FROM_TO_NORMAL(j, t, id);
		
	}
};

#endif // _ImportQtrkFile_H_