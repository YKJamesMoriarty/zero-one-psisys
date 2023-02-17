#pragma once
#ifndef _PUR_QUOT_MOD_BILL_STATUS_DTO_H_
#define _PUR_QUOT_MOD_BILL_STATUS_DTO_H_
#include "../../GlobalInclude.h"


class PurQuotModBillStatusDTO
{
	//������һЩ�ֶΣ��Ҳ�ȷ���Ƿ���Ļ��õ������֮��д���룬���ֻ���Ҫ�����ֶΣ��������ȥ������Ҫ��ɾ����
	// ����id
	CC_SYNTHESIZE(long, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//���ݽ׶�
	CC_SYNTHESIZE(int, billStage, BillStage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//�����������
	CC_SYNTHESIZE(int, approvalResultType, ApprovalResultType);
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

public:
	//��JSONת������
	friend void from_json(const json& j, PurQuotModBillStatusDTO& t) {
		BIND_FROM_TO_L(j, t, id);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_I(j, t, approvalResultType);
		BIND_FROM_TO_I(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
	}
};

#endif // !_PUR_QUOT_MOD_BILL_STATUS_DTO_