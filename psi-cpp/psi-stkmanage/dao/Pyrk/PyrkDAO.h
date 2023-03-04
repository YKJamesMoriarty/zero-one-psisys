#pragma once
#ifndef _PYRK_DAO_
#define _PYRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillDetailsVO.h"
#include "../../domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"

class PyrkDAO : public BaseDAO {
public:
	
	// ��������
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// ��˵��ݸ�������
	int updateApproval(const StkIoDO& iObj);
	// �޸�����
	int update(const StkIoDO& iObj);
	// �޸ĵ���״̬
	int updateState(const StkIoDO& iObj);
	// ������ϸ
	int update(const StkIoEntryDO& iObj);
	// ���ݵ��ݱ��ɾ������
	int deleteBillById(const string& billNo);
	// ���ݵ��ݱ�źͷ�¼��ɾ����ϸ
	int deleteDetailById(const string& billNo, const int& entryNo);
	// ���ݵ��ݱ��ɾ��������ϸ
	int deleteDetailById(const string& billNo);
	
	//��ѯ�����б�
	std::list<StkIoDO> selectBillList(const QueryPyrkBillListQuery query);

	//��ѯ���������б���Ϣ
	list<StkIoDO>selectBillListByBillNo(string BillNo);

	//��ѯ������ϸ��Ϣ
	list<StkIoEntryDO> selectBillDetails(string billNo);
	
	// ͳ����������
	uint64_t count(const QueryPyrkBillListDo& Obj);
};
#endif
