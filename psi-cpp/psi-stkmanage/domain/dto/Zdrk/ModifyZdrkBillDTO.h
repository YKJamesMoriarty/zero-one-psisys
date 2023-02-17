#pragma once
#ifndef _MODIFYZDRKBILL_DTO_
#define _MODIFYZDRKBILL_DTO_

#include "../../GlobalInclude.h"

/**
 * ���ӵ��ݴ������
 */
class ModifyZdrkBillDTO
{
	//����
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);//�Զ�����
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);

	//ѡ��############
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operatoR, Operator);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//��ϸ*********
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//�����
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
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);

	//������######################
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
	CC_SYNTHESIZE(int, hasRp, HasRp);

public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyZdrkBillDTO& t); // NOLINT
	BIND_TO_JSON(ModifyZdrkBillDTO, billNo, billDate, subject, opDept, operatoR, handler, entryNo, materialId, model, warehouseId, unitId, swellQty, inCost, remarK, custom1, custom2, remark, attachment, billStage, isEffective, isClosed, isVoided, effectiveTime, approver, bpmiInstanceId, createBy, createTime, sysOrgCode, updateTime, updateTime, updateBy, isAuto, isRubric, hasRp);
};

#endif // !_DOC_DTO_
