#pragma once

#ifndef _FIN_PAYMENT_BILL_REQ_DO_
#define _FIN_PAYMENT_BILL_REQ_DO_
#include "../DoInclude.h"

/*
*�����
*/
class FinPaymentBillReqDO
{
	//����id
	CC_SYNTHESIZE(string, id, Id);
	//���ݱ�� 
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�������� 
	CC_SYNTHESIZE(string, billDate, BillDate);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//�Ƿ����
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//��������
	CC_SYNTHESIZE(string, paymentType, PaymentType);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator, Operator);
	//������
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(double, paidAmt, PaidAmt);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//����id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//�����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//�Ƿ��ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��������
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�汾
	CC_SYNTHESIZE(int, version, Version);


public:
	FinPaymentBillReqDO() {

	}
};

#endif // _FIN_PAYMENT_BILL_REQ_DO_