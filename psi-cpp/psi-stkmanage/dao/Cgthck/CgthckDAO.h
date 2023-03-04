#pragma once
//
#ifndef _CGRK_DAO_
#define _CGRK_DAO_
#include "BaseDAO.h"
#include "FastDfsClient.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../service/Cgthck/CgthckMapper.h"
#include "../lib-common/include/SnowFlake.h"
#include"domain/do/Cgthck/QueryCgthrkBillListDO.h"
#include"domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"
#include"domain/vo/Cgthck/BillEntryDetailedVO.h"
#include"domain/do/Cgthck/BillDetailedDO.h"
#include"../../domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"
#include"../../domain/do/Cgthck/QueryCgthrkBillDetailedReturnDO.h"

#include"list"
class CgthckDAO : public BaseDAO {
public:
	uint64_t count(const CgthckEntryDO& iobj);
	list<CgthckEntryDO> selectWithId(const CgthckEntryDO& iobj);
	// ͳ����������
	uint64_t count(const QueryCgthrkBillListDO& Obj);
	// ��ѯ�����б�
	list<QueryCgthrkBillListReturnDO> selectCgthckBillList(const QueryCgthrkBillListDO& Obj, uint64_t pageIndex, uint64_t pageSize);
	// ��ѯ��ϸ��Ϣ
	QueryCgthrkBillDetailedReturnDO selectCgthckBillListDetailed(const BillDetailedDO& Obj);
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
	// ����
	int updateApproval(const CgthckDO& iobj);
	// �޸�״̬
	int updateStatus(const CgthckDO& iobj);
	// ɾ��ͨ����������
	int deleteBillById(const string& billNo);
	// ɾ��ͨ��������ϸ
	int deleteEntryById(const string& billNo);
	int deleteEntryById(const string& billNo, const string& entryNo);
	// ����
	uint64_t importData(const CgthckDO& iobj);
	uint64_t importData(const CgthckEntryDO& iobj);
	// ����
	list< CgthckDO> exportData(const CgthckDO& iobj);
	list< CgthckEntryDO> exportData(const CgthckEntryDO& iobj);
};





#endif

