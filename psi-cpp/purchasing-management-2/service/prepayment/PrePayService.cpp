#include "stdafx.h"
#include "PrePayService.h"
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "../lib-common/include/SimpleDateTimeFormat.h"
#include "SnowFlake.h"
// ɾ��
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"
// �ɹ������б�
#include "../../domain/do/PurOrder/PurOrderDO.h"
#include "../../domain/do/PurOrder/PurOrderEntryDO.h"

#define SET_X_FROM_Y(x,y,funName) \
x.set##funName(y.get##funName())

#define BASICINF "id,bill_no,bill_begin_date,subject,supplier_id,op_dept,\
op,amt,paid_amt,bill_stage,is_effective,is_closed,is_voided,is_auto,is_rubric,remark,\
effective_time,approver,create_time,create_by,sys_org_code,update_time,update_by"


// ��ҳ��ѯ �ɹ�������������(�������)
// �����ˣ�xubuxi
PageVO<PurOrderVO> PrePayService::listAll(const PurOrderQuery& query)
{
	//�������ض���
	PageVO<PurOrderVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	PurOrderDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	obj.setPur_type(query.getPur_type());
	obj.setPayment_method(query.getPayment_method());
	obj.setSettle_method(query.getSettle_method());
	obj.setSettle_time(query.getSettle_time());
	obj.setDelivery_method(query.getDelivery_method());
	obj.setInvoice_type(query.getInvoice_type());

	obj.setOp_er(query.getOp_er());
	obj.setOp_dept(query.getOp_dept());
	obj.setSupplier_id(query.getSupplier_id());

	PrepaymentDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<PurOrderDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PurOrderVO> vr;
	for (PurOrderDO sub : result)
	{
		PurOrderVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSrc_bill_type(sub.getSrc_bill_type());
		vo.setSrc_bill_id(sub.getSrc_bill_id());
		vo.setSrc_no(sub.getSrc_no());
		vo.setSubject(sub.getSubject());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setPur_type(sub.getPur_type());
		vo.setSupplier_id(sub.getSupplier_id());
		vo.setContact(sub.getContact());
		vo.setPhone(sub.getPhone());
		vo.setFax(sub.getFax());
		vo.setEmail(sub.getEmail());
		vo.setOp_dept(sub.getOp_dept());
		vo.setOp_er(sub.getOp_er());
		vo.setDelivery_method(sub.getDelivery_method());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setDelivery_time(sub.getDelivery_time());
		vo.setTransport_method(sub.getTransport_method());
		vo.setPayment_method(sub.getPayment_method());
		vo.setSettle_method(sub.getSettle_method());
		vo.setSettle_time(sub.getSettle_time());
		vo.setInvoice_method(sub.getInvoice_method());
		vo.setInvoice_type(sub.getInvoice_type());
		vo.setCurrency(sub.getCurrency());
		vo.setExchange_rate(sub.getExchange_rate());
		vo.setQty(sub.getQty());
		vo.setAmt(sub.getAmt());
		vo.setPrepayment_bal(sub.getPrepayment_bal());
		vo.setSettle_qty(sub.getSettle_qty());
		vo.setSettle_amt(sub.getSettle_amt());
		vo.setIn_qty(sub.getIn_qty());
		vo.setIn_cost(sub.getIn_cost());
		vo.setSettled_amt(sub.getSettled_amt());
		vo.setInvoiced_amt(sub.getInvoiced_amt());
		vo.setAttachment(sub.getAttachment());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());
		vo.setBill_stage(sub.getBill_stage());
		vo.setApprover(sub.getApprover());
		vo.setBpmi_instance_id(sub.getBpmi_instance_id());
		vo.setApproval_result_type(sub.getApproval_result_type());
		vo.setApproval_remark(sub.getApproval_remark());
		vo.setIs_effective(sub.getIs_effective());
		vo.setEffective_time(sub.getEffective_time());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setCreate_by(sub.getCreate_by());
		vo.setCreate_time(sub.getCreate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}


//��ѯָ��������ϸ��Ϣ-ͨ�����ݱ�Ų�ѯ����
// �����ˣ�xubuxi
PurOrderVO PrePayService::getAll(const PurOrderQuery& query) {
	// �������ض���
	PurOrderVO detail;

	// ����ģ��ת��
	PurOrderDO obj;
	obj.setBill_no(query.getBill_no());
	PurOrderEntryDO obj2;
	obj2.setBill_no(query.getBill_no());

	// ��ѯָ��ѯ�۵�����
	PrepaymentDAO dao;
	list <PurOrderDO> result = dao.selectByBill_no(obj);
	for (PurOrderDO sub : result)
	{
		PurOrderVO detail;
		detail.setBill_no(sub.getBill_no());
		detail.setBill_date(sub.getBill_date());
		detail.setSrc_bill_type(sub.getSrc_bill_type());
		detail.setSrc_bill_id(sub.getSrc_bill_id());
		detail.setSrc_no(sub.getSrc_no());
		detail.setSubject(sub.getSubject());
		detail.setIs_rubric(sub.getIs_rubric());
		detail.setPur_type(sub.getPur_type());
		detail.setSupplier_id(sub.getSupplier_id());
		detail.setContact(sub.getContact());
		detail.setPhone(sub.getPhone());
		detail.setFax(sub.getFax());
		detail.setEmail(sub.getEmail());
		detail.setOp_dept(sub.getOp_dept());
		detail.setOp_er(sub.getOp_er());
		detail.setDelivery_method(sub.getDelivery_method());
		detail.setDelivery_place(sub.getDelivery_place());
		detail.setDelivery_time(sub.getDelivery_time());
		detail.setTransport_method(sub.getTransport_method());
		detail.setPayment_method(sub.getPayment_method());
		detail.setSettle_method(sub.getSettle_method());
		detail.setSettle_time(sub.getSettle_time());
		detail.setInvoice_method(sub.getInvoice_method());
		detail.setInvoice_type(sub.getInvoice_type());
		detail.setCurrency(sub.getCurrency());
		detail.setExchange_rate(sub.getExchange_rate());
		detail.setQty(sub.getQty());
		detail.setAmt(sub.getAmt());
		detail.setPrepayment_bal(sub.getPrepayment_bal());
		detail.setSettle_qty(sub.getSettle_qty());
		detail.setSettle_amt(sub.getSettle_amt());
		detail.setIn_qty(sub.getIn_qty());
		detail.setIn_cost(sub.getIn_cost());
		detail.setSettled_amt(sub.getSettled_amt());
		detail.setInvoiced_amt(sub.getInvoiced_amt());
		detail.setAttachment(sub.getAttachment());
		detail.setRemark(sub.getRemark());
		detail.setIs_auto(sub.getIs_auto());
		detail.setBill_stage(sub.getBill_stage());
		detail.setApprover(sub.getApprover());
		detail.setBpmi_instance_id(sub.getBpmi_instance_id());
		detail.setApproval_result_type(sub.getApproval_result_type());
		detail.setApproval_remark(sub.getApproval_remark());
		detail.setIs_effective(sub.getIs_effective());
		detail.setEffective_time(sub.getEffective_time());
		detail.setIs_closed(sub.getIs_closed());
		detail.setIs_voided(sub.getIs_voided());
		detail.setSys_org_code(sub.getSys_org_code());
		detail.setCreate_by(sub.getCreate_by());
		detail.setCreate_time(sub.getCreate_time());
		detail.setUpdate_by(sub.getUpdate_by());
		detail.setUpdate_time(sub.getUpdate_time());
		detail.setVersion(sub.getVersion());
	}

	return detail;
}


// ͨ��IDɾ������
// �����ˣ�xubuxi
bool PrePayService::DePrePayId(const DePayDTO& dto)
{
	PrepaymentDAO dao;
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
	return false;
}

// ��ҳ��ѯ Ԥ�����뵥��������(�������)
// �����ˣ�Qi
PageVO<PrepaymentBillVO> PrePayService::listAll(const PrepayBillQuery& query)
{
	//�������ض���
	PageVO<PrepaymentBillVO> pages;

	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������

	PrepaymentDO obj;
	SET_X_FROM_Y(obj, query, Bill_no);
	SET_X_FROM_Y(obj, query, Bill_begin_date);
	SET_X_FROM_Y(obj, query, Bill_end_date);
	SET_X_FROM_Y(obj, query, Subject);
	SET_X_FROM_Y(obj, query, Supplier_id);
	SET_X_FROM_Y(obj, query, Bill_stage);
	SET_X_FROM_Y(obj, query, Is_effective);
	SET_X_FROM_Y(obj, query, Is_closed);
	SET_X_FROM_Y(obj, query, Is_voided);

	PrepaymentDAO dao;
	uint64_t count = dao.count(obj);

	if (count <= 0)
	{
		return pages;
	}
	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<PrepaymentDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PrepaymentBillVO> vr;
	for (PrepaymentDO sub : result)
	{
		PrepaymentBillVO vo;

		SET_X_FROM_Y(vo, sub, Id);
		SET_X_FROM_Y(vo, sub, Bill_no);
		vo.setBill_date(sub.getBill_begin_date());
		SET_X_FROM_Y(vo, sub, Subject);
		SET_X_FROM_Y(vo, sub, Supplier_id);
		SET_X_FROM_Y(vo, sub, Op_dept);
		SET_X_FROM_Y(vo, sub, Operator);
		SET_X_FROM_Y(vo, sub, Amt);
		SET_X_FROM_Y(vo, sub, Paid_amt);
		SET_X_FROM_Y(vo, sub, Bill_stage);
		SET_X_FROM_Y(vo, sub, Is_effective);
		SET_X_FROM_Y(vo, sub, Is_closed);
		SET_X_FROM_Y(vo, sub, Is_voided);
		SET_X_FROM_Y(vo, sub, Remark);
		SET_X_FROM_Y(vo, sub, Effective_time);
		SET_X_FROM_Y(vo, sub, Approver);
		SET_X_FROM_Y(vo, sub, Create_time);
		SET_X_FROM_Y(vo, sub, Create_by);
		SET_X_FROM_Y(vo, sub, Sys_org_code);
		SET_X_FROM_Y(vo, sub, Update_time);
		SET_X_FROM_Y(vo, sub, Update_by);
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

// ��ѯָ��������ϸ��Ϣ-ͨ�����ݱ�Ų�ѯ����
// �����ˣ�Qi
PageVO<PrepaymentDetailBillVO> PrePayService::getAll(const PrepayDetailBillQuery& query) {
	//�������ض���
	PageVO<PrepaymentDetailBillVO> pages;

	PrepaymentDetailDO obj;
	obj.setBill_no(query.getBill_no());

	PrepaymentDAO dao;

	uint64_t count = dao.countDetail(obj);

	if (count <= 0)
	{
		return pages;
	}

	//�����ܸ���
	pages.setTotal(count);

	list <PrepaymentDetailDO> result = dao.selectByBill_no(query.getBill_no());
	list<PrepaymentDetailBillVO> vr;
	for (PrepaymentDetailDO sub : result)
	{
		PrepaymentDetailBillVO vo;
		SET_X_FROM_Y(vo, sub, Id);
		SET_X_FROM_Y(vo, sub, Entry_no);
		SET_X_FROM_Y(vo, sub, Src_no);
		SET_X_FROM_Y(vo, sub, Amt);
		SET_X_FROM_Y(vo, sub, Remark);
		SET_X_FROM_Y(vo, sub, Custom1);
		SET_X_FROM_Y(vo, sub, Custom2);
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

// ��������
// �����ˣ�Qi
uint64_t PrePayService::saveData(const AddPayDTO& dto, const PayloadDTO& payload)
{
	PrepaymentDO data;
	SnowFlake sf(1, 4);
	//��װDO
	data.setId(to_string(sf.nextId()));
	SET_X_FROM_Y(data, dto, Bill_no);
	data.setBill_begin_date(dto.getBill_date());
	data.setBill_end_date(dto.getBill_date());
	SET_X_FROM_Y(data, dto, Subject);
	SET_X_FROM_Y(data, dto, Operator);
	SET_X_FROM_Y(data, dto, Op_dept);
	SET_X_FROM_Y(data, dto, Supplier_id);
	data.setRemark(dto.getAt_remark());
	SET_X_FROM_Y(data, dto, Attachment);
	SET_X_FROM_Y(data, dto, Bill_stage);
	SET_X_FROM_Y(data, dto, Is_effective);
	SET_X_FROM_Y(data, dto, Is_closed);
	SET_X_FROM_Y(data, dto, Is_voided);
	SET_X_FROM_Y(data, dto, Is_auto);
	SET_X_FROM_Y(data, dto, Is_rubric);
	SET_X_FROM_Y(data, dto, Version);
	data.setCreate_by(payload.getUsername());
	data.setSys_org_code(payload.getDepartment());
	list<PrepaymentDetailDO> d;

	double amt_count = 0;
	double paid_amt_count = 0;
	for (AddPayDetailDTO x : dto.getDetail()) {
		//��װ��ϸ
		PrepaymentDetailDO dtdata;
		dtdata.setId(to_string(sf.nextId()));
		dtdata.setMid(data.getId());
		dtdata.setBill_no(data.getBill_no());
		SET_X_FROM_Y(dtdata, x, Entry_no);
		SET_X_FROM_Y(dtdata, x, Src_bill_type);
		SET_X_FROM_Y(dtdata, x, Src_bill_id);
		SET_X_FROM_Y(dtdata, x, Src_entry_id);
		SET_X_FROM_Y(dtdata, x, Src_no);
		SET_X_FROM_Y(dtdata, x, Amt);
		SET_X_FROM_Y(dtdata, x, Paid_amt);
		amt_count += x.getAmt();
		paid_amt_count += x.getPaid_amt();
		SET_X_FROM_Y(dtdata, x, Remark);
		SET_X_FROM_Y(dtdata, x, Paid_amt);
		SET_X_FROM_Y(dtdata, x, Custom1);
		SET_X_FROM_Y(dtdata, x, Custom2);
		d.push_back(dtdata);
	}
	data.setDetail(d);
	//ͳ�ƽ��
	data.setAmt(amt_count);
	data.setPaid_amt(paid_amt_count);

	//ִ���������
	PrepaymentDAO dao;
	return dao.insertPrepay(data);
}

// �޸�����
/*
	��1������ǰ�˴�����id,�Ա������޸Ķ�Ӧ������
	��2��ɾ��������ϸ����Mid��ǰ�˴�����IDһ����
	��3�����²����Ӧ���µ���ϸ��
*/
// �����ˣ�Qi
bool PrePayService::updateData(const AddPayDTO& dto, const PayloadDTO& payload)
{
	//��װ��������
	PrepaymentDO data;
	PrepaymentDetailDO dtdata;

	//��װDO
	SET_X_FROM_Y(data, dto, Id);
	data.setBill_begin_date(dto.getBill_date());
	data.setBill_end_date(dto.getBill_date());
	SET_X_FROM_Y(data, dto, Subject);
	SET_X_FROM_Y(data, dto, Operator);
	SET_X_FROM_Y(data, dto, Op_dept);
	SET_X_FROM_Y(data, dto, Supplier_id);
	data.setRemark(dto.getAt_remark());
	SET_X_FROM_Y(data, dto, Attachment);
	SET_X_FROM_Y(data, dto, Bill_stage);
	SET_X_FROM_Y(data, dto, Is_effective);
	SET_X_FROM_Y(data, dto, Is_closed);
	SET_X_FROM_Y(data, dto, Is_voided);
	SET_X_FROM_Y(data, dto, Is_auto);
	SET_X_FROM_Y(data, dto, Is_rubric);
	SET_X_FROM_Y(data, dto, Version);
	data.setUpdate_by(payload.getUsername());
	SnowFlake sf(1, 4);
	list<PrepaymentDetailDO> d;

	double amt_count = 0;
	double paid_amt_count = 0;
	for (AddPayDetailDTO x : dto.getDetail()) {
		//��װ��ϸ
		PrepaymentDetailDO dtdata;
		dtdata.setId(to_string(sf.nextId()));
		dtdata.setMid(data.getId());
		dtdata.setBill_no(data.getBill_no());
		SET_X_FROM_Y(dtdata, x, Entry_no);
		SET_X_FROM_Y(dtdata, x, Src_bill_type);
		SET_X_FROM_Y(dtdata, x, Src_bill_id);
		SET_X_FROM_Y(dtdata, x, Src_entry_id);
		SET_X_FROM_Y(dtdata, x, Src_no);
		SET_X_FROM_Y(dtdata, x, Amt);
		SET_X_FROM_Y(dtdata, x, Paid_amt);
		amt_count += x.getAmt();
		paid_amt_count += x.getPaid_amt();
		SET_X_FROM_Y(dtdata, x, Remark);
		SET_X_FROM_Y(dtdata, x, Paid_amt);
		SET_X_FROM_Y(dtdata, x, Custom1);
		SET_X_FROM_Y(dtdata, x, Custom2);
		d.push_back(dtdata);
	}
	data.setDetail(d);
	//ͳ�ƽ��
	data.setAmt(amt_count);
	data.setPaid_amt(paid_amt_count);

	//ִ�������޸�
	PrepaymentDAO dao;
	return dao.updatePrepay(data);
}


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
	return false;
}