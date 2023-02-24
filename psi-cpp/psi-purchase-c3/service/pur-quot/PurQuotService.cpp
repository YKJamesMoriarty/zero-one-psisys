#include "stdafx.h"
#include "PurQuotService.h"
#include "../../dao/pur-quot/PurQuotDAO.h"
#include <list>
#include "../../uselib/fastdfs/TestFastDfs.h"
#include <string>
#include <time.h> 
#include <stdio.h>
#include "../lib-common/include/SnowFlake.h"
#include <cstdlib>
#include <stdlib.h>

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
	//����BaseVO����
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
	//���ò�ѯ����
	PurQuotEntryDO entry_obj;
	entry_obj.setBill_no(query.getBill_no());
	//���ղ�ѯ����DO
	list<PurQuotEntryDO> entry_result = dao.selectPurQuotDetail(entry_obj); //���Base����
	PurQuotDetailVO entry_vo;

	//����DetailVO����
	list<PurQuotDetailVO> entry_vr;
	for (PurQuotEntryDO sub : entry_result) {
		PurQuotDetailVO entry_vo;
		entry_vo.setEntry_src_no(sub.getSrc_no());
		entry_vo.setEntry_material_id(sub.getMaterial_id());
		entry_vo.setEntry_unit_id(sub.getUnit_id());
		entry_vo.setEntry_qty(sub.getQty());
		entry_vo.setEntry_tax_rate(sub.getTax_rate());
		entry_vo.setEntry_price(sub.getPrice());
		entry_vo.setEntry_discount_rate(sub.getDiscount_rate());
		entry_vo.setEntry_amt(sub.getAmt());
		entry_vo.setEntry_remark(sub.getRemark());
		entry_vo.setEntry_custom1(sub.getCustom1());
		entry_vo.setEntry_custom2(sub.getCustom2());
		entry_vr.push_back(entry_vo);
	}
	
	//�������ض���
	PurQuotFindDetailBillVO vr(vo, entry_vr);
	return vr;
}


// �������ۣ���AddPurQuotDTO�е����ݷŽ�PurQuotDO��
uint64_t PurQuotService::saveData(const AddPurQuotDTO& dto, const PayloadDTO& payload)
{
	//TestFastDfs Test;											//�����ϴ����ԣ������IPҪдFastDFS��������IP��ַ
	//Test.testDfs("C:\\Program Files\\architecture.jpg");

	//����ʱ��
	time_t t;					//��t����Ϊʱ�����
	struct tm* p;				//struct tm��һ���ṹ�壬����һ���ṹ��ָ��
	time(&t);
	p = localtime(&t);			//��õ��ص�ʱ��
	char timestr[30];
	sprintf(timestr, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	std::cout << timestr << std::endl;

	// ѩ���㷨������id
	SnowFlake autoId(1, 1);
	std::cout << autoId.nextId() << std::endl;
	auto a = autoId.nextId();
	char autoIdStr[25];
	sprintf(autoIdStr, "%llu", autoId.nextId());

	//��װ��Ӧ��������
	PurQuotNaiGuanDO data;

	data.setId(autoIdStr);
	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());

	data.setSrcBillId(dto.getSrcBillId());
	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());

	data.setIsTempSupplier(dto.getIsTempSupplier());
	data.setSupplierId(dto.getSupplierId());
	data.setTempSupplierName(dto.getTempSupplierName());
	data.setDeliveryMethod(dto.getDeliveryMethod());

	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryAddress(dto.getDeliveryAddress());
	data.setContact(dto.getContact());
	data.setPhone(dto.getPhone());

	data.setFax(dto.getFax());
	data.setEmail(dto.getEmail());
	data.setQty(dto.getQty());
	data.setAmt(dto.getAmt());

	std::string fileAddress = "group1" + dto.getAttachment();				//ƴ���ļ���ַ
	data.setAttachment(fileAddress);
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());
	data.setBillStage(dto.getBillStage());

	data.setApprover(dto.getApprover());
	data.setBpmi_instance_id(dto.getBpmi_instance_id());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	data.setSysOrdCode(dto.getSysOrdCode());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(timestr);
	data.setUpdateBy(dto.getUpdateBy());

	data.setUpdateTime(dto.getUpdateTime());
	data.setVersion(dto.getVersion());

	//���ڽ���DTO�е�list�����ݸ�DO�е�list
	list<PurQuotDetailDTO> Addlist;
	//��װ��Ӧ������ϸ����
	for (PurQuotDetailDTO i : dto.getDetail()) {
		// ѩ���㷨������id
		SnowFlake autoIdEntry(1, 1);
		auto a = autoIdEntry.nextId();
		char autoIdStrEntry[25];
		sprintf(autoIdStrEntry, "%llu", autoIdEntry.nextId());

		PurQuotDetailDTO Addone;
		Addone.setId(autoIdStrEntry);
		Addone.setMid("pur_quot");
		Addone.setBill_no(i.getBill_no());
		Addone.setEntry_no(i.getEntry_no());						//ǰ���Զ�����

		Addone.setSrc_bill_type(i.getSrc_bill_type());
		Addone.setSrc_bill_id(i.getSrc_bill_id());
		Addone.setSrc_entry_id(i.getSrc_entry_id());
		Addone.setSrc_no(i.getSrc_no());

		Addone.setMaterial_id(i.getMaterial_id());
		Addone.setUnit_id(i.getUnit_id());
		Addone.setQty(i.getQty());
		Addone.setTax_rate(i.getTax_rate());

		Addone.setPrice(i.getPrice());
		Addone.setDiscount_rate(i.getDiscount_rate());
		Addone.setAmt(i.getAmt());
		Addone.setRemark(i.getRemark());

		Addone.setCustom1(i.getCustom1());
		Addone.setCustom2(i.getCustom2());
		Addone.setVersion(i.getVersion());
		Addlist.push_back(Addone);
	}
	//��Addlist�еĶ������ݵ�DO�е�list
	data.setDetail(Addlist);
	PurQuotDAO dao;
	return dao.insert(data);
}

