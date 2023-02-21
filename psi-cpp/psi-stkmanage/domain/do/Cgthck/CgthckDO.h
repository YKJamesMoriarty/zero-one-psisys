#ifndef _CGTHCK_DO_
#define _CGTHCK_DO_
#include "../DoInclude.h"

/**
* �ɹ��˻�����(����), ��ѯ�����б����ݿ�ʵ����
*/
class CgthckBillListDO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// ����Ч
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// �ѹر�
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
	// ��Чʱ��
	CC_SYNTHESIZE(std::string, effTime, EffTime);
	// ������
	CC_SYNTHESIZE(std::string, approver, Approver);
	// ����ʵ��
	CC_SYNTHESIZE(std::string, bpmiInstanceId, BpmiInstanceId);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// �Ƶ�����
	CC_SYNTHESIZE(std::string, sysOrgCode, SysOrgCode);
	// �Ƶ���
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	// �Ƿ��Զ�����
	CC_SYNTHESIZE(bool, isAuto, IsAuto);
	// �Ƿ����
	CC_SYNTHESIZE(bool, isRubric, IsRubric);
	// ��Ӧ��
	CC_SYNTHESIZE(bool, hasRp, HasRp);
	// ���Ƕ�
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// Դ������
	CC_SYNTHESIZE(std::string, srcBillType, SrcBillType);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// Դ��ҵ����Ա
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// ҵ����
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// �ɹ���ⵥ
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ��Ʊ����
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
	// ���⾭��
	CC_SYNTHESIZE(std::string, handler, Handler);
	// �ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// ����
	CC_SYNTHESIZE(std::string, attachment, Attachment);
	// �������
	CC_SYNTHESIZE(std::string, apvRemark, ApvRemark);
	// �����������
	CC_SYNTHESIZE(std::string, apvResType, ApvResType);
public:
	CgthckBillListDO()
	{
		billNo = "";
		billDate = "";
		billStage = "";
		isEff = true;
		isClosed = false;
		isVoided = false;
		isAuto = false;
		isRubric = true;
		hasRp = true;
		hasSwell = false;
	}
};

/**
* �ɹ��˻�����(����), ��ѯ�����б���ϸ���ݿ�ʵ����
*/
class CgthckBillDetailDO : public CgthckBillListDO
{
	// Դ����¼��
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ����
	CC_SYNTHESIZE(std::string, materialId, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(std::string, model, Model);
	// �ֿ�
	CC_SYNTHESIZE(std::string, warehouseId, WarehouseId);
	// ��λ
	CC_SYNTHESIZE(std::string, unitId, UnitId);
	// ��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	// ˰��
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	// ��˰����
	CC_SYNTHESIZE(double, price, Price);
	// �ۿ���
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	// ˰��
	CC_SYNTHESIZE(double, tax, Tax);
	// ������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// �������
	CC_SYNTHESIZE(double, qty, Qty);
	// �ɹ�����
	CC_SYNTHESIZE(double, cost, Cost);
	// ����� (Ӧ���Ǽ���ֵ)
	CC_SYNTHESIZE(double, inAmt, InAmt);
	// �ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	// �ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedQmt, InvoicedAmt);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
};

#endif // !_CGTHCK_DO_