#include "stdafx.h"
#include "PrePayService.h"
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "SnowFlake.h"


#define SET_X_FROM_Y(x,y,funName) \
x.set##funName(y.get##funName())

#define BASICINF "id,bill_no,bill_begin_date,subject,supplier_id,op_dept,\
op,amt,paid_amt,bill_stage,is_effective,is_closed,is_voided,is_auto,is_rubric,remark,\
effective_time,approver,create_time,create_by,sys_org_code,update_time,update_by"


// ��ҳ��ѯ Ԥ�����뵥��������(�������)
PageVO<PrepaymentBillVO> PrePayService::listAll(const PrepayBillQuery& query)
{
	//�������ض���
	PageVO<PrepaymentBillVO> pages;

	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������

	PrepaymentDO obj;
	SET_X_FROM_Y(obj,query,Bill_no);
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
uint64_t PrePayService::saveData(const AddPayDTO& dto, const PayloadDTO& payload)
{
	PrepaymentDO data;
	SnowFlake sf(1,4);
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
	data.setCreate_by(payload.getUsername());
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
		SET_X_FROM_Y(dtdata, x, Remark);
		SET_X_FROM_Y(dtdata, x, Paid_amt);
		SET_X_FROM_Y(dtdata, x, Custom1);
		SET_X_FROM_Y(dtdata, x, Custom2);
		data.getDetail().push_back(dtdata);
	}
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
	data.setUpdate_by(payload.getUsername());
	SnowFlake sf(1, 4);
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
		SET_X_FROM_Y(dtdata, x, Remark);
		SET_X_FROM_Y(dtdata, x, Paid_amt);
		SET_X_FROM_Y(dtdata, x, Custom1);
		SET_X_FROM_Y(dtdata, x, Custom2);
		data.getDetail().push_back(dtdata);
	}
	//ִ�������޸�
	PrepaymentDAO dao;
	return dao.updatePrepay(data);
}

// ͨ��IDɾ������
bool PrePayService::removeData(uint64_t id)
{
	PrepaymentDAO dao;
	return dao.deleteById(id) == 1;
}

// �޸ĵ���״̬
bool PrePayService::updateStatus(const PayModBillStatusDTO& dto)
{
	//��װ��������
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	PrepaymentDAO dao;
	return dao.updateStatus(data) == 1;
}

// ���浼������