#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/25 12:02:32

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
#ifndef _PUR_COM_ENTRY_DO_H_
#define _PUR_COM_ENTRY_DO_H_
#include "../DoInclude.h"

/**
 * �ɹ��ȼ���ϸ��
 */
class PurComEntryDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, mid, Mid);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);

	// ��¼��
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	// Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);

	// Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	// Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);

	// ����
	CC_SYNTHESIZE(string, material_id, Material_id);
	// ������λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);

	// ˰��%
	CC_SYNTHESIZE(float, tax_rate, Tax_rate);
	// ��˰����
	CC_SYNTHESIZE(float, price, Price);
	// �ۿ���
	CC_SYNTHESIZE(float, discount_rate, Discount_rate);

	// ��˰���
	CC_SYNTHESIZE(float, amt, Amt);
	// ����
	CC_SYNTHESIZE(string, ranking, Ranking);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);


	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	// �汾
	CC_SYNTHESIZE(int, version, Version);

public:
	PurComEntryDO() {

	}
};
#endif // !_PUR_COM_ENTRY_DO_H_ 