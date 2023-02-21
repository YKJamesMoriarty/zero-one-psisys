
#ifndef _PUR_QUOT_DAO_H_
#define _PUR_QUOT_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotFindBillDO.h"
#include "../../domain/do/pur-quot/PurQuotFindDetailBillDO.h"
#include "../../domain/do/pur-quot/PurQuotListDO.h"
#include "../../domain/do/pur-quot/PurQuotDividedListDO.h"

class PurQuotDAO : public BaseDAO {
public:
	//ͳ����������
	uint64_t count(const PurQuotFindBillDO& iObj);
	//��ѯ�����б�
	list<PurQuotFindBillDO> selectPurQuotFindBillDO(const PurQuotFindBillDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//��ѯָ��������ϸ��Ϣ
	list<PurQuotFindDetailBillDO> selectPurQuotFindDetailBillDO(const PurQuotFindDetailBillDO& obj);
	//���۵��б�
	list<PurQuotListDO> selectPurQuotListDO(const PurQuotListDO& obj);
	//���۵���¼�б�
	list<PurQuotDividedListDO> selectPurQuotDividedListDO(const PurQuotDividedListDO& obj);
	
};

#endif