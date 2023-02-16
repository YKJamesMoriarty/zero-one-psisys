#pragma once

#ifndef _PAYMENT_BILL_VO_
#define _PAYMENT_BILL_VO_

#include "../../GlobalInclude.h"

/*
��ѯ�����б�
*/
class PaymentBillVO {
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, billDate, Bill_date);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, Supplier_id)
	// ҵ����
	CC_SYNTHESIZE(string, opDept, Op_dept)
	// ҵ��Ա
	CC_SYNTHESIZE(string, operator,Operator)
	// Դ����
	CC_SYNTHESIZE(string,srcNo,SrcNo)
	// ������
	CC_SYNTHESIZE(double, amt, Amt)
	// �Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt)
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч			
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�			
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������			
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// �Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// ���ֵ���
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ��Чʱ��
	CC_SYNTHESIZE(int, effectiveTime, EffectiveTime);
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
	BIND_TO_JSON(PaymentBillVO, billNo, billDate, subject, supplierId, opDept,
		operator, srcNo, amt, paidAmt, billStage, isEffective, isClosed, isVoided,
		isAuto, isRubric, remark, effectiveTime,
		approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
};



/*
��ѯ�����б�
*/
class PaymentBillDetailQuery : public PaymentBillVO {
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	// �Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(PaymentBillDetailQuery, srcNo, amt, paidAmt, remark, custom1, custom2);
};

#endif