#pragma once

#ifndef _ExportQtrkFileVO_H_
#define _ExportQtrkFileVO_H_

#include "../../GlobalInclude.h"

/**
 * ������Ϣ�����ʾ����
 */
class ExportQtrkFileVO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, id, Id);
	
public:
	// ��JSONת������
	BIND_TO_JSON(ExportQtrkFileVO, id);
};

#endif // _ExportQtrkFileVO_H_