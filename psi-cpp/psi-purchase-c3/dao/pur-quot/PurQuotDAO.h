
#ifndef _PUR_QUOT_H_
#define _PUR_QUOT_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotFindBillDO.h"


class PurQuotDAO : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const PurQuotFindBillDO& iObj);
	//��ѯ�����б�
	list<PurQuotFindBillDO> selectPurQuotFindBillDO(const PurQuotFindBillDO& obj, uint64_t pageIndex, uint64_t pageSize);
};

#endif