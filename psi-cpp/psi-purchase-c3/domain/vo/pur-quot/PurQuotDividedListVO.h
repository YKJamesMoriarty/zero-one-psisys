#pragma once
#ifndef _PUR_QUOT_DIVIDED_LIST_VO_H_
#define _PUR_QUOT_DIVIDED_LIST_VO_H_
#include "../../GlobalInclude.h"
class PurQuotDividedListVO
{
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//����
	CC_SYNTHESIZE(string, material_id, Material_id);
	//����ͺ�
	//��λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//����
	CC_SYNTHESIZE(string, qty, Qty);
	//˰��
	CC_SYNTHESIZE(string, tax_rate, Tax_rate);
	//��˰����
	CC_SYNTHESIZE(string, price, Price);
	//��˰���
	CC_SYNTHESIZE(string, amt, Amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotDividedListVO, bill_no, material_id, unit_id, qty, tax_rate, price, amt,remark, custom1, custom2);
};
#endif
