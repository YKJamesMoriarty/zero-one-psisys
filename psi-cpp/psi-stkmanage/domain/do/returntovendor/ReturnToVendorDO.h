#ifndef _RETURN_TO_VENDOR_DO_
#define _RETURN_TO_VENDOR_DO_
#include "../DoInclude.h"

/**
* �ɹ��˻�����(����), ��ѯ�����б����ݿ�ʵ����
*/
class RtvDocDO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, bill_no, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, bill_date, BillDate);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, bill_stage, BillStage);
	// ����Ч
	CC_SYNTHESIZE(bool, is_eff, IsEff);
	// �ѹر�
	CC_SYNTHESIZE(bool, is_closed, IsClosed);
	// ������
	CC_SYNTHESIZE(bool, is_voided, IsVoided);
	// ��Чʱ��
	CC_SYNTHESIZE(std::string, eff_time, EffTime);
	// ������
	CC_SYNTHESIZE(std::string, approver, Approver);
	// ����ʵ��
	CC_SYNTHESIZE(std::string, bpmi_instance_id, BpmiInstanceId);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(std::string, create_time, CreateTime);
	// �Ƶ�����
	CC_SYNTHESIZE(std::string, sys_org_code, SysOrgCode);
	// �Ƶ���
	CC_SYNTHESIZE(std::string, create_by, CreateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(std::string, update_time, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(std::string, update_by, UpdateBy);
	// �Ƿ��Զ�����
	CC_SYNTHESIZE(bool, is_auto, IsAuto);
	// �Ƿ����
	CC_SYNTHESIZE(bool, is_rubric, IsRubric);
	// ��Ӧ��
	CC_SYNTHESIZE(bool, has_rp, HasRp);
	// ���Ƕ�
	CC_SYNTHESIZE(bool, has_swell, HasSwell);
	// Դ������
	CC_SYNTHESIZE(std::string, src_bill_type, SrcBillType);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// Դ��ҵ����Ա
	CC_SYNTHESIZE(std::string, src_operator, SrcOperator);
	// ҵ����
	CC_SYNTHESIZE(std::string, op_dept, OpDept);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplier_id, SupplierId);
	// �ɹ���ⵥ
	CC_SYNTHESIZE(std::string, src_no, SrcNo);
	// ��Ʊ����
	CC_SYNTHESIZE(std::string, invoice_type, InvoiceType);
	// ���⾭��
	CC_SYNTHESIZE(std::string, handler, Handler);
	// �ѽ�����
	CC_SYNTHESIZE(double, settled_amt, SettledAmt);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// ����
	CC_SYNTHESIZE(std::string, attachment, Attachment);
	// �������
	CC_SYNTHESIZE(std::string, apv_remark, ApvRemark);
	// �����������
	CC_SYNTHESIZE(std::string, apv_res_type, ApvResType);
};

/**
* �ɹ��˻�����(����), ��ѯ�����б���ϸ���ݿ�ʵ����
*/
class RtvEntryDO
{
	// Դ����¼��
	CC_SYNTHESIZE(std::string, src_no, SrcNo);
	// ����
	CC_SYNTHESIZE(std::string, material_id, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(std::string, model, Model);
	// �ֿ�
	CC_SYNTHESIZE(std::string, warehouse_id, WarehouseId);
	// ��λ
	CC_SYNTHESIZE(std::string, unit_id, UnitId);
	// ��������
	CC_SYNTHESIZE(double, settle_qty, SettleQty);
	// ˰��
	CC_SYNTHESIZE(double, tax_rate, TaxRate);
	// ��˰����
	CC_SYNTHESIZE(double, price, Price);
	// �ۿ���
	CC_SYNTHESIZE(double, discount_rate, DiscountRate);
	// ˰��
	CC_SYNTHESIZE(double, tax, Tax);
	// ������
	CC_SYNTHESIZE(double, settle_amt, SettleAmt);
	// �������
	CC_SYNTHESIZE(double, qty, Qty);
	// �ɹ�����
	CC_SYNTHESIZE(double, cost, Cost);
	// ����� (Ӧ���Ǽ���ֵ)
	// �ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoiced_qty, InvoicedQty);
	// �ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoiced_amt, InvoicedAmt);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
};

#endif // !_RETURN_TO_VENDOR_DO_