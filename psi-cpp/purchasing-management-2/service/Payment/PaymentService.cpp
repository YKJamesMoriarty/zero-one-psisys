#include "stdafx.h"
#include "PaymentService.h"
#include "../../dao/Payment/PaymentDAO.h"

// ͨ��IDɾ������
bool PaymentService::DePayment(const DePaymentDTO& dto)
{
	//��װ��������
	PaymentDAO dao;
	PurReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
}

// �޸ĵ���״̬
bool PaymentService::ChangePayStatus(const PaymentChangeDTO& dto)
{
	//��װ��������
	PurReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	PaymentDAO dao;
	if (dto.getOpType() == PaymentChangeDTO::CLOSE || dto.getOpType() == PaymentChangeDTO::UNCLOSE)
	{
		data.setIs_closed(dto.getIs_closed());
		return dao.ChangeStatusClose(data) == 1;
	}
	else if (dto.getOpType() == PaymentChangeDTO::CANCEL)
	{
		data.setIs_voided(dto.getIs_voided());
		return dao.ChangeStatusCancel(data) == 1;
	}
}

// ���浼������