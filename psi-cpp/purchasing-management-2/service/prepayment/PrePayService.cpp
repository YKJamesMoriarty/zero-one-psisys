#include "stdafx.h"
#include "PrePayService.h"
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "../lib-common/include/SimpleDateTimeFormat.h"

// �޸ĵ���״̬(�ر�/���ر�/����)
// �����ˣ�Andrew
bool PrePayService::updateStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	//��װ��������
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	data.setUpdate_by(payload.getUsername());
	data.setUpdate_time(SimpleDateTimeFormat::format());

	//ִ�������޸�
	PrepaymentDAO dao;
	if (dto.getOpType() == PayModBillStatusDTO::CLOSE || dto.getOpType() == PayModBillStatusDTO::UNCLOSE)
	{
		data.setIs_closed(dto.OPS[dto.getOpType()]);
		return dao.updateStatusClose(data) == 1;
	}
	else if (dto.getOpType() == PayModBillStatusDTO::CANCEL)
	{
		data.setIs_voided(dto.OPS[dto.getOpType()]);
		return dao.updateStatusCancel(data) == 1;
	}
}