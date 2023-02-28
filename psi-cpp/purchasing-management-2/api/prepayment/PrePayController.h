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

private:
	//�޸ĵ���״̬(�رա����ϡ����ر�)
	// �����ˣ�Andrew
	JsonVO<string> execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& pl);
};

#endif // _SAMPLE_CONTROLLER_