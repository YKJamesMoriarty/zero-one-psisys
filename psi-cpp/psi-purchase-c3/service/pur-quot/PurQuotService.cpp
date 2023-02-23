#include "stdafx.h"
#include "PurQuotService.h"
#include "../../dao/pur-quot/PurQuotDAO.h"
#include <list>

//��ȡ���PurQuotFindBillVO����
PageVO<PurQuotFindBillVO> PurQuotService::listPurQuotFindBillVO(const PurQuotFindBillQuery& query) {
	//�������ض���
	PageVO<PurQuotFindBillVO> pages;
	//���÷��ض����Index��Size 
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());
	
	//���ò�ѯ����
	PurQuotDO obj;
	obj.setBill_no(query.getBill_no());
	//���ڴ���,��ʱ����
	obj.setSubject(query.getSubject());
	obj.setBill_stage(query.getBill_stage());
	obj.setIs_effective(query.getIs_effective());
	obj.setIs_closed(query.getIs_closed());
	obj.setIs_voided(query.getIs_voided());
	
	//����ѯ������������
	PurQuotDAO dao;
	uint64_t count = dao.count(obj);
	//��������С�ڵ���0, ֱ�ӷ���pages
	if (count <= 0)
	{
		return pages;
	}
	//������������0, ���ط�ҳ��ѯ����VO
	pages.setTotal(count);
	pages.calcPages();
	//���ղ�ѯ����DO
	list<PurQuotDO> result = dao.selectPurQuotFindBill(obj, query.getPageIndex(), query.getPageSize());
	//vr�ǽ���DO��VO����
	list<PurQuotFindBillVO> vr; 
	for (PurQuotDO sub : result) {
		PurQuotFindBillVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setSubject(sub.getSrc_no());
		vo.setSupplier_id(sub.getSupplier_id());
		vo.setSupplier_name(sub.getSupplier_name());
		vo.setDelivery_time(sub.getDelivery_time());
		vo.setQty(sub.getQty());
		vo.setAmt(sub.getAmt());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setPayment_method(sub.getPayment_method());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setContact(sub.getContact());
		vo.setPhone(sub.getPhone());
		vo.setFax(sub.getFax());
		vo.setEmail(sub.getEmail());
		vo.setRemark(sub.getRemark());
		vo.setIs_auto(sub.getIs_auto());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setEffective_time(sub.getEffective_time());
		vo.setApprover(sub.getApprover());
		vo.setCreate_time(sub.getCreate_time());
		vo.setCreate_by(sub.getCreate_by());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vr.push_back(vo);
	}	
	pages.setRows(vr);
	return pages;
}

//��ȡ���PurQuotList����
list<PurQuotListVO> PurQuotService::listPurQuotListVO(const PurQuotListQuery& query) {
	//���ò�ѯ����
	PurQuotEntryDO obj;
	obj.setBill_no(query.getBill_no());

	//���ղ�ѯ����DO
	PurQuotDAO dao;
	list<PurQuotEntryDO> result = dao.selectPurQuotList(obj);
	//�������ض���
	list<PurQuotListVO> vr;
	for (PurQuotEntryDO sub : result) {
		PurQuotListVO vo;
		vo.setSrc_no(sub.getSrc_no());
		vo.setMaterial_id(sub.getMaterial_id());
		vo.setUnit_id(sub.getUnit_id());
		vo.setQty(sub.getQty());
		vo.setTax_rate(sub.getTax_rate());
		vo.setPrice(sub.getPrice());
		vo.setDiscount_rate(sub.getDiscount_rate());
		vo.setAmt(sub.getAmt());
		vo.setRemark(sub.getRemark());
		vo.setCustom1(sub.getCustom1());
		vo.setCustom2(sub.getCustom2());
		vr.push_back(vo);
	}
	return vr;
}

//��ȡ���PurQuotDividedListVO����
list<PurQuotDividedListVO> PurQuotService::listPurQuotDividedListVO(const PurQuotDividedListQuery& query) {

	//���ò�ѯ����
	PurQuotEntryDO obj;
	obj.setBill_no(query.getBill_no());

	//���ղ�ѯ����DO
	PurQuotDAO dao;
	list<PurQuotEntryDO> result = dao.selectPurQuotDividedList(obj);

	//�������ض���vo
	list<PurQuotDividedListVO> vr;
	for (PurQuotEntryDO sub : result) {
		PurQuotDividedListVO vo;
		vo.setBill_no(sub.getBill_no());
		vo.setMaterial_id(sub.getMaterial_id());
		vo.setUnit_id(sub.getUnit_id());
		vo.setQty(sub.getQty());
		vo.setTax_rate(sub.getTax_rate());
		vo.setPrice(sub.getPrice());
		vo.setAmt(sub.getAmt());
		vo.setRemark(sub.getRemark());
		vo.setCustom1(sub.getCustom1());
		vo.setCustom2(sub.getCustom2());
		vr.push_back(vo);
	}
	return vr;
}

//��ȡһ��PurQuotFindDetailBillVO����
PurQuotFindDetailBillVO PurQuotService::getPurQuotFindDetailBillVO(const PurQuotFindDetailBillQuery& query) {

//----------����BaseVO
	//���ò�ѯ����
	PurQuotDO obj;
	obj.setBill_no(query.getBill_no());

	//���ղ�ѯ����DO
	PurQuotDAO dao;
	list<PurQuotDO> result = dao.selectPurQuotBase(obj); //һ��Base����
	
	PurQuotBaseVO vo;
	if (!result.empty()) {
		auto sub = result.front();
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setBill_stage(sub.getBill_stage());
		vo.setIs_effective(sub.getIs_effective());
		vo.setIs_closed(sub.getIs_closed());
		vo.setIs_voided(sub.getIs_voided());
		vo.setSubject(sub.getSubject());
		vo.setIs_temp_supplier(sub.getIs_temp_supplier());
		vo.setSupplier_id(sub.getSupplier_id());
		vo.setSupplier_name(sub.getSupplier_name());
		vo.setPayment_method(sub.getPayment_method());
		vo.setDelivery_time(sub.getDelivery_time());
		vo.setDelivery_place(sub.getDelivery_place());
		vo.setContact(sub.getContact());
		vo.setPhone(sub.getPhone());
		vo.setFax(sub.getFax());
		vo.setEmail(sub.getEmail());
		vo.setRemark(sub.getRemark());
		vo.setApproval_remark(sub.getApproval_remark());
		vo.setAttachment(sub.getAttachment());
		vo.setApproval_result_type(sub.getApproval_result_type());
		vo.setEffective_time(sub.getEffective_time());
		vo.setApprover(sub.getApprover());
		vo.setBpmi_instance_id(sub.getBpmi_instance_id());
		vo.setSys_org_code(sub.getSys_org_code());
		vo.setCreate_by(sub.getCreate_by());
		vo.setUpdate_time(sub.getUpdate_time());
		vo.setUpdate_by(sub.getUpdate_by());
		vo.setIs_auto(sub.getIs_auto());
		vo.setIs_rubric(sub.getIs_rubric());
		vo.setSrc_bill_type(sub.getSrc_bill_type());
	}



//---------����DetailVO
	PurQuotEntryDO entry_obj;
	entry_obj.setBill_no(query.getBill_no());
	list<PurQuotEntryDO> entry_result = dao.selectPurQuotDetail(entry_obj); //���Base����
	PurQuotDetailVO entry_vo;

	
	
	//�������ض���
	PurQuotFindDetailBillVO vr;
	


}

