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
#include "../../domain/dto/prepayment/PayModBillStatusDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
//���뵼��
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../../domain/dto/prepayment/PayIntoDTO.h"
#include "../../domain/vo/prepayment_req/PrepaymentIntoVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentExportVO.h"

#include "../../domain/vo/PageVO.h"

/**
 * Ԥ������ķ���ʵ��
 */
class PrePayService
{
public:
	// �޸ĵ���״̬(�ر�/���ر�/����)
	// �����ˣ�Andrew
	bool updateStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload);
	// ��ҳ��ѯ Ԥ�����뵥��������(�������)
	// �����ˣ�Qi
	PageVO<PrepaymentBillVO> listAll(const PrepayBillQuery& query);
	// ��ѯԤ�����뵥��ϸ����(��������)
	// �����ˣ�Qi
	PageVO<PrepaymentDetailBillVO> getAll(const PrepayDetailBillQuery& query);
	// ��������
	// �����ˣ�Qi
	uint64_t saveData(const AddPayDTO& dto, const PayloadDTO& payload);
	// �޸�����
	// �����ˣ�Qi
	bool updateData(const AddPayDTO& dto, const PayloadDTO& payload);
};

#endif // !_PRE_PAY_SERVICE_
