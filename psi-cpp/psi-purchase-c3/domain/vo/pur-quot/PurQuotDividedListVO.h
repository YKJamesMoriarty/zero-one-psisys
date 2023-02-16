#ifndef __PUR_QUOT_DIVIDED_LIST_VO_
#define __PUR_QUOT_DIVIDED_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * ��Ӧ���۵���ѯ��ʾ����
 */
class PurQuotDividedListVO
{
	// ���
	CC_SYNTHESIZE(string, receiptNum, ReceiptNum);
	// ����
	CC_SYNTHESIZE(string, material, Material);
	//����ͺ�
	CC_SYNTHESIZE(string, specificationsModels, SpecificationsModels);
	//��λ
	CC_SYNTHESIZE(string, units, Units);
	//����
	CC_SYNTHESIZE(int, quantity, Quantity);
	//˰��
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//�ο�˰����
	CC_SYNTHESIZE(double, referenceTaxPrice, ReferenceTaxPrice);
	//�ο���˰����
	CC_SYNTHESIZE(double, referenceIncludTaxPrice, ReferenceIncludTaxPrice);
	//�ο���˰���
	CC_SYNTHESIZE(double, referenceIncludTaxAmount, referenceIncludTaxAmount);
	//��ע
	CC_SYNTHESIZE(string, comments, Comments);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotDividedListVO, receiptNum, material, specificationsModels,\
		units, quantity, taxRate, referenceTaxPrice, referenceIncludTaxPrice,\
		referenceIncludTaxAmount, comments, custom1, custom2);
	// ���ڲ�����
	PurQuotDividedListVO() {
		this->setReceiptNum("20");
		this->setMaterial("test Material");
	}
};
#endif 
