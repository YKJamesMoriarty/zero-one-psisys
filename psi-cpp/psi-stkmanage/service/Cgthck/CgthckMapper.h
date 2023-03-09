#pragma once
#ifndef _CGTHCK_MAPPER_
#define _CGTHCK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
using CgthckDO = StkIoDO;
using CgthckEntryDO = StkIoEntryDO;
/**
* �ɹ��˻�������ϸ�ֶ�ƥ��ӳ����
*/
class CgthckEntryMapper : public Mapper<CgthckEntryDO>
{
public:
	CgthckEntryDO mapper(ResultSet* resultSet) const override
	{
		CgthckEntryDO data;
		data.setEntryNo(resultSet->getInt("entry_no"));
		data.setSrcNo(resultSet->getString("src_no"));
		data.setMaterialId(resultSet->getString("material_id"));
		data.setBatchNo(resultSet->getString("bill_no"));
		data.setWarehouseId(resultSet->getString("warehouse_id"));
		data.setUnitId(resultSet->getString("unit_id"));
		data.setSettleQty(resultSet->getDouble("settle_qty"));
		data.setTaxRate(resultSet->getDouble("tax_rate"));
		data.setPrice(resultSet->getDouble("price"));
		data.setDiscountRate(resultSet->getDouble("discount_rate"));
		data.setTax(resultSet->getDouble("tax"));
		data.setSettleAmt(resultSet->getDouble("settle_amt"));
		data.setQty(resultSet->getDouble("qty"));
		data.setCost(resultSet->getDouble("cost"));
		data.setInvoicedQty(resultSet->getDouble("invoiced_qty"));
		data.setInvoicedAmt(resultSet->getDouble("invoiced_amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		return data;
	}
};

/**
* �ɹ��˻������ֶε���ƥ��ӳ����
*/
class CgthckSheetMapper : public Mapper<CgthckDO>
{
public:
	CgthckDO mapper(ResultSet* resultSet) const override
	{
		CgthckDO data;
        data.setStockIoType(resultSet->getString("stock_io_type"));
        // �Ƿ�������
        data.setHasRp(resultSet->getInt("has_rp"));
        // �Ƿ����Ƕ�
        data.setHasSwell(resultSet->getInt("has_swell"));
        // ��Ӧ��
        data.setSupplierId(resultSet->getString("supplier_id"));
        // �ͻ�
        data.setCustomerId(resultSet->getString("customer_id"));
        // ��Ʊ����
        data.setInvoiceType(resultSet->getString("invoice_type"));
        // ҵ����
        data.setOpDept(resultSet->getString("op_dept"));
        // ҵ��Ա
        data.setOperator1(resultSet->getString("operator"));
        // ����⾭��
        data.setHandler(resultSet->getString("handler"));
        // �ɱ�
        data.setCost(resultSet->getDouble("cost"));
        // ������
        data.setSettleAmt(resultSet->getDouble("settle_amt"));
        // �ѽ�����
        data.setSettledAmt(resultSet->getDouble("settled_amt"));
        // �ѿ�Ʊ���
        data.setInvoicedAmt(resultSet->getDouble("invoiced_amt"));
        // �Ƿ���Ч
        data.setIsEffective(resultSet->getInt("is_effective"));
        // ����
        data.setAttachment(resultSet->getString("attachment"));
        // Դ��id
        data.setSrcBillId(resultSet->getString("src_bill_id"));
        // ��������
        data.setSubject(resultSet->getString("subject"));
        // ���ݽ׶�
        data.setBillStage(resultSet->getString("bill_stage"));
        // Դ����
        data.setSrcNo(resultSet->getString("src_no"));
        // �Ƿ��Զ�����
        data.setIsAuto(resultSet->getInt("is_auto"));
        // ��ע
        data.setRemark(resultSet->getString("remark"));
        // ����ʵ��id
        data.setBpmiInstanceId(resultSet->getString("bpmi_instance_id"));
        // ������
        data.setIsVoided(resultSet->getInt("is_voided"));
        // ���ݱ��
        data.setBillNo(resultSet->getString("bill_no"));
        // �Ƿ����
        data.setIsRubric(resultSet->getInt("is_rubric"));
        // Դ������
        data.setSrcBillType(resultSet->getString("src_bill_type"));
        // �Ƶ�ʱ��
        data.setCreateTime(resultSet->getString("create_time"));
        // ��Чʱ��
        data.setEffectiveTime(resultSet->getString("effective_time"));
        // ������
        data.setApprover(resultSet->getString("approver"));
        // �޸���
        data.setUpdateBy(resultSet->getString("update_by"));
        // �Ƶ�����
        data.setSysOrgCode(resultSet->getString("sys_org_code"));
        // �ѹر�
        data.setIsClosed(resultSet->getInt("is_closed"));
        // �����������
        data.setApprovalResultType(resultSet->getString("approval_result_type"));
        // ��������
        data.setBillDate(resultSet->getString("bill_date"));
        // �Ƶ���
        data.setCreateBy(resultSet->getString("create_by"));
        // �������
        data.setApprovalRemark(resultSet->getString("approval_remark"));
        return data;
	}
};

/**
* �ɹ��˻������ֶ���ϸ����ƥ��ӳ����
*/
class CgthckSheetEntryMapper : public Mapper<CgthckEntryDO>
{
public:
	CgthckEntryDO mapper(ResultSet* resultSet) const override
	{
		CgthckEntryDO data;
        // ����
        data.setMaterialId(resultSet->getString("material_id"));
        // ���κ�
        data.setBatchNo(resultSet->getString("batch_no"));
        // �ֿ�
        data.setWarehouseId(resultSet->getString("warehouse_id"));
        // ���뷽��
        data.setStockIoDirection(resultSet->getString("stock_io_direction"));
        // ��Ӧ��
        data.setSupplierId(resultSet->getString("supplier_id"));
        // ������λ
        data.setUnitId(resultSet->getString("unit_id"));
        // �Ƕ�����
        data.setSwellQty(resultSet->getDouble("swell_qty"));
        // ����
        data.setQty(resultSet->getDouble("qty"));
        // ����ɱ�����
        data.setExpense(resultSet->getDouble("expense"));
        // �ɱ�
        data.setCost(resultSet->getDouble("cost"));
        // ��������
        data.setSettleQty(resultSet->getDouble("settle_qty"));
        // ˰��%
        data.setTaxRate(resultSet->getDouble("tax_rate"));
        // ��˰����
        data.setPrice(resultSet->getDouble("price"));
        // �ۿ���%
        data.setDiscountRate(resultSet->getDouble("discount_rate"));
        // ˰��
        data.setTax(resultSet->getDouble("tax"));
        // ������
        data.setSettleAmt(resultSet->getDouble("settle_amt"));
        // �ѿ�Ʊ����
        data.setInvoicedQty(resultSet->getDouble("invoiced_qty"));
        // �ѿ�Ʊ���
        data.setInvoicedAmt(resultSet->getDouble("invoiced_amt"));
        // �Զ���1
        data.setCustom1(resultSet->getString("custom1")); 
        // Դ���¼��
        data.setSrcNo(resultSet->getString("src_no"));
        // ��¼��
        data.setEntryNo(resultSet->getInt("entry_no"));
        // �Զ���2
        data.setCustom2(resultSet->getString("custom2"));
        // Դ����¼id
        data.setSrcEntryId(resultSet->getString("src_entry_id"));
        // Դ������
        data.setSrcBillType(resultSet->getString("src_bill_type"));
        // ��ע
        data.setRemark(resultSet->getString("remark"));
        // ���ݱ��
        data.setBillNo(resultSet->getString("bill_no"));
        // Դ��id
        data.setSrcBillId(resultSet->getString("mid"));

        return data;
	}
};
#endif // !_CGTHCK_MAPPER_
