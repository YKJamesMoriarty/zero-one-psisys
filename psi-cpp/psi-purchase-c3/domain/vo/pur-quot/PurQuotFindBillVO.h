#ifndef _PUR_Quot_FIND_BILL_VO_
#define _PUR_Quot_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * ��Ӧ���۵���ѯ��ʾ����
 */
class PurQuotFindBillVO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billNu, BillNu);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// Դ����
	CC_SYNTHESIZE(string, srcNu, SrcNu);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier, Supplier);
	// ��ʱ��Ӧ������
	CC_SYNTHESIZE(string, tempSupplierName, TempSupplierName);
	// ��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// ����
	CC_SYNTHESIZE(string, count, Count);
	// ���
	CC_SYNTHESIZE(string, amount, Amount);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// ����Ч
	CC_SYNTHESIZE(string, isWork, IsWork);
	// �ѹر�
	CC_SYNTHESIZE(string, isClose, IsClose);
	// ������
	CC_SYNTHESIZE(string, isAbolish, IsAbolish);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, contactNum, ContactNum);
	// ����
	CC_SYNTHESIZE(string, faxes, Faxes);
	// �����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	// ��ע
	CC_SYNTHESIZE(string, comment, Comment);
	// �Զ�����
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	//���ֵ���
	CC_SYNTHESIZE(string, redBill, RedBill);
	//��Чʱ��
	CC_SYNTHESIZE(string, tmTakingEffect, TmTakingEffect);
	//������
	CC_SYNTHESIZE(string, approvalOfficer, ApprovalOfficer);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, billingTime, BillingTime);
	//�Ƶ���
	CC_SYNTHESIZE(string, billMaker, BillMaker);
	//�Ƶ�����
	CC_SYNTHESIZE(string, billMakerDepart, BillMakerDepart);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, changeTime, ChangeTime);
	//�޸���
	CC_SYNTHESIZE(string, changePerson, ChangePerson);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotFindBillVO, id,billNu, billDate, billTheme, srcNu, supplier, tempSupplierName,\
		deliveryDate,count, amount, billStage, isWork, isClose, isAbolish, paymentMethod, \
		deliveryPlace, contact, contactNum, faxes, email, comment, autoBill, redBill, \
		tmTakingEffect, approvalOfficer, billingTime, billMaker, billMakerDepart, changeTime, changePerson);
	// ���ڲ�����
	PurQuotFindBillVO() {
		this->setId(100);
		this->setBillNu("CGBJ100QZP");
		this->setBillTheme("test func");
	}
};


#endif 
