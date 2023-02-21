#pragma once
#ifndef _Q_P_B_L_VO_
#define _Q_P_B_L_VO_
#include "../../GlobalInclude.h"
/*
* ���ظ�ǰ�˵�����
*/
class QueryPyrkBillListVO {
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
public:
	// ��JSONת������
	BIND_TO_JSON(QueryPyrkBillListVO, id, data, theme, resourceId, handing, stage, isEffective,
		isClosed, isVoided, remarks, isAuto, effectiveData, checkPerson, makePerson, makeData,
		department, modifyData, modifyPerson);
	
	//����
	/*QueryPyrkBillListVO() {
		id = "123",
			data = "2022221",
			theme = "asd",
			resourceId = "123",
			handing = "asd",
			stage = 1;
	}*/
};


#endif