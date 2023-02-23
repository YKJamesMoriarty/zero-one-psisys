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
	uint64_t insertIntoBill(const CgthckDO& iobj);
	// ���뵥����ϸ
	int insertIntoEntry(const CgthckEntryDO& iobj);
	// �����ļ�
	string insertFile(const string& fileName);
	// �޸�����
	int update(const CgthckDO& iobj);
	// ɾ��ͨ����������
	int deleteById(const CgthckDO& iobj);
};

#endif // !_CGTHCK_DAO_