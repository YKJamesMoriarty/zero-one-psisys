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
 * �ɹ�Ԥ�����������
 */
class PrePayController
{
public:
	//�޸ĵ���״̬(�رա����ϡ����ر�)
	// �����ˣ�Andrew
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReqBillStatus, execModifyPayBillStatus, PayModBillStatusDTO);
	//��ѯ
	// �����ˣ�Qi
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill, execQueryPrepayFindBill, PrepayBillQuery);
	//��ѯָ��������ϸ��Ϣ
	// �����ˣ�Qi
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill, execQueryPayDetailBill, PrepayDetailBillQuery);
	//��Ӷ���
	// �����ˣ�Qi
	CREATE_API_FUN_JSON_PAYLOAD(addPay, execAddPay, AddPayDTO);
	//�޸Ķ���
	// �����ˣ�Qi
	CREATE_API_FUN_JSON_PAYLOAD(modifyPay, execModifyPay, AddPayDTO);
private:
	//�޸ĵ���״̬(�رա����ϡ����ر�)
	// �����ˣ�Andrew
	JsonVO<string> execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& pl);
	//��ѯ
	// �����ˣ�Qi
	JsonVO<PageVO<PrepaymentBillVO>> execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	// �����ˣ�Qi
	JsonVO<PageVO<PrepaymentDetailBillVO>> execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload);
	//��������
	// �����ˣ�Qi
	JsonVO<uint64_t> execAddPay(const AddPayDTO& dto, const PayloadDTO& payload);
	//�޸Ķ���
	// �����ˣ�Qi
	JsonVO<uint64_t> execModifyPay(const AddPayDTO& dto, const PayloadDTO& payload);
};

#endif // _SAMPLE_CONTROLLER_