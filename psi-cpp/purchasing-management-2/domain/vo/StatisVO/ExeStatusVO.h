#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/18 10:00:00

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
#ifndef __EXESTATUS_VO__
#define __EXESTATUS_VO__

#include "../../GlobalInclude.h"
#include "../lib-common/include/CharsetConvertHepler.h"

/**
* �ɹ�����ִ�����VO����ģ��
*/
class ExeStatusVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(uint16_t, quantity, Quantity); // �ɹ�����
	CC_SYNTHESIZE(double, price, Price); // �ɹ����
	CC_SYNTHESIZE(double, incost, Incost); // �����
	CC_SYNTHESIZE(uint16_t, inQty, InQty); // �������
	CC_SYNTHESIZE(uint16_t, settleQty, SettleQty); // ��������
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // ������
	CC_SYNTHESIZE(double, settledPrice, SettledPrice); // �ѽ�����
	CC_SYNTHESIZE(double, invoiced, Invoiced); // �ѿ�Ʊ���
	CC_SYNTHESIZE(uint64_t, supplier, Supplier); // ��Ӧ��ID
	CC_SYNTHESIZE(string, supName, SupName); // ��Ӧ����
	CC_SYNTHESIZE(string, dept, Dept); // ҵ����ID
	CC_SYNTHESIZE(string, deptName, DeptName); // ҵ������
	CC_SYNTHESIZE(uint64_t, op, Op); // ҵ��ԱID
	CC_SYNTHESIZE(string, opName, OpName); // ҵ��Ա��
	CC_SYNTHESIZE(string, billNo, BillNo); // ���ݱ��
	CC_SYNTHESIZE(string, billDate, BillDate); // ��������
	CC_SYNTHESIZE(bool, exeEnd, ExeEnd); // ִ�н���
	CC_SYNTHESIZE(string, exeEndText, ExeEndText); // ִ�н�������
public:
	ExeStatusVO() : id(155149), quantity(2), price(996.00), incost(666.00), inQty(10), settlePrice(6.66), settledPrice(2.33), invoiced(4.55), supplier(114514), supName("Test"), dept("testDept"), deptName("department"), op(123456), opName("NO.1"), billNo("Bill-111000"), billDate("2023-02-14"), exeEnd(true), exeEndText(CharsetConvertHepler::ansiToUtf8("��")) {}
	// ��JSONת������
	BIND_TO_JSON(ExeStatusVO, id, quantity, price, incost, inQty, settlePrice, settledPrice, settleQty, invoiced, supplier, supName, dept, deptName, op, opName, billNo, billDate, exeEnd, exeEndText);
};

#endif