
//����ͷ�ļ�
#pragma once
#ifndef _PUR_ORDER_CONTROLLER_H_
#define _PUR_ORDER_CONTROLLER_H_
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"



#include "../../domain/query/PurOrder/PurOrderDividedListQuery.h"
#include "../../domain/vo/PurOrder/PurOrderDividedListVO.h"
#include "../../service/PurOrder/PurOrderService.h"

class PurOrderController
{
public:
	//ѯ�۵���¼�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurOrderDividedList, execQueryPurOrderDividedList, PurOrderDividedListQuery);
private:
	// ��ѯѯ�۵���¼�б�
	JsonVO<list<PurOrderDividedListVO>> execQueryPurOrderDividedList(const PurOrderDividedListQuery& query, const PayloadDTO& payload) {
		//�������ض���
		list<PurOrderDividedListVO> result;
		//����У��
		if (query.getBillNo() == "") return JsonVO<list<PurOrderDividedListVO>>(result, RS_PARAMS_INVALID);
		//����У��ɹ�,���ض�Ӧ�Ķ���
		PurOrderService service;
		result = service.listPurOrderDividedListDO(query);
		return JsonVO<list<PurOrderDividedListVO>>(result, RS_SUCCESS);
	}
};
#endif // _PUI_QUOT_CONTROLLER_




