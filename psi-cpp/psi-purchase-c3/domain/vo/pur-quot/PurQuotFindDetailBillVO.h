#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#include "../../GlobalInclude.h"
#include "PurQuotBaseVO.h"
#include "PurQuotDetailVO.h"

//ָ��������ϸ�б��VO
class PurQuotFindDetailBillVO{
	CC_SYNTHESIZE(PurQuotBaseVO, base_vo, Base_vo);
	CC_SYNTHESIZE(list<PurQuotDetailVO>, detail_vo, Detail_vo);
public:
	BIND_TO_JSON(PurQuotFindDetailBillVO, base_vo, detail_vo);
	//Ĭ�Ϲ��캯��
	PurQuotFindDetailBillVO() {}
	PurQuotFindDetailBillVO(PurQuotBaseVO &b_vo, list<PurQuotDetailVO> &entry_vo) :base_vo(b_vo), detail_vo(entry_vo){}
};

#endif