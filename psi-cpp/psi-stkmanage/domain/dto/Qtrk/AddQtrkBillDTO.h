#pragma once

#ifndef _AddQtrkBill_DTO_
#define _AddQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * ���������ⵥ�������
 */
class AddQtrkBillDTO
{
	//����
	//���ݱ��
	CC_SYNTHESIZE(string, bill, Bill);//�Զ�����
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);

	//ѡ��############
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier, Supplier);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//��ϸ*********
	//��¼��
	CC_SYNTHESIZE(uint64_t, entryNo, EntryNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//��λ
	CC_SYNTHESIZE(string, depart, Depart);
	
	//�������
	CC_SYNTHESIZE(uint64_t, inhouse, Inhouse);
	//��λ���
	CC_SYNTHESIZE(double, permoney, Permoney);
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

	////���ݽ׶�(������)
	//CC_SYNTHESIZE(string, billStage, BillStage);
	////����Ч
	//CC_SYNTHESIZE(int, isEffective, IsEffective);
	////�ѹر�
	//CC_SYNTHESIZE(int, isClosed, IsClosed);
	////������
	//CC_SYNTHESIZE(int, isVoided, IsVoided);
	////��Чʱ��
	//CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	////������ 
	//CC_SYNTHESIZE(string, approver, Approver);
	////����ʵ��***
	//CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	////�Ƶ���*******
	//CC_SYNTHESIZE(string, createBy, CreateBy);
	////�Ƶ�ʱ��
	//CC_SYNTHESIZE(string, createTime, CreateTime);
	////�Ƶ�����
	//CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	////�޸�ʱ��
	//CC_SYNTHESIZE(string, updateTime, UpdateTime);
	////�޸���
	//CC_SYNTHESIZE(string, updateBy, UpdateBy);
	////�Զ�����
	//CC_SYNTHESIZE(int, isAuto, IsAuto);
	////���ֵ���
	//CC_SYNTHESIZE(int, isRubric, IsRubric);
	////��Ӧ��
	//CC_SYNTHESIZE(int, hasRp, HasRp);



public:
	// ��JSONת������
	friend void from_json(const json& j, AddQtrkBillDTO& t); // NOLINT
	BIND_TO_JSON(AddQtrkBillDTO, bill, billDate, subject, supplier, handler, entryNo, materialId, model, warehouseId
		,depart, inhouse, permoney, inCost, remarK, remark, custom1, custom2, attachment);
};

#endif // !_AddQtrkBill_DTO_