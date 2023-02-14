#pragma once
#pragma once
#ifndef _QUERYDOCLIST_DO_
#define _QUERYDOCLIST_DO_
#include "../DoInclude.h"

/**
 * �Ƕ���⣬��ѯ������ϸ���ݿ�ʵ����
 */
class QueryDocListDO
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, opDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operatoR, Operator);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//��ע
	CC_SYNTHESIZE(int,isAuto, IsAuto);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//������ 
	CC_SYNTHESIZE(string, approver, Approver);
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

public:
	QueryDocListDO() {
		billNo = "";
		billDate = "";
		opDept = "";
		operatoR = "";
		billStage = "";
		isEffective = -1;
		isClosed = 1;
		isVoided = -1;
		remark = "";
		isAuto = -1;
		effectiveTime = "";
		approver = "";
		createBy = "";
		createTime = "";
		sysOrgCode = "";
		updateTime = "";
		updateBy = "";


	}
};

#endif // __QUERYDOC_DO_
