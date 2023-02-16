#ifndef __PUR_QUOT_FIND_DETAIL_BILL_VO_
#define __PUR_QUOT_FIND_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * ��Ӧ���۵���ѯ��ʾ����
 */
class PurQuotFindDetailBillVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNu, BillNu);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//������
	CC_SYNTHESIZE(string, isMakeDone, IsMakeDone);
	// ����Ч
	CC_SYNTHESIZE(string, isWork, IsWork);
	// �ѹر�
	CC_SYNTHESIZE(string, isClose, IsClose);
	// ������
	CC_SYNTHESIZE(string, isAbolish, IsAbolish);
	//��Чʱ��
	CC_SYNTHESIZE(string, tmTakingEffect, TmTakingEffect);
	//������
	CC_SYNTHESIZE(string, approvalOfficer, ApprovalOfficer);
	//����ʵ��
	CC_SYNTHESIZE(string, approvalObject, ApprovalObject);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, billingTime, BillingTime);
	//�Ƶ�����
	CC_SYNTHESIZE(string, billMakerDepart, BillMakerDepart);
	//�Ƶ���
	CC_SYNTHESIZE(string, billMaker, BillMaker);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, changeTime, ChangeTime);
	//�޸���
	CC_SYNTHESIZE(string, changePerson, ChangePerson);
	// �Զ�����
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	//���ֵ���
	CC_SYNTHESIZE(string, redBill, RedBill);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	//�ɹ�ѯ�۵�
	CC_SYNTHESIZE(string, purchaseInquirySheet, PurchaseInquirySheet);
	//��ʱ��Ӧ�̣��Ƿ�
	CC_SYNTHESIZE(string,isTemsupplier, IsTemsupplier);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier, Supplier);
	// ��ʱ��Ӧ������
	CC_SYNTHESIZE(string, tempSupplierName, TempSupplierName);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
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
	//// Դ����
	//CC_SYNTHESIZE(string, srcNu, SrcNu);
	//// ����
	//CC_SYNTHESIZE(string, count, Count);
	//// ���
	//CC_SYNTHESIZE(string, amount, Amount);
	//// ���ݽ׶�
	//CC_SYNTHESIZE(string, billStage, BillStage);
	//
	//// ��ע
	//CC_SYNTHESIZE(string, comment, Comment);
	//
	
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotFindDetailBillVO, billNu, billDate, isMakeDone, isWork, isClose, isAbolish, tmTakingEffect, \
		approvalOfficer, approvalObject, billingTime, billMakerDepart, billMaker, changeTime, changePerson, autoBill, \
		redBill, srcBillType, billTheme, purchaseInquirySheet, isTemsupplier, supplier, tempSupplierName, paymentMethod, \
		deliveryDate, deliveryPlace, contact, contactNum, faxes, email);
	// ���ڲ�����
	PurQuotFindDetailBillVO() {
		this->setBillNu("CGBJ100QZP");
		this->setBillTheme("test func");
	}
};


#endif 
