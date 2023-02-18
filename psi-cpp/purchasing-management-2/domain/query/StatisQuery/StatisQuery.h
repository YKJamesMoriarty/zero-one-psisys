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
#ifndef __STATIS_QUERY__
#define __STATIS_QUERY__

/**
* �ɹ���������Query����ģ��
*/
class StatisQuery : public BaseQuery
{
	CC_SYNTHESIZE(uint16_t, year, Year); // ���
	CC_SYNTHESIZE(uint16_t, month, Month); // �·�
public:
	// ��JSONת������
	friend void from_json(const json& j, StatisQuery& sq)
	{
		from_json(j, static_cast<BaseQuery&>(sq));
		BIND_FROM_TO_UL(j, sq, year);
		BIND_FROM_TO_UL(j, sq, month);
	}
};

/**
* �ɹ���������-����/ҵ��Ա/��Ӧ��/����Query����ģ��
*/
class StatisByDeptQuery : public StatisQuery
{
	CC_SYNTHESIZE(std::string, dept, Dept); // ҵ����ID
public:
	// ��JSONת������
	friend void from_json(const json& j, StatisByDeptQuery& bq)
	{
		from_json(j, static_cast<StatisQuery&>(bq));
		BIND_FROM_TO_NORMAL(j, bq, dept);
	}
};

class StatisByOperatorQuery : public StatisByDeptQuery
{
	CC_SYNTHESIZE(string, opName, OpName); // ҵ��Ա��
public:
	// ��JSONת������
	friend void from_json(const json& j, StatisByOperatorQuery& bq)
	{
		from_json(j, static_cast<StatisByDeptQuery&>(bq));
		BIND_FROM_TO_NORMAL(j, bq, opName);
	}
};

class StatisBySupplierQuery : public StatisQuery
{
	CC_SYNTHESIZE(uint64_t, supplier, Supplier); // ��Ӧ��ID
public:
	//// ��JSONת������
	friend void from_json(const json& j, StatisBySupplierQuery& bq)
	{
		from_json(j, static_cast<StatisQuery&>(bq));
		BIND_FROM_TO_ULL(j, bq, supplier);
	}
};

class StatisByMaterialQuery : public StatisQuery
{
	CC_SYNTHESIZE(uint64_t, material, Material); // ����ID
	CC_SYNTHESIZE(string, materialCode, MaterialCode); // ���ϴ���
	CC_SYNTHESIZE(string, materialName, MaterialName); // ������
public:
	// ��JSONת������
	friend void from_json(const json& j, StatisByMaterialQuery& bq)
	{
		from_json(j, static_cast<StatisQuery&>(bq));
		BIND_FROM_TO_ULL(j, bq, material);
		BIND_FROM_TO_NORMAL(j, bq, materialCode);
		BIND_FROM_TO_NORMAL(j, bq, materialName);
	}
};

#endif