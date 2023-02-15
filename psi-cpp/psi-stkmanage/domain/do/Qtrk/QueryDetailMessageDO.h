#pragma once
#ifndef _QueryDetailMessage_DO_
#define __QueryDetailMessage_DO_
#include "../DoInclude.h"

/**
 * ������⣬��ѯ������ϸ���ݿ�ʵ����
 */
class QueryDetailMessageDO
{
	//���ݱ��
	CC_SYNTHESIZE(string, id, Id);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//������ 
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//�Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//�Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ֵ���
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//��Ӧ��
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	
public:
	QueryDetailMessageDO() {
		id = "";
		billDate = "";
		billStage = "";
		isEffective = -1;
		isClosed = -1;
		isVoided = -1;
		effectiveTime = "";
		approver = "";
		bpmiInstanceId = "";
		createBy = "";
		createTime = "";
		sysOrgCode = "";
		updateTime = "";
		updateBy = "";
		isAuto = -1;
		isRubric = -1;
		hasRp = -1;
		subject = "";
		supplierId = "";
		handler = "";
	}
};

#endif // __QueryDetailMessage_DO_