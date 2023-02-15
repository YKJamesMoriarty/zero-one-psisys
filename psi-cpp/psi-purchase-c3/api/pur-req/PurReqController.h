#pragma once

#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

#include"api/ApiHelper.h"



//�����ӿ�
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"

//��ѯ�����б�
#include "../../domain/query/pur-req/PurReqFindBillQuery.h"
#include "../../domain/vo/pur-req/PurReqFindBillVO.h"

//��ѯָ�������б�
#include "../../domain/query/pur-req/PurReqFindDetailBillQuery.h"
#include "../../domain/vo/pur-req/PurReqFindDetailBillVO.h"

//����
#include "../../domain/dto/pur-req/PurReqExportDTO.h"
//����
#include "../../domain/dto/pur-req/PurReqIntoDTO.h"
#include "../../domain/vo/pur-req/PurReqIntoVO.h"

/**
 * �ɹ����빦�ܵ�
 */
class PurReqController
{
public:
	//�ӿ�1 �������뵥
	CREATE_API_FUN_BODY_PAYLOAD(queryPurReqExport, execPurReqExport, PurReqExportDTO);
  //�ӿ�2 �������뵥
	CREATE_API_FUN_BODY_FILE(modifyPurReqInto, execPurReqInto, PurReqIntoDTO);
	
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindBill, execQueryPurReqFindBill,PurReqFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindDetailBill, execQueryPurReqFindDetailBill, PurReqFindDetailBillQuery);
private:
	//��ѯ�����б�
	JsonVO<PageVO<PurReqFindBillVO>> execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	JsonVO<PurReqFindDetailBillVO> execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload);
		//ִ�з���������
	nlohmann::json execPurReqExport(const PurReqExportDTO &dto, const PayloadDTO &payload);
	//ִ�з���������
	JsonVO<PurReqIntoVO> execPurReqInto(const PurReqIntoDTO& dto);
};
#endif 

