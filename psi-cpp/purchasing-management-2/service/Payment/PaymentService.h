#pragma once
#ifndef _PRE_PAY_SERVICE_
#define _PRE_PAY_SERVICE_
#include <list>
//�鿴Ԥ�����뵥�б�
#include "../../domain/query/prepaymentbill/PrepayBillQuery.h"
#include "../../domain/query/prepaymentbill/PrepayDetailBillQuery.h"
#include "../../domain/vo/prepaymentbill/PrepaymentBillVO.h"
#include "../../domain/vo/prepaymentbill/PrepaymentDetailBillVO.h"
//�����޸�ɾ��Ԥ�����뵥�б�
#include "../../domain/dto/prepayment/AddPayDTO.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/dto/payment/PaymentChangeDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
//���뵼��
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../../domain/dto/prepayment/PayIntoDTO.h"
#include "../../domain/vo/prepayment_req/PrepaymentIntoVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentExportVO.h"

#include "../../domain/vo/PageVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 * Ԥ������ķ���ʵ��
 */
class PaymentService
{
public:
	// ͨ��IDɾ������
	/*bool removeData(const PayModBillStatusDTO& dto);*/
	// �޸ĵ���״̬
	bool ChangePayStatus(const PaymentChangeDTO& dto);

};

#endif // !_PRE_PAY_SERVICE_
