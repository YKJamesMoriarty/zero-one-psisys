#pragma once
#ifndef _PUR_COMPARE_VO_
#define _PUR_COMPARE_VO_

#include "../../GlobalInclude.h"

 // �����ȼ�
class AddPurComVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// �Ƶ�����
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// �Ƶ���
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// �Զ�����
	CC_SYNTHESIZE(int, autoBill, AutoBill);
	// ���ֵ���
	CC_SYNTHESIZE(int, redBill, RedBill);
	// Դ������
	CC_SYNTHESIZE(string, billType, BillType);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �ɹ�ѯ�۵������ݱ�ţ�
	CC_SYNTHESIZE(string, inquiryBill, InquiryBill);
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
	BIND_TO_JSON(AddPurComVO, billId, billDate, isEffect, isClose, isCancelled,
		effectDate, approver, makeBillDate, makeBillDept, makeBillPerson,
		updateDate, updatePerson, autoBill, redBill, billType, billTheme, billStatus,
		inquiryBill, payMethod, deliveryDate, deliveryPlace, remark);
};

// �޸ıȼ�
class ModPurComVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// �Ƶ�����
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// �Ƶ���
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// �Զ�����
	CC_SYNTHESIZE(int, autoBill, AutoBill);
	// ���ֵ���
	CC_SYNTHESIZE(int, redBill, RedBill);
	// Դ������
	CC_SYNTHESIZE(string, billType, BillType);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �ɹ�ѯ�۵������ݱ�ţ�
	CC_SYNTHESIZE(string, inquiryBill, InquiryBill);
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
	BIND_TO_JSON(ModPurComVO, billId, billDate, isEffect, isClose, isCancelled,
		effectDate, approver, makeBillDate, makeBillDept, makeBillPerson,
		updateDate, updatePerson, autoBill, redBill, billType, billTheme, billStatus,
		inquiryBill, payMethod, deliveryDate, deliveryPlace, remark);
};

//ɾ���ȼ�
class DelPurComVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	
public:
	// ��JSONת������
	BIND_TO_JSON(DelPurComVO, billId);
};

//�޸ĵ���״̬
class PurComModBillStatusVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);

public:
	// ��JSONת������
	BIND_TO_JSON(PurComModBillStatusVO, billId, isEffect, isClose, isCancelled, billStatus, updateDate, updatePerson);
};
#endif // !_PUR_COMPARE_VO_