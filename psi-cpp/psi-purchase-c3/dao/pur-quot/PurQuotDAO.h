
#ifndef _PUR_QUOT_DAO_H_
#define _PUR_QUOT_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"
#include "../../domain/do/pur-quot/PurQuotNaiGuanDO.h"

class PurQuotDAO : public BaseDAO {
public:
	//ͳ����������
	uint64_t count(const PurQuotDO& iObj);
	uint64_t count(const PurQuotEntryDO& iObj);

	//��ѯ�����б�,���ض������
	list<PurQuotDO> selectPurQuotFindBill(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//���۵��б�(�������)
	list<PurQuotEntryDO> selectPurQuotList(const PurQuotEntryDO& obj);
	//���۵���¼�б�(�������)
	list<PurQuotEntryDO> selectPurQuotDividedList(const PurQuotEntryDO& obj);

	//��DO�������BaseVO
	list<PurQuotDO> selectPurQuotBase(const PurQuotDO& obj);
	//��DO�������DetailVO
	list<PurQuotEntryDO> selectPurQuotDetail(const PurQuotEntryDO& obj);


	// ��������
	uint64_t insert(const PurQuotNaiGuanDO& iObj);
	// �޸�����
	int update(const PurQuotNaiGuanDO& uObj);
	// ͨ��bill_noɾ������
	int deleteByBillNo(const PurQuotNaiGuanDO& dObj);
	// ͨ��bill_no�޸ı���״̬
	int updateBillStatus(const PurQuotNaiGuanDO& ubsObj);

	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	
};

#endif