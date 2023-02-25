#pragma once
#include "stdafx.h"
#ifndef __PUR_REQ_ENTRY_DO_H__
#define __PUR_REQ_ENTRY_DO_H__

#include "../DoInclude.h"


class PurReqEntryDO
{
	// ID
	CC_SYNTHESIZE(string, entry_id, Entry_id);
	// ����
	CC_SYNTHESIZE(string, mid, Mid);
	// ���ݺ�
	CC_SYNTHESIZE(string, entry_bill_no, Entry_bill_no);
	// ��¼��
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	// Դ������
	CC_SYNTHESIZE(string, entry_src_bill_type, Entry_src_bill_type);
	// Դ��id
	CC_SYNTHESIZE(string, entry_src_bill_id, Entry_src_bill_id);
	// Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, src_entry_id);
	// Դ����¼��
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	// ����
	CC_SYNTHESIZE(string, material_id, Material_id);
	// ������λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	// ����
	CC_SYNTHESIZE(double, entry_qty, Entry_qty);
	// ˰��%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	// �ο���˰����
	CC_SYNTHESIZE(double, price, Price);	
	// �ο���˰���
	CC_SYNTHESIZE(double, entry_amt, Entry_Amt);
	// ���鹩Ӧ��
	CC_SYNTHESIZE(string, suggest_supplier_id, Suggest_supplier_id);
	// �Ѷ�������
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	// ��ע
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	// �汾
	CC_SYNTHESIZE(string, version, Version);

public:
	PurReqEntryDO()
	{



	}




};


#endif //__PUR_REQ_ENTRY_DO_H__