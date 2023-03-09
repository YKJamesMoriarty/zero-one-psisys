#pragma once

/*
 @Author: akun
 @Date: 2023/02/26 22:11
*/

#ifndef _PUR_ORDER_DIVIDED_LIST_DO_H_
#define _PUR_ORDER_DIVIDED_LIST_DO_H_
#include "../../GlobalInclude.h"

/**
 * �ɹ�����--�ɹ����뵥��¼�б�VO����
 */
class PurOrderDividedListDO {
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, BillNo);
	//��¼��
	CC_SYNTHESIZE(int, entry_no, EntryNo);
	//����
	CC_SYNTHESIZE(string, material_id, MaterialId);
	//����ͺ�------û�ҵ�
	//��λ
	CC_SYNTHESIZE(string, unit_id, UnitId);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//�Ѷ�����
	CC_SYNTHESIZE(double, ordered_qty, OrderedQty);
	//˰��
	CC_SYNTHESIZE(double, tax_rate, TaxRate);
	//�ο���˰����
	CC_SYNTHESIZE(double, price, Price);
	//�ο���˰���
	CC_SYNTHESIZE(double, amt, Amt);
	//���鹩Ӧ��
	CC_SYNTHESIZE(string, suggest_supplier_id, SuggestSupplierId);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	PurOrderDividedListDO() {
		bill_no = "";
		entry_no = -1;
		material_id = "";
		unit_id = "";
		qty = -1.0;
		ordered_qty = -1.0;
		tax_rate = -1.0;
		price = -1.0;
		amt = -1.0;
		suggest_supplier_id = "";
		remark = "";
		custom1 = "";
		custom2 = "";
	}
};

#endif // !_PUR_ORDER_VO_