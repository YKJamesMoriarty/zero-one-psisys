#pragma once

#ifndef _QueryQtrkBillDetails_VO_
#define _QueryQtrkBillDetails_VO_

#include "../../GlobalInclude.h"

/**
 * ��ѯ�����б���ϸ��Ϣ��ʾ����
 */
class QueryQtrkBillDetailsVO
{
	//���ݱ��
	CC_SYNTHESIZE(string, id, Id);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч
	CC_SYNTHESIZE(uint64_t, isEffective, IsEffective);
	//�ѹر�
	CC_SYNTHESIZE(uint64_t, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(uint64_t, isVoided, IsVoided);
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
	CC_SYNTHESIZE(uint64_t, isAuto, IsAuto);
	//���ֵ���
	CC_SYNTHESIZE(uint64_t, isRubric, IsRubric);
	//��Ӧ��
	CC_SYNTHESIZE(uint64_t, hasRp, HasRp);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
public:
	QueryQtrkBillDetailsVO()
	{
		id = "12334";
		billDate = "2023 - 2 - 17";
		billStage = "ing";
		isEffective = 0;
		isClosed = 0;
		isVoided = 0;
		effectiveTime = "2023-2-17";
		approver = "aaaa";
		bpmiInstanceId = "";
		createBy = "gonverner";
		createTime = "2023-2-17";
		sysOrgCode = "research gorver";
		updateTime = "2023-2-17";
		updateBy = "wangwu";
		isAuto = 0;
		isRubric = 0;
		hasRp = 0;
		subject = "sgrg";
		supplierId = "wangwu";
		handler = "aafef";
	}
	// ��JSONת������
	friend void from_json(const json& j, QueryQtrkBillDetailsVO& t); // NOLINT
	BIND_TO_JSON(QueryQtrkBillDetailsVO, id, billDate, billStage, isEffective, isClosed, isVoided, effectiveTime, approver,
		bpmiInstanceId, createBy, createTime, sysOrgCode, updateTime, updateBy, isAuto, isRubric, hasRp, subject,
		supplierId, handler);

};

#endif // !_QueryQtrkBillDetails_VO_