#pragma once

#ifndef _PUR_COMPARE_VO_
#define _PUR_COMPARE_VO_

#include "../../GlobalInclude.h"

/**
 * �ȼ۵��б���ʾ����
 */
class PurComFindBillVO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// ����Ч
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// �ѹر�
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ�����
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// ���ֵ���
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// �Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComFindBillVO, id, billNo, billDate, subject, srcNo, paymentMethod, deliveryTime, \
		billStage, isEffective, isClosed, isVoided, deliveryPlace, remark, isAuto, isRubric, \
		effectiveTime, approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
};

/**
 * ָ���ıȼ۵���ϸ��Ϣ��ʾ����
 */
class PurComFindDetailBillVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// ����Ч
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// �ѹر�
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// �Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �Զ�����
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// ���ֵ���
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// Դ������
	CC_SYNTHESIZE(string, srcBilType, SrcBillType);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// Դ����(�ɹ�ѯ�۵�)
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ����
	CC_SYNTHESIZE(std::list<std::string>, attachment, Attachment);
	// �������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	// �������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComFindDetailBillVO, billNo, billDate, billStage, isEffective, isClosed, isVoided, \
		effectiveTime, approver, bpmiInstanceId, createTime, sysOrgCode, createBy, updateTime, \
		updateBy, isAuto, isRubric, srcBillType, subject, srcNo, paymentMethod, deliveryTime, \
		deliveryPlace, remark, attachment, approvalRemark, approvalResultType);
};


/**
 * ���۵��б���ʾ����
 */
class PurComListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComListVO, billNo, billDate, subject, supplierId, \
		paymentMethod, deliveryTime, deliveryPlace, remark);
};

/**
 * ���۵���¼�б���ʾ����
 */
class PurComDividedListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// #
	// ����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(string, specifications, Specifications);
	// ��λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);
	// ˰��
	CC_SYNTHESIZE(uint64_t, taxRate, TaxRate);
	// ��˰�۸�
	CC_SYNTHESIZE(double, price, Price);
	// �ۿ���
	CC_SYNTHESIZE(uint64_t, discountRate, DiscountRate);
	// ��˰���
	CC_SYNTHESIZE(double, amt, Amt);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComListVO, billNo, materialId, specifications, unitId, qty, taxRate,\
		price, discountRate, amt, remark, custom1, custom2);
};
#endif 

