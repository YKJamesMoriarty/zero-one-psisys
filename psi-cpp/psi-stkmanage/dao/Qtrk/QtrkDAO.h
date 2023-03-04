#pragma once
#ifndef _QTRK_DAO_
#define _QTRK_DAO_

#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillDetailsVO.h"
#include "../../domain/query/Qtrk/QueryQtrkBillListQuery.h"
#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"
#include"domain/do/Qtrk/ModifyQtrkBillStatusDO.h"
#include"domain/do/Qtrk/DeleteBill.h"

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
	
	//��ѯ�����б�
	std::list<StkIoDO> selectBillList(const QueryQtrkBillListQuery query);

	//��ѯ���������б���Ϣ
	list<StkIoDO>selectBillListByBillNo(string BillNo);

	//��ѯ������ϸ��Ϣ
	list<StkIoEntryDO> selectBillDetails(string billNo);

	int updataBillStatus(const ModifyQtrkBillStatusDO& doObject);


	int deleteBill(const DeleteBill& doObject);
};

#endif // !_QTRK_DAO_
