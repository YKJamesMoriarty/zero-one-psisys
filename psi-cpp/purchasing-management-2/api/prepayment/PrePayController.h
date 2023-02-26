#pragma once
#ifndef _PRE_PAY_CONTROLLER_
#define _PRE_PAY_CONTROLLER_

#include"api/ApiHelper.h"

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//�鿴Ԥ�����뵥�б�
#include "../../domain/query/prepaymentbill/PrepayBillQuery.h"
#include "../../domain/query/prepaymentbill/PrepayDetailBillQuery.h"
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
//vo
#include "../../domain/vo/prepaymentbill/PrepaymentBillVO.h"
#include "../../domain/vo/prepaymentbill/PrepaymentDetailBillVO.h"
//�����޸�ɾ��Ԥ�����뵥�б�
#include "../../domain/dto/prepayment/AddPayDTO.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/dto/prepayment/PayModBillStatusDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
//���뵼��
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../../domain/vo/prepayment_req/PrepaymentExportVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentIntoVO.h"
#include "../../domain/dto/prepayment/PayIntoDTO.h"


/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PrePayController
{
public:

	//��ѯ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill, execQueryPrepayFindBill, PrepayBillQuery);
	//��ѯָ��������ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill, execQueryPayDetailBill, PrepayDetailBillQuery);
	//ɾ������
	CREATE_API_FUN_BODY(removeDePayId, execRemoveDePayId, DePayDTO);
	//CREATE_API_FUN_BODY(removePayById, execRemovePayById, IntID);


private:
	
	//��ѯ
	JsonVO<PageVO<PrepaymentBillVO>> execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	JsonVO<PrepaymentDetailBillVO> execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload);
	//ɾ������
	JsonVO<string> execRemoveDePayId(const DePayDTO& dto);
	//JsonVO<uint64_t> execRemovePayById(const IntID& id);

};

#endif // _SAMPLE_CONTROLLER_