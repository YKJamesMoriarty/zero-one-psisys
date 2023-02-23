
#ifndef _PUR_QUOT_DAO_H_
#define _PUR_QUOT_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"


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
	PurQuotDO selectPurQuotBase(const PurQuotDO& obj);
	//��DO�������DetailVO
	PurQuotEntryDO selectPurQuotDetail(const PurQuotEntryDO& obj);

	
};

#endif