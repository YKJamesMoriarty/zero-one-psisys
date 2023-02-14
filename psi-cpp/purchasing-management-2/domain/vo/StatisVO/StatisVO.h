#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef __STATIS_VO__
#define __STATIS_VO__

#include "../../GlobalInclude.h"

/**
* �ɹ�����ִ�����VO����ģ��
*/
class StatisVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(int, quantity, Quantity); // �ɹ�����
	CC_SYNTHESIZE(double, price, Price); // �ɹ����
	CC_SYNTHESIZE(double, inPost, InCost); // �����
	CC_SYNTHESIZE(int, inQty, InQty); // �������
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // ������
	CC_SYNTHESIZE(int, settleQty, SettleQty); // ��������
	CC_SYNTHESIZE(uint64_t, supplier, Supplier); // ��Ӧ��ID
	CC_SYNTHESIZE(std::string, supName, SupName); // ��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, dept, Dept); // ҵ����ID
	CC_SYNTHESIZE(std::string, deptName, DeptName); // ҵ������
	CC_SYNTHESIZE(uint64_t, op, Op); // ҵ��ԱID
	CC_SYNTHESIZE(std::string, opName, OpName); // ҵ��Ա��
	CC_SYNTHESIZE(std::string, billNo, BillNo); // ���ݱ��
	CC_SYNTHESIZE(std::string, billDate, BillDate); // ��������
	CC_SYNTHESIZE(bool, exeEnd, ExeEnd); // ִ�н���
	CC_SYNTHESIZE(std::string, exeEndText, ExeEndText); // ִ�н�������
	CC_SYNTHESIZE(double, invoidced, Invoidced); // �ѽ�����
public:
	// ��JSONת������
	BIND_TO_JSON(StatisVO, id, quantity, price, inPost, inQty, settlePrice, settleQty, supplier, supName, dept, deptName, op, opName, billNo, billDate, exeEnd, exeEndText, invoidced);
};

#endif