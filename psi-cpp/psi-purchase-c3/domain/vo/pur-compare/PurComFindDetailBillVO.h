#pragma once

#ifndef _PUR_COM_FIND_DETAIL_BILL_VO_
#define _PUR_COM_FIND_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
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
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
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

#endif 