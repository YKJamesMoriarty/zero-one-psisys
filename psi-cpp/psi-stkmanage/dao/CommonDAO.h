#pragma once
#ifndef _COMMON_DAO_
#define _COMMON_DAO_

#include "BaseDAO.h"

/*
* ���ڽ��в�ѯָ�����ݵ�DAO
*/
class CommonDAO : public BaseDAO
{
public:
	// ����username��ѯ���������Ŵ���
	string selectOrgCodeByUsername(const string& username);
	// ���ݵ��ݱ�Ų���id
	string selectBillIdByBillNo(const string& billNo);
	// ���ݵ��ݱ�Ų��丽����
	string selectAttachmentByBillNo(const string& billNo);
	// ���ݵ��ݱ�Ų�ѯ��ϸ��¼���б�
	list<int> selectEntryNoByBillNo(const string& billNo);
};

#endif // !_COMMON_DAO_
