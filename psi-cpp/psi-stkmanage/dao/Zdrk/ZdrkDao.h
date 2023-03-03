#pragma once
#ifndef _ZDRK_DAO_
#define _ZDRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/SysDictDO.h"
#include "../../domain/do/StkIoDO.h"
#include "../../domain/do/StkIoEntryDO.h"
#endif //!_ZDRK_DAO_

/**
 * �Ƕ�������ݿ����ʵ��
 */
class ZdrkDAO : public BaseDAO
{
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
};


