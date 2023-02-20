#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../../domain/vo/sample/SampleVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/sample/SampleQuery.h"
#include "../../domain/dto/sample/SampleDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class SampleService
{
public:
	// ��ҳ��ѯ��������
	PageVO<SampleVO> listAll(const SampleQuery& query);
	// ��������
	uint64_t saveData(const SampleDTO& dto);
	// �޸�����
	bool updateData(const SampleDTO& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

