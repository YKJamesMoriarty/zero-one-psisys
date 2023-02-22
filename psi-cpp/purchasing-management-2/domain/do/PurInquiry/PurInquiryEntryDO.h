#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: huilai
 @Date: 2023/02/20 16:48:09
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
#ifndef _PUR_INQUIRY_ENTRY_DO_H_
#define _PUR_INQUIRY_ENTRY_DO_H_
#include "../../GlobalInclude.h"


class PurInquiryEntryDO
{
	// ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(uint64_t, mid, Mid);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��¼��
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	// Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	// Դ����¼id
	CC_SYNTHESIZE(string, src_entry_no, Src_entry_no);
	// Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);
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
	// �ο���˰���
	CC_SYNTHESIZE(float, amt, Amt);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	// �汾
	CC_SYNTHESIZE(int, version, Version);

public:

	PurInquiryEntryDO(){

	}

};

#endif // !_PUR_INQUIRY_ENTRY_DO_H_