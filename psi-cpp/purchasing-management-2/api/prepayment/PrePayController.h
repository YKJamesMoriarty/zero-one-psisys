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
	//����
	CREATE_API_FUN_BODY(modifyPayInto, execPayInto, PayIntoDTO);
	//��ѯ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill, execQueryPrepayFindBill, PrepayBillQuery);
	//��ѯָ��������ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill, execQueryPayDetailBill, PrepayDetailBillQuery);
	//�������뵥
	CREATE_API_FUN_BODY_PAYLOAD(queryPayExport, execPrepayExport, PrePayExportQuery);
	//��Ӷ���
	CREATE_API_FUN_BODY(addPay, execAddPay, AddPayDTO);
	//�޸Ķ���
	CREATE_API_FUN_BODY(modifyPay, execModifyPay, PrepaymentDTO);
	//ɾ������
	CREATE_API_FUN_BODY(removeDePay, execRemoveDePay, DePayDTO);
	CREATE_API_FUN_BODY(removePayById, execRemovePayById, IntID);
	//�޸ĵ���״̬(�رա����ϡ����ر�)
	CREATE_API_FUN_BODY(modifyPurReqBillStatus, execModifyPayBillStatus, PayModBillStatusDTO);

private:
	//�޸ĵ���״̬(�رա����ϡ����ر�)
	JsonVO<string> execModifyPayBillStatus(const PayModBillStatusDTO& dto);
	//��ѯ
	JsonVO<PageVO<PrepaymentBillVO>> execQueryPrepayFindBill(const PrepayBillQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	JsonVO<PrepaymentDetailBillVO> execQueryPayDetailBill(const PrepayDetailBillQuery& query, const PayloadDTO& payload);
	//����
	JsonVO<PrepaymentExportVO> execPrepayExport(const PrePayExportQuery& query, const PayloadDTO& payload);
	//��������
	JsonVO<uint64_t> execAddPay(const AddPayDTO& dto);
	//�޸Ķ���
	JsonVO<string> execModifyPay(const PrepaymentDTO& dto);
	//ɾ������
	JsonVO<uint64_t> execRemoveDePay(const DePayDTO& dto);
	JsonVO<uint64_t> execRemovePayById(const IntID& id);
	//����
	JsonVO<uint64_t> execPayInto(const PayIntoDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_