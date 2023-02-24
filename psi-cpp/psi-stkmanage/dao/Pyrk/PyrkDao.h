#pragma once
#ifndef _PYRK_DAO_
#define _PYRK_DAO_
#include "BaseDAO.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
class PyrkDao : public BaseDAO {
public:
	// ����username��ѯ���������Ŵ���
	string selectOrgCodeByUsername(const string& username);
	// ���ݵ��ݱ�Ų���id
	string selectBillIdByBillNo(const string& billNo);
	// ���ݵ��ݱ�Ų��丽����
	string selectAttachmentByBillNo(const string& billNo);
	// ������������ѯ�ֿ�id
	string selectWarehouseIdByAuxName(const string& warehouse);
	// ������������ѯ����id
	string selectMaterialIdByAuxName(const string& material);
	// �������ֲ�ѯ��λid
	string selectUnitIdByName(const string& unit);
	// ��������
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// �ϴ�����
	string insertAttachment(const string& fileName);
	// ɾ���ļ�
	bool deleteAttachment(const string& fileName);
	// ��˵��ݸ�������
	int updateApproval(const StkIoDO& iObj);
	// �޸�����
	int update(const StkIoDO& iObj);
	// �޸ĵ���״̬
	int updateState(const StkIoDO& iObj);
	// ���ݵ��ݱ�Ų�ѯ��ϸ��¼���б�
	list<int> selectEntryNoByBillNo(const string& billNo);
	// ������ϸ
	int update(const StkIoEntryDO& iObj);
	// ���ݵ��ݱ��ɾ������
	int deleteBillById(const string& billNo);
	// ���ݵ��ݱ�źͷ�¼��ɾ����ϸ
	int deleteDetailById(const string& billNo, const int& entryNo);
	// ���ݵ��ݱ��ɾ��������ϸ
	int deleteDetailById(const string& billNo);
};
#endif