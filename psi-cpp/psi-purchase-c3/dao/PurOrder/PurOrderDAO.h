#pragma once

#ifndef _PUR_ORDER_DAO_H_
#define _PUR_ORDER_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderDividedListDO.h"
class PurOrderDAO : public BaseDAO {
public:
	//�ɹ����뵥��¼�б�
	list<PurOrderDividedListDO> selectPurOrderDividedListDO(const PurOrderDividedListDO& obj);
};

#endif