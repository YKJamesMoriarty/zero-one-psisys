#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023\02\25 14:33:32

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
#ifndef _PUR_COM_DETAIL_DTO_H_
#define _PUR_COM_DETAIL_DTO_H_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class PurComDetailDTO
{
	// ����id
	CC_SYNTHESIZE(string, id, Id);
	//����
	CC_SYNTHESIZE(string, mid, Mid);
	//���ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��¼��
	CC_SYNTHESIZE(int, entry_no, Entry_no);

	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcbillid
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);

	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//����
	CC_SYNTHESIZE(string, material_id, Material_id);			//���ݿ�ش�ֵ
	//������λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);					//���ݿ�ش�ֵ
	//����
	CC_SYNTHESIZE(double, qty, Qty);							//���ݿ�ش�ֵ
	//˰��%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);					//���ݿ�ش�ֵ

	//��˰����
	CC_SYNTHESIZE(double, price, Price);						//���ݿ�ش�ֵ
	//�ۿ���%
	CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	//��˰���
	CC_SYNTHESIZE(double, amt, Amt);							//���ݿ�ش�ֵ
	//����
	CC_SYNTHESIZE(int, ranking, Ranking);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
public:
	// ��JSONת������
	friend void from_json(const json& j, PurComDetailDTO& t)
	{
		//BIND_FROM_TO_NORMAL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, mid);
		BIND_FROM_TO_NORMAL(j, t, bill_no);

		BIND_FROM_TO_I(j, t, entry_no);

		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		BIND_FROM_TO_NORMAL(j, t, src_bill_id);
		BIND_FROM_TO_NORMAL(j, t, src_entry_id);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, material_id);
		BIND_FROM_TO_NORMAL(j, t, unit_id);

		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, tax_rate);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, discount_rate);
		BIND_FROM_TO_D(j, t, amt);

		BIND_FROM_TO_I(j, t, ranking);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);

		BIND_FROM_TO_I(j, t, version);
	}
};

#endif // !_PUR_COM_DETAIL_DTO_H_