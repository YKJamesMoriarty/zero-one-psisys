#pragma once
#ifndef _Q_P_D_B_VO_
#define _Q_P_D_B_VO_
#include "../../GlobalInclude.h"
#include"QueryPyrkBillListVO.h"
#include"DetailedMessage.h"
class QueryPyrkDetailedBillVO  {
	// ���ݱ��
	CC_SYNTHESIZE(string, id, Id);
	// ��������
	CC_SYNTHESIZE(string, data, Data);
	// ��������
	CC_SYNTHESIZE(string, theme, Theme);
	// Դ����
	CC_SYNTHESIZE(string, resourceId, ResourceId);
	// �̵㾭��
	CC_SYNTHESIZE(string, handing, Handing);
	// ���ݽ׶�
	CC_SYNTHESIZE(int, stage, Stage);
	// ����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	// �ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	// �Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveData, EffectiveData);
	// ������
	CC_SYNTHESIZE(string, checkPerson, CheckPerson);
	// �Ƶ���
	CC_SYNTHESIZE(string, makePerson, MakePerson);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, makeData, MakeData);
	// �Ƶ�����
	CC_SYNTHESIZE(string, department, Department);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, modifyData, ModifyData);
	// �޸���
	CC_SYNTHESIZE(string, modifyPerson, ModifyPerson);
	// ����ʵ��
	CC_SYNTHESIZE(string, checkInstanceId, CheckInstanceId);
	// ��Ӧ��
	CC_SYNTHESIZE(int, hasYF, HasYF);
	// ���ֵ���
	CC_SYNTHESIZE(int, redBill, RedBill);
	// Դ������
	CC_SYNTHESIZE(string, sourceBillType, SourceBillType);
	// ��ϸ
protected:
	DetailedMessage dm;
public:
	void setDm(DetailedMessage dm) {
		this->dm = dm;
	}
	DetailedMessage getDm() {
		return this->dm;
	}
	// Դ����¼��
	CC_SYNTHESIZE(string, sourceBillId, SourceBillId);
	// ����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	// �ֿ�
	CC_SYNTHESIZE(string, warehouse, Warehouse);
	// ��λ
	CC_SYNTHESIZE(string, unit, Unit);
	// �������
	CC_SYNTHESIZE(double, inNum, InNum);
	// �����
	CC_SYNTHESIZE(double, inMoney, InMoney);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	 //��JSONת������
	BIND_TO_JSON(QueryPyrkDetailedBillVO, id, data, theme, resourceId, handing, stage, isEffective,
		isClosed, isVoided, remarks, isAuto, effectiveData, checkPerson, makePerson, makeData,
		department, modifyData, modifyPerson, checkInstanceId, hasYF, redBill, sourceBillType,
		sourceBillId, materialId, model, warehouse, unit, inNum, inMoney, custom1, custom2);


	//����
	QueryPyrkDetailedBillVO() {
		id = "Pyrk_12312";
		data = "20201123";
		theme = "jintian";
		resourceId = "123";
		handing = "123";
		stage = 1;
		isEffective = 1;
		isClosed = 2;
		isVoided = 1;
	}
};








#endif