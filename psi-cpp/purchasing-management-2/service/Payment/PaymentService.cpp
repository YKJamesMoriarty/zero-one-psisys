#include "stdafx.h"
#include "PaymentService.h"
#include "../../dao/Payment/PaymentDAO.h"

//// 通过ID删除数据
////bool PrePayService::removeData(uint64_t id)
////{
////	PrepaymentDAO dao;
////	return dao.deleteById(id) == 1;
////}

// 修改单据状态
bool PaymentService::ChangePayStatus(const PaymentChangeDTO& dto)
{
	//组装传输数据
	PurReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//执行数据修改
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

// 保存导入数据