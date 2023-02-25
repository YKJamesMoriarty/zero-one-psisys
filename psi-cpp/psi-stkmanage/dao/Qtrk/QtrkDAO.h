#pragma once
#ifndef _QTRK_DAO_
#define _QTRK_DAO_

#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"

class QtrkDAO : public BaseDAO {
public:
	// ��������
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// ��˵��ݸ�������
	int updateApproval(const StkIoDO& iObj);
	// �޸�����
	int update(const StkIoDO& iObj);
	// ������ϸ
	int update(const StkIoEntryDO& iObj);
	// ���ݵ��ݱ�źͷ�¼��ɾ����ϸ
	int deleteDetailById(const string& billNo, const int& entryNo);
};

#endif // !_QTRK_DAO_