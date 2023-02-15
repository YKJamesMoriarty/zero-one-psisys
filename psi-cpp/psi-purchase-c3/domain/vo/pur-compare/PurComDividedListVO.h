#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:55:35

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

#ifndef _PUR_COM_DIVIDE_LIST_VO_
#define _PUR_COM_DIVIDE_LIST_VO_

#include "../../GlobalInclude.h"


/**
 * ���۵���¼�б���ʾ����
 */
class PurComDividedListVO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// # ��¼���
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	// ����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// ����ͺ�
	CC_SYNTHESIZE(string, specifications, Specifications);
	// ��λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);
	// ˰��
	CC_SYNTHESIZE(uint64_t, taxRate, TaxRate);
	// ��˰�۸�
	CC_SYNTHESIZE(double, price, Price);
	// �ۿ���
	CC_SYNTHESIZE(uint64_t, discountRate, DiscountRate);
	// ��˰���
	CC_SYNTHESIZE(double, amt, Amt);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComDividedListVO, billNo, materialId, specifications, unitId, qty, taxRate, \
		price, discountRate, amt, remark, custom1, custom2);
	PurComDividedListVO()
	{
		this->setBillNo("CGBJ100QZP");
		this->setSrcEntryId("214");
		this->setRemark("����");
	}
};

#endif 


