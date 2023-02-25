#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _ENTRY_PUR_INQUIRY_VO_H_
#define _ENTRY_PUR_INQUIRY_VO_H_
#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� �ɹ�ѯ�۵���ϸ�б����ɹ����뵥��Ϣ
 */


//�ɹ�ѯ�۵���ϸ���ɹ����뵥
class EntryPurInquiryVO
{
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//Դ����¼��
	CC_SYNTHESIZE(string, src_entry_no, Src_entry_no);
	//����
	CC_SYNTHESIZE(string, material_id, Materialid);
	//����ͺţ������ӿڣ�

	//��λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//˰��%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	//�ο���˰����
	CC_SYNTHESIZE(double, price, Price);
	//�ο���˰���
	CC_SYNTHESIZE(double, amt, Amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(EntryPurInquiryVO, src_bill_type, src_entry_no, material_id, unit_id,
		qty, tax_rate, price, amt, remark, custom1, custom2);
};


#endif // !_ENTRY_PUR_INQUIRY_VO_
