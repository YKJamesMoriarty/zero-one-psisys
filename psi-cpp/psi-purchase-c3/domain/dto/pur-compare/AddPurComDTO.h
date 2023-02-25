#pragma once
#ifndef _ADD_PUR_COM_DTO_H_
#define _ADD_PUR_COM_DTO_H_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//�����ȼ�
// ���������д��޸ģ�����ȫ��string
// ��û����ϸ������
class AddPurComDTO :public FileDTO
{
	//// ����id
	//CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ����Ч
	CC_SYNTHESIZE(string, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(string, isClose, IsClose);
	// ������
	CC_SYNTHESIZE(string, isCancelled, IsCancelled);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	// �Ƶ�ʱ��
	//CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// �Ƶ�����
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// �Ƶ���
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// �Զ�����
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	// ���ֵ���
	CC_SYNTHESIZE(string, redBill, RedBill);
	// Դ������
	CC_SYNTHESIZE(string, billType, BillType);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �ɹ�ѯ�۵������ݱ�ţ�
	CC_SYNTHESIZE(string, inqueryBill, InqueryBill);
	// ���ʽ
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	// ��JSONת������
	friend void from_json(const json& j, AddPurComDTO& t) {
		//BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, billId);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, isEffect);
		BIND_FROM_TO_NORMAL(j, t, isClose);
		BIND_FROM_TO_NORMAL(j, t, isCancelled);
		BIND_FROM_TO_NORMAL(j, t, effectDate);
		BIND_FROM_TO_NORMAL(j, t, approver);
		//BIND_FROM_TO_NORMAL(j, t, makeBillDate);
		BIND_FROM_TO_NORMAL(j, t, makeBillDept);
		BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
		BIND_FROM_TO_NORMAL(j, t, updateDate);
		BIND_FROM_TO_NORMAL(j, t, updatePerson);
		BIND_FROM_TO_NORMAL(j, t, autoBill);
		BIND_FROM_TO_NORMAL(j, t, redBill);
		BIND_FROM_TO_NORMAL(j, t, billType);
		BIND_FROM_TO_NORMAL(j, t, billTheme);
		BIND_FROM_TO_NORMAL(j, t, billStatus);
		BIND_FROM_TO_NORMAL(j, t, inqueryBill);
		BIND_FROM_TO_NORMAL(j, t, payMethod);
		BIND_FROM_TO_NORMAL(j, t, deliveryDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
		BIND_FROM_TO_NORMAL(j, t, remark);
		
	}
};

#endif // !_ADD_PUR_COM_DTO_

