#ifndef __PUR_QUOT_LIST_VO_
#define __PUR_QUOT_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * ��Ӧ���۵���ѯ��ʾ����
 */
class PurQuotListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, receiptId, ReceiptId);
	// �������� 
	CC_SYNTHESIZE(string, receiptTime, ReceiptTime);
	// ��������
	CC_SYNTHESIZE(string, receiptTheme, ReceiptTheme);
	// ��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	// ��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// �ѹر�
	CC_SYNTHESIZE(string, isClose, IsClose);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotListVO, receiptId, receiptTime, receiptTheme,contact, deliveryDate, deliveryPlace, isClose);
	// ���ڲ�����
	PurQuotListVO() {
		this->setReceiptId("CGBJ100QZP");
		this->setReceiptTheme("test func");
	}
};
#endif 