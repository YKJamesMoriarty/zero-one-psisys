#pragma once

#ifndef _ImportQtrkFileVO_H_
#define _ImportQtrkFileVO_H_

#include "../../GlobalInclude.h"

/**
 * �ϴ���Ϣ�����ʾ����
 */
class ImportQtrkFileVO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// ��JSONת������
	BIND_TO_JSON(ImportQtrkFileVO, id);
};

#endif // _ImportQtrkFileVO_H_