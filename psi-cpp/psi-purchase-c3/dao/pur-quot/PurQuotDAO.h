
#ifndef _PUR_QUOT_DAO_H_
#define _PUR_QUOT_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"


class PurQuotDAO : public BaseDAO {
public:
	//ͳ����������
	uint64_t count(const PurQuotDO& iObj);
	//��ѯ�����б�,���ض������
	list<PurQuotDO> selectPurQuotFindBill(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//���۵��б�(�������)
	list<PurQuotEntryDO> selectPurQuotList(const PurQuotEntryDO& obj);
	//���۵���¼�б�(�������)
	list<PurQuotEntryDO> selectPurQuotDividedList(const PurQuotEntryDO& obj);

	//��DO�������BaseVO
	list<PurQuotEntryDO> selectPurQuotBase(const PurQuotEntryDO& obj);

	//��DO�������DetailVO
	
	
};

#endif