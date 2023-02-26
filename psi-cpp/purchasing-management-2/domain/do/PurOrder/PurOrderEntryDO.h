#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2022/21/22 20:30:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef __PURORDERENTRYDO_H__
#define __PURORDERENTRYDO_H__
#include "../DoInclude.h"

/**
* �ɹ�������ϸ��DO����ģ��
*/
class PurOrderEntryDO
{
private:
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//����
	CC_SYNTHESIZE(string, mid, Mid);
	//���ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��¼��
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcBillId
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);
	//����
	CC_SYNTHESIZE(string, material_id, Material_id);
	//������λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//˰��%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	//��˰����
	CC_SYNTHESIZE(double, price, Price);
	//�ۿ���%
	CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	//˰��
	CC_SYNTHESIZE(double, tax, Tax);
	//��˰���
	CC_SYNTHESIZE(double, amt, Amt);
	//���������
	CC_SYNTHESIZE(double, in_qty, In_qty);
	//�����ɱ�
	CC_SYNTHESIZE(double, in_cost, In_cost);
	//��������
	CC_SYNTHESIZE(double, settle_qty, Settle_qty);
	//������
	CC_SYNTHESIZE(double, settle_amt, Settle_amt);
	//�ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoiced_qty, Invoiced_qty);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoiced_amt, Invoiced_amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
	
	PurOrderEntryDO() {
		id = "";
		bill_no = "";
		entry_no = "";
		src_bill_type = "";
		src_bill_id = "";
		src_no = "";
		unit_id = "";
		qty = -1;
		amt = -1;
		remark = "";
		custom1 = "";
		custom2 = "";
		mid = "";
		discount_rate = -1;
		tax = -1;
		in_qty = -1;
		in_cost = -1;
		settle_qty = -1;
		settle_amt = -1;
		invoiced_qty = -1;
		invoiced_amt = -1;
	}
};

#endif
