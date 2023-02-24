#pragma once
#ifndef _CGTHCK_DAO_
#define _CGTHCK_DAO_

#include "BaseDAO.h"
#include "FastDfsClient.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../service/Cgthck/CgthckMapper.h"
#include "../lib-common/include/SnowFlake.h"

constexpr auto DATABASE1 = "stk_io";
constexpr auto DATABASE2 = "stk_io_entry";
//using CgthckDO = StkIoDO;
//using CgthckEntryDO = StkIoEntryDO;

class CgthckDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CgthckDO& iobj);
	// ��ҳ��ѯ����
	list<CgthckDO> selectById(const string& id);
	// ���뵥������
	uint64_t insert(const CgthckDO& iobj);
	// ���뵥����ϸ
	int insert(const CgthckEntryDO& iobj);
	// �����ļ�
	string insertFile(const string& fileName);
	// ɾ���ļ�
	bool deleteFile(const string& fileName);
	// �޸ĵ�������
	int update(const CgthckDO& iobj);
	// �޸ĵ�����ϸ
	int update(const CgthckEntryDO& iobj);
	// ɾ��ͨ����������
	int deleteById(const CgthckDO& iobj);
};

#endif // !_CGTHCK_DAO_