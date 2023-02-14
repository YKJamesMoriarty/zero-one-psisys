#pragma once

#ifndef _PUR_COM_LIST_VO_
#define _PUR_COM_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * ���۵��б���ʾ����
 */
class PurComListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComListVO, billNo, billDate, subject, supplierId, \
		paymentMethod, deliveryTime, deliveryPlace, remark);
	//���ڲ���
	PurComListVO()
	{
		this->setBillNo("CGBJ100QZP");
		this->setSubject("���Խӿ�");
	}
};


#endif 

