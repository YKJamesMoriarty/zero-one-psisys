#include "stdafx.h"
#include "PurReqController.h"

//��ѯ������Ϣ
JsonVO<PageVO<PurReqFindBillVO>> PurReqController::execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload){
	PurReqFindBillVO test1;
	list<PurReqFindBillVO> ls; 
	ls.push_back(test1);
	PageVO<PurReqFindBillVO> result(1, 2, 0, 0, ls);
	return JsonVO<PageVO<PurReqFindBillVO>>(result, RS_SUCCESS);
}

//��ѯָ��������ϸ��Ϣ
JsonVO<PurReqFindDetailBillVO> PurReqController::execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload){
	PurReqFindDetailBillVO result;
	return JsonVO<PurReqFindDetailBillVO>(result, RS_SUCCESS);
}