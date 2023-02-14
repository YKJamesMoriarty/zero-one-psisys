#pragma once
#ifndef _PUR_REQ_ADAM_DTO_
#define _PUR_REQ_ADAM_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//���ǵ��޸ĺ���Ӳɹ������Ĳ����������Ժϲ�Ϊһ��DTO
//��Ӷ�����DTO(��������ϸ����),ͬʱ�����и������ݿ������,���Լ̳�FileDTO
class AddAndModifyPurReqDTO:FileDTO
{
	// ����id
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
	//�ɹ�����
	CC_SYNTHESIZE(string, purType, PurType);
	//������
	CC_SYNTHESIZE(string, requester, Requester);
	//����ʱ��
	CC_SYNTHESIZE(string, requestTime, RequestTime);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//�ο����
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѷ�����
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);
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
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
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
	//��������
	CC_SYNTHESIZE(string, sysOrdCode, SysOrdCode);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, updateTime);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
public:
	//��JSONת������
	friend void from_json(const json& j, AddAndModifyPurReqDTO& t);
};

//ɾ��������DTO ǰ��ֻ��Ҫ����һ�����ݱ�Ÿ��Ҽ��ɽ����޸�
class DeletePurDTO {
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	//��JSONת������
	friend void from_json(const json& j, DeletePurDTO& t);
};
//�޸Ķ���״̬��DTO ǰ����Ҫ����һ�����ݱ���Լ�״̬�޸���Ϣ
class PurReqModBillStatusDTO {
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
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
	friend void from_json(const json& j, PurReqModBillStatusDTO& t);
};
#endif // !_PUR_REQ_ADAM_DTO_