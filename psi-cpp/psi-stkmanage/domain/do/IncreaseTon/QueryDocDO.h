#pragma once
#ifndef _QUERYDOC_DO_
#define __QUERYDOC_DO_
#include "../DoInclude.h"

/**
 * �Ƕ���⣬��ѯ������ϸ���ݿ�ʵ����
 */
class QueryDocDO
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
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
	//����ʵ��***
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//�Ƶ���*******
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
	CC_SYNTHESIZE(int,hasRp, HasRp);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, opDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operatoR, Operator);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	//�ֿ�
	CC_SYNTHESIZE(string,warehouseId, WarehouseId);
	//��λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	//�Ƕ�����
	CC_SYNTHESIZE(double, swellQty, SwellQty);
	//�����
	CC_SYNTHESIZE(double, inCost, InCost);
	//��ϸ����ע
	CC_SYNTHESIZE(string, remarK, RemarK);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//�������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);

	
	
	
public:
	QueryDocDO() {
		billNo = "";
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
		opDept = "";
		operatoR = "";
		handler = "";
		entryNo = 0;
		materialId = "";
		model = "";
		warehouseId = "";
		unitId = "";
		swellQty = 0;
		inCost = 0;
		remarK = "";
		approvalRemark = "";
		custom1 = "";
		custom2 = "";
		remark = "";
		approvalRemark = "";
		approvalResultType = "";
	}
};

#endif // __QUERYDOC_DO_