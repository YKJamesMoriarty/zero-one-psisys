#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/15 22:00:00

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
* �ɹ���������VO����ģ��
*/
class StatisVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(double, price, Price); // �ɹ����
	CC_SYNTHESIZE(double, incost, Incost); // �����
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // ������
	CC_SYNTHESIZE(double, settledPrice, SettledPrice); // �ѽ�����
	CC_SYNTHESIZE(double, unsettledPrice, UnsettledPrice); // δ������
	CC_SYNTHESIZE(uint16_t, year, Year); // ���
	CC_SYNTHESIZE(uint16_t, month, Month); // �·�
	CC_SYNTHESIZE(uint16_t, orders, Orders); // ��������
private:
	friend void to_json(json& j, const StatisVO& sv)
	{
		j = json{
			{"id", sv.id},
			{"price", sv.price},
			{"incost", sv.incost},
			{"settlePrice", sv.settlePrice},
			{"settledPrice", sv.settledPrice},
			{"unsettledPrice", sv.unsettledPrice},
			{"year", sv.year},
			{"month", sv.month},
			{"orders", sv.orders}
		};
	}
};

/**
* �ɹ���������-����/ҵ��Ա/��Ӧ��VO����ģ��
*/
class StatisByDeptVO : public StatisVO
{
	CC_SYNTHESIZE(std::string, dept, Dept); // ҵ����ID
	CC_SYNTHESIZE(std::string, deptName, DeptName); // ҵ������
private:
	friend void to_json(json& j, const StatisByDeptVO& sv)
	{
		to_json(j, static_cast<const StatisVO&>(sv));
		j = json{
			{"dept", sv.dept},
			{"deptName", sv.deptName},
		};
	}
};

class StatisByOperatorVO : public StatisByDeptVO
{
	CC_SYNTHESIZE(std::string, op, Op); // ҵ��ԱID
	CC_SYNTHESIZE(std::string, opName, OpName); // ҵ��Ա��
private:
	friend void to_json(json& j, const StatisByOperatorVO& sv)
	{
		to_json(j, static_cast<const StatisByDeptVO&>(sv));
		j = json{
			{"op", sv.op},
			{"opName", sv.opName},
		};
	}
};

class StatisBySupplierVO : public StatisVO
{
	CC_SYNTHESIZE(std::string, supplier, supplier); // ��Ӧ��ID
	CC_SYNTHESIZE(std::string, supName, SupName); // ��Ӧ����
private:
	friend void to_json(json& j, const StatisBySupplierVO& sv)
	{
		to_json(j, static_cast<const StatisVO&>(sv));
		j = json{
			{"supplier", sv.supplier},
			{"supName", sv.supName},
		};
	}
};

#endif // !__STATIS_VO__
