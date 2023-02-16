#include "stdafx.h"
#ifndef __PurQuotFindDetailBill_QUERY_H__
#define __PurQuotFindDetailBill_QUERY_H__

#include "../PageQuery.h"

class PurQuotDividedListQuery : public PageQuery
{

	// ���
	CC_SYNTHESIZE(int, receiptNum, ReceiptNum);
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
public:
	friend void from_json(const json& j, PurQuotDividedListQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_I(j, t, receiptNum);
		BIND_FROM_TO_NORMAL(j, t, material);
		BIND_FROM_TO_NORMAL(j, t, specificationsModels);
		BIND_FROM_TO_NORMAL(j, t, units);
		BIND_FROM_TO_I(j, t, quantity);
		BIND_FROM_TO_D(j, t, taxRate);
		BIND_FROM_TO_D(j, t, referenceTaxPrice);
		BIND_FROM_TO_D(j, t, referenceIncludTaxPrice);
		BIND_FROM_TO_D(j, t, referenceIncludTaxAmount);
		BIND_FROM_TO_NORMAL(j, t, comments);

	}
};

#endif
