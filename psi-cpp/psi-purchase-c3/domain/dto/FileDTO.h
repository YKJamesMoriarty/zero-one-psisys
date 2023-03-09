
#ifndef _FILEDTO_H_
#define _FILEDTO_H_

#include "../GlobalInclude.h"
#include <list>

/**
 * ����һ���ļ��ϴ���������ģ��
 */
class FileDTO
{
protected:
	// �ϴ��ļ�·���б�
	CC_SYNTHESIZE_GET(std::list<std::string>, files, Files);
public:
	// ����ļ��ϴ�·��
	void addFile(std::string file) {
		files.push_back(file);
	}
};

#endif // _FILEDTO_H_