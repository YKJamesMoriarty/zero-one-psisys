#pragma once
#ifndef _IMPORT_PYRK_FILE_VO_
#define _IMPORT_PYRK_FILE_VO_

#include "../../GlobalInclude.h"

/**
* �������ݽ����ʾ����
*/
class ImportPyrkFileVO
{
	// ����������
	CC_SYNTHESIZE(int, totalRows, TotalRows);
	// �Ƿ�ɹ�
	CC_SYNTHESIZE(bool, success, Success);
	// ʧ��ԭ��
	CC_SYNTHESIZE(string, failReason, FailReason);
public:
	ImportPyrkFileVO() {
		totalRows = 100;
		success = true;
		failReason = "";
	}
	// ��JSONת������
	BIND_TO_JSON(ImportPyrkFileVO, totalRows, success, failReason);
};

#endif // !_IMPORT_PYRK_FILE_VO_