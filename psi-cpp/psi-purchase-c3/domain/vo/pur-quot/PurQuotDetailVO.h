#pragma once
#ifndef _PUR_QUOT_DETAIL_VO_H_
#define _PUR_QUOT_DETAIL_VO_H_
#include "../../GlobalInclude.h"

//��ϸ��VO
class PurQuotDetailVO {
	//----��ϸ(pur-quot-entry���ֶ�)
		//Դ����¼��
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	//����
	CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
	//����ͺ�
	//��λ
	CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
	//����
	CC_SYNTHESIZE(string, entry_qty, Entry_qty);
	//˰��
	CC_SYNTHESIZE(string, entry_tax_rate, Entry_tax_rate);
	//��˰����
	CC_SYNTHESIZE(string, entry_price, Entry_price);
	//�ۿ���
	CC_SYNTHESIZE(string, entry_discount_rate, Entry_discount_rate);
	//��˰���
	CC_SYNTHESIZE(string, entry_amt, Entry_amt);
	//��ע
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	//�Զ���1
	CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotDetailVO, entry_src_no, entry_material_id, entry_unit_id, entry_qty, entry_tax_rate, entry_price, entry_discount_rate,
		entry_amt, entry_remark, entry_custom1, entry_custom2);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_

