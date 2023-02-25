#include "stdafx.h"
#include "PrePayService.h"
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "../lib-common/include/SimpleDateTimeFormat.h"

// 分页查询 预付申请单所有数据(多个对象)
PageVO<PrepaymentBillVO> PrePayService::listAll(const PrepayBillQuery& query)
{
	//构建返回对象
	PageVO<PrepaymentBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//查询数据总条数
	PrepaymentDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	PrepaymentDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<PrepaymentDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PrepaymentBillVO> vr;
	for (PrepaymentDO sub : result)
	{
		PrepaymentBillVO vo;
		vo.setId(sub.getId());
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setAmt(sub.getAmt());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
// 查询指定单据详细信息-通过单据编号查询数据
PageVO<PrepaymentDetailBillVO> PrePayService::getAll(const PrepayDetailBillQuery& query) {
	PageVO<PrepaymentDetailBillVO> pages;
	//PrepaymentDO obj;
	//obj.setBill_no(query.getBill_no());
	//PrepaymentDAO dao;
	//list <PrepaymentDO> result=dao.selectByBill_no(query.getBill_no());
	//list<PrepaymentDetailBillVO> vr;
	//for (PrepaymentDO sub : result)
	//{
	//	PrepaymentBillVO vo;
	//	vo.setId(vo.getId());
	//	vo.setBill_no(vo.getBill_no());
	//	vo.setBill_date(vo.getBill_date());
	//	vo.setAmt(vo.getAmt());
	//	vr.push_back(vo);
	//}
	//pages.setRows(vr);
	return pages;
}

// 保存数据
uint64_t PrePayService::saveData(const AddPayDTO& dto)
{
	//组装数据
	PrepaymentDO data;
	data.setBill_no(dto.getBill_no());
	data.setBill_date(dto.getBill_date());
	data.setAmt(dto.getAmt());
	//执行数据添加
	PrepaymentDAO dao;
	return dao.insertPrepay(data);
}

// 修改数据
bool PrePayService::updateData(const PrepaymentDTO& dto)
{
	//组装传输数据
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	data.setBill_date(dto.getBill_date());
	data.setAmt(dto.getAmt());
	//执行数据修改
	PrepaymentDAO dao;
	return dao.updatePrepay(data) == 1;
}

// 通过ID删除数据
bool PrePayService::removeData(uint64_t id)
{
	PrepaymentDAO dao;
	return dao.deleteById(id) == 1;
}

// 修改单据状态
// 负责人：Andrew
bool PrePayService::updateStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	//组装传输数据
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	data.setUpdate_by(payload.getUsername());
	data.setUpdate_time(SimpleDateTimeFormat::format());

	//执行数据修改
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

// 保存导入数据