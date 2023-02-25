#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/18 16:25:02

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

#ifndef _PUR_COM_DETAILS_VO_
#define _PUR_COM_DETAILS_VO_

#include "../../GlobalInclude.h"


/**
 * �ȼ۵���ϸ��ʾ����
 */
class PurComDetailsVO
{
	// # ��¼���
	CC_SYNTHESIZE(int64_t, entryNo, EntryNo);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierName, SupplierName);
	// Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// ����
	CC_SYNTHESIZE(string, materialName, MaterialName);
	// ����ͺ�
	CC_SYNTHESIZE(string, specifications, Specifications);
	// ��λ
	CC_SYNTHESIZE(string, unitName, UnitName);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);
	// ˰��
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	// ��˰����
	CC_SYNTHESIZE(double, price, Price);
	// �ۿ���
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	// ��˰���
	CC_SYNTHESIZE(double, amt, Amt);
	// ����
	CC_SYNTHESIZE(int, ranking, Ranking);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComDetailsVO, entryNo, supplierName, srcNo, materialName, specifications, unitName, qty, taxRate, \
		price, discountRate, amt, ranking, remark, custom1, custom2);

	/*PurComDetailsVO()
	{
		this->setEntryNo("10");
		this->setSupplierId("1624286740595646466");
		this->setSrcNo("GYBJ-230212:10");
		this->setMaterialId("1584947805371310082");
		this->setUnitId("kg");
		this->setQty(5);
		this->setTaxRate(13);
		this->setPrice(10.6);
		this->setDiscountRate(100);
		this->setAmt(53);
		this->setRanking(12);
		this->setRemark("test");
	}*/
};

#endif 


