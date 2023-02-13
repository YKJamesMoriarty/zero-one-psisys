#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:19:03

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
#ifndef _PUR_RER_FIND_Detail_BILL_VO_
#define _PUR_RER_FIND_Detail_BILL_VO_

#include "../../GlobalInclude.h"
#include "PurReqFindBillVO.h"
/*
��ѯ�����б���ʾ����
*/
//��ע:��ĺ�������ֶ�������Ҫ����
class PurReqFindDetailBillVO : public PurReqFindBillVO {
	//Դ����¼��
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	//����
	CC_SYNTHESIZE(string, material_id, Material_id);
	//�����ͺ�--δ�ҵ�
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	//��λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//����
	CC_SYNTHESIZE(string, qty, Qty);
	//�Ѷ�����
	CC_SYNTHESIZE(string, ordered_qty, Ordered_qty);
	//˰��
	CC_SYNTHESIZE(string, tax_rate, Tax_rate);
	//�ο���˰����
	CC_SYNTHESIZE(string, price, Price);
	//�ο���˰���
	CC_SYNTHESIZE(string, amt, Amt);
	//���鹩Ӧ��
	CC_SYNTHESIZE(string, suggest_supplier_id, Suggest_supplier_id);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(PurReqFindDetailBillVO, entry_no, material_id, entry_no, unit_id, qty, ordered_qty, tax_rate, price, amt, suggest_supplier_id, remark, custom1, custom2);
};
#endif // !







