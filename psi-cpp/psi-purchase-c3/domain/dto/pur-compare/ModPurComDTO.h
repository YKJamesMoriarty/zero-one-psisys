#pragma once
#ifndef _MOD_PUR_COM_DTO_H_
#define _MOD_PUR_COM_DTO_H_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
class ModPurComDTO : public FileDTO
{
	// ����id
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// Դ��ID
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);

	// Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// subject
	CC_SYNTHESIZE(string, subject, Subject);
	// �Ƿ����
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// ��ѡ���۵�ids
	CC_SYNTHESIZE(string, candidateQuotIds, CandidateQuotIds);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);

	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ����ʱ��
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);

	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// �����
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	// �����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	// �������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);

	// �Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// �ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// ��������
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);

	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// �汾
	CC_SYNTHESIZE(int, version, Version);

	//��ϸ
	CC_SYNTHESIZE(list<PurComDetailDTO>, detail, Detail);
public:
	// ��JSONת������
	friend void from_json(const json& j, ModPurComDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);

		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_I(j, t, isRubric);
		BIND_FROM_TO_NORMAL(j, t, candidateQuotIds);
		BIND_FROM_TO_NORMAL(j, t, paymentMethod);

		BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
		BIND_FROM_TO_NORMAL(j, t, deliveryTime);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_I(j, t, isAuto);

		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, bpmiInstanceId);
		BIND_FROM_TO_NORMAL(j, t, approvalResultType);
		BIND_FROM_TO_NORMAL(j, t, approvalRemark);

		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_NORMAL(j, t, effectiveTime);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_NORMAL(j, t, sysOrgCode);

		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);
		BIND_FROM_TO_I(j, t, version);

		BIND_FROM_TO_OBJ(j, t, detail, list<PurComDetailDTO>);

	}
};


#endif 