// �޸ı��ۣ���ModPurQuotDTO�е����ݷ���PurQuotDO��
bool PurQuotService::updateData(const ModPurQuotDTO& dto, const PayloadDTO& payload)
{
	//����ʱ��
	time_t t;					//��t����Ϊʱ�����
	struct tm* p;				//struct tm��һ���ṹ�壬����һ���ṹ��ָ��
	time(&t);
	p = localtime(&t);			//��õ��ص�ʱ��
	char timestr[30];
	sprintf(timestr, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	std::cout << timestr << endl;

	//��װ��Ӧ��������
	PurQuotNaiGuanDO data;
	data.setId(dto.getId());						//�޸ĺ�id�޹�
	data.setBillNo(dto.getBillNo());
	data.setBillDate(dto.getBillDate());
	data.setSrcBillType(dto.getSrcBillType());

	data.setSrcBillId(dto.getSrcBillId());
	data.setSrcNo(dto.getSrcNo());
	data.setSubject(dto.getSubject());
	data.setIsRubric(dto.getIsRubric());

	data.setIsTempSupplier(dto.getIsTempSupplier());
	data.setSupplierId(dto.getSupplierId());
	data.setTempSupplierName(dto.getTempSupplierName());
	data.setDeliveryMethod(dto.getDeliveryMethod());

	data.setDeliveryDate(dto.getDeliveryDate());
	data.setDeliveryAddress(dto.getDeliveryAddress());
	data.setContact(dto.getContact());
	data.setPhone(dto.getPhone());

	data.setFax(dto.getFax());
	data.setEmail(dto.getEmail());
	data.setQty(dto.getQty());
	data.setAmt(dto.getAmt());

	data.setAttachment(dto.getAttachment());
	data.setRemark(dto.getRemark());
	data.setIsAuto(dto.getIsAuto());
	data.setBillStage(dto.getBillStage());

	data.setApprover(dto.getApprover());
	data.setBpmi_instance_id(dto.getBpmi_instance_id());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setApprovalRemark(dto.getApprovalRemark());

	data.setIsEffective(dto.getIsEffective());
	data.setEffectiveTime(dto.getEffectiveTime());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	data.setSysOrdCode(dto.getSysOrdCode());
	//data.setCreateBy(dto.getCreateBy());						//�޸ĵ��ݣ�����Ҫ�漰�����˺ʹ���ʱ��
	//data.setCreateTime(dto.getCreateTime());
	data.setUpdateBy(payload.getUsername());

	data.setUpdateTime(timestr);
	data.setVersion(dto.getVersion());

	//���ڽ���DTO�е�list�����ݸ�DO�е�list
	list<PurQuotDetailDTO> Addlist;
	//��װ��Ӧ������ϸ����
	for (PurQuotDetailDTO i : dto.getDetail()) {
		// ѩ���㷨������id
		SnowFlake autoIdEntry(1, 1);
		auto a = autoIdEntry.nextId();
		char autoIdStrEntry[25];
		sprintf(autoIdStrEntry, "%llu", autoIdEntry.nextId());

		PurQuotDetailDTO Addone;
		Addone.setId(autoIdStrEntry);
		Addone.setMid("pur_quot");
		Addone.setBill_no(i.getBill_no());
		Addone.setEntry_no(i.getEntry_no());

		Addone.setSrc_bill_type(i.getSrc_bill_type());
		Addone.setSrc_bill_id(i.getSrc_bill_id());
		Addone.setSrc_entry_id(i.getSrc_entry_id());
		Addone.setSrc_no(i.getSrc_no());

		Addone.setMaterial_id(i.getMaterial_id());
		Addone.setUnit_id(i.getUnit_id());
		Addone.setQty(i.getQty());
		Addone.setTax_rate(i.getTax_rate());

		Addone.setPrice(i.getPrice());
		Addone.setDiscount_rate(i.getDiscount_rate());
		Addone.setAmt(i.getAmt());
		Addone.setRemark(i.getRemark());

		Addone.setCustom1(i.getCustom1());
		Addone.setCustom2(i.getCustom2());
		Addone.setVersion(i.getVersion());
		Addlist.push_back(Addone);
	}
	//��Addlist�еĶ������ݵ�DO�е�list
	data.setDetail(Addlist);
	PurQuotDAO dao;
	return dao.update(data) == 1;
}

// ͨ��bill_noɾ�������Լ���Ӧ����ϸ����DelPurQuotDTO�е�bill_no�Ž�PurQuotDO��
bool PurQuotService::removeData(const DelPurQuotDTO& dto)
{
	PurQuotNaiGuanDO data;
	data.setBillNo(dto.getBillNo());
	PurQuotDAO dao;
	return dao.deleteByBillNo(data) == 1;
}

// �޸ı���״̬����PurQuotModBillStatusDTO�е����ݷŽ�PurQuotDO��
bool PurQuotService::UpdateDataBillStatus(const PurQuotModBillStatusDTO& dto)
{
	PurQuotNaiGuanDO data;
	data.setIsEffective(dto.getIsEffective());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());
	data.setApprovalResultType(dto.getApprovalResultType());
	data.setBillStage(dto.getBillStage());
	data.setBillNo(dto.getBillNo());
	data.setApprover(dto.getApprover());
	data.setApprovalRemark(dto.getApprovalRemark());
	data.setEffectiveTime(dto.getEffectiveTime());
	PurQuotDAO dao;
	return dao.updateBillStatus(data) == 1;

}
