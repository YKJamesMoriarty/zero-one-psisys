#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 //
 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _STKIOENTRY_DO_
#define _STKIOENTRY_DO_
#include "../DoInclude.h"

/**
 * stk_io_entry���ݿ�ʵ����
 */
class StkIoEntryDO
{
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//����
	CC_SYNTHESIZE(string, mid, Mid);
	//���ݺ�
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��¼��
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//Դ�����ͣ��ɹ�������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ��id���ɹ�������
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����¼id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//Դ����¼��
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//����
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//���κ�
	CC_SYNTHESIZE(string, batchNo, BatchNo);
	//�ֿ�
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//���뷽��
	CC_SYNTHESIZE(string, stockIoDirection, StockIoDirection);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//������λ
	CC_SYNTHESIZE(string, unitId, UnitId);
	//�Ƕ�����+/-
	CC_SYNTHESIZE(double, swellQty, SwellQty);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//������óɱ�
	CC_SYNTHESIZE(double, expense, Expense);
	//�ɱ�
	CC_SYNTHESIZE(double, cost, Cost);
	//��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//˰��%
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//��˰����
	CC_SYNTHESIZE(double, price, Price);
	//�ۿ���
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//˰��
	CC_SYNTHESIZE(double, tax, Tax);
	//�������˰�ϼƣ�
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//�ѿ�Ʊ����
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(string, version, Version);



public:
	StkIoEntryDO()
	{
		id = "";
		mid = "";
		billNo = "";
		entryNo = -1;
		srcBillType = "";
		srcBillId = "";
		srcEntryId = "";
		srcNo = "";
		materialId = "";
		batchNo = "";
		warehouseId = "";
		stockIoDirection = "";
		supplierId = "";
		unitId = "";
		swellQty = -1;
		qty = -1;
		expense = -1;
		cost = -1;
		settleQty = -1;
		taxRate = -1;
		price = -1;
		discountRate = -1;
		tax = -1;
		settleAmt = -1;
		invoicedQty = -1;
		invoicedAmt = -1;
		remark = "";
		custom1 = "";
		custom2 = "";
		version = "";



	}




};

#endif // !_STKIOENTRY_DO_
