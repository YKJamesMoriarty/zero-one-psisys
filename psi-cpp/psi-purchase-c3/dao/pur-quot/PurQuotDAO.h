
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
	list<PurQuotDO> selectPurQuotFindBillDO(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize);

	////��ѯָ��������ϸ��Ϣ
	//list<xx> selectPurQuotFindDetailBillDO(const PurQuotFindDetailBillDO& obj);
	////���۵��б�
	//list<PurQuotListDO> selectPurQuotListDO(const PurQuotListDO& obj);
	////���۵���¼�б�
	//list<PurQuotDividedListDO> selectPurQuotDividedListDO(const PurQuotDividedListDO& obj);
	
};

#endif