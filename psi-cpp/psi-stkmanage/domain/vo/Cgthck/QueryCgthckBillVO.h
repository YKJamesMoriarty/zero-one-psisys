#ifndef _QUERY_CGTHCK_BILL_VO_
#define _QUERY_CGTHCK_BILL_VO_

#include "../../GlobalInclude.h"

/**
* �ɹ��˻�����(����), ������ʾ����
*/
class QueryCgthckBillVO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// Դ����
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// ҵ����
	CC_SYNTHESIZE(std::string, optDept, OptDept);
	// ҵ��Ա
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// �����
	CC_SYNTHESIZE(double, inAmt, InAmt);
	// ������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// �ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	// �ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	// ��Ʊ����
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
	// ���⾭��
	CC_SYNTHESIZE(std::string, handler, Handler);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// �Ƿ�ر�
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
	// �Զ�����
	CC_SYNTHESIZE(bool, isAuto, IsAuto);
	// ���ֵ���
	CC_SYNTHESIZE(bool, isRubric, IsRubric);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// ��Чʱ��
	CC_SYNTHESIZE(std::string, effTime, EffTime);
	// ������
	CC_SYNTHESIZE(std::string, approver, Approver);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// �Ƶ���
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// �Ƶ�����
	CC_SYNTHESIZE(std::string, sysOrgCode, SysOrgCode);
	// �޸�ʱ��
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
public:
	BIND_TO_JSON
	(
		QueryCgthckBillVO, billNo, billDate, subject, srcNo, supplierId, optDept, srcOperator,
		inAmt, settleAmt, settledAmt, invoicedAmt, invoiceType, handler, billStage, isEff,
		isClosed, isVoided, isAuto, isRubric, remark, effTime, approver, createTime, createBy,
		sysOrgCode, updateTime, updateBy
	);
};

/**
*  �ɹ��˻�����(����), ������ϸ��ʾ����
*/
class QueryCgthckBillDetailVO : public QueryCgthckBillVO
{
	// ����ʵ��
	CC_SYNTHESIZE(std::string, bpmiInstanceId, BpmiInstanceId);
	// ��Ӧ��
	CC_SYNTHESIZE(bool, hasRp, HasRp);
	// ���Ƕ�
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// Դ������
	CC_SYNTHESIZE(std::string, srcBillType, SrcBillType);
	// ����
	CC_SYNTHESIZE(std::string, materialId, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(std::string, moddel, Moddel);
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
	// �������
	CC_SYNTHESIZE(double, inQty, InQty);
	// �ɹ�����
	CC_SYNTHESIZE(double, cost, Cost);
	// �Զ���1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
public:
	BIND_TO_JSON
	(
		QueryCgthckBillDetailVO, billNo, billDate, subject, srcNo, supplierId, optDept, srcOperator,
		inAmt, settleAmt, settledAmt, invoicedAmt, invoiceType, handler, billStage, isEff,
		isClosed, isVoided, isAuto, isRubric, remark, effTime, approver, createTime, createBy,
		sysOrgCode, updateTime, updateBy, bpmiInstanceId, hasRp, hasSwell, srcBillType,
		materialId, moddel, warehouseId, unitId, settleQty, taxRate, price, discountRate, tax,
		inQty, cost, custom1, custom2
	);
};

#endif // ! _QUERY_CGTHCK_BILL_VO_

