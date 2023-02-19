#pragma once

#ifndef _ExportQtrkFileDTO_H_
#define _ExportQtrkFileDTO_H_

#include "../FileDTO.h"

/**
 * �����ļ����ݴ���ģ��
 */
class ExportQtrkFileDTO : public FileDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// ��JSONת������
	friend void from_json(const json& j, ExportQtrkFileDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		
	}
};

#endif // _ExportQtrkFile_H_