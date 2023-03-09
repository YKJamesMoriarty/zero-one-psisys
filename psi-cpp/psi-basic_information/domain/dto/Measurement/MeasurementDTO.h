#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MEASUREMENT_DTO_
#define _MEASUREMENT_DTO_

#include "../../GlobalInclude.h"
#include <string>
#include "../FileDTO.h"

/**
 * �������
 */
class MeasurementDTO : public FileDTO
{
	// pid
	CC_SYNTHESIZE(string, pid, Pid);
	//has_child
	CC_SYNTHESIZE(uint64_t, has_child, Has_child);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, symbol, Symbol);
	// ����ϵ��
	CC_SYNTHESIZE(double, factor, Factor);
	// ����
	CC_SYNTHESIZE(string, is_enabled, Is_enabled);
public:
	// ��JSONת������
	friend void from_json(const json& j, MeasurementDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, pid);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, symbol);
		BIND_FROM_TO_LD(j, t, factor);
		BIND_FROM_TO_NORMAL(j, t, is_enabled);
		BIND_FROM_TO_I(j, t, has_child);
	}
	MeasurementDTO() {
		is_enabled = "��";
		factor = -1.0;
		has_child = 0;
	}
};

/*
//�����ļ�DTO
class MeasurementFileDTO : public FileDTO
{
	// ��׼��λ
	CC_SYNTHESIZE(string, pname, Pname);
	// has_child
	CC_SYNTHESIZE(uint64_t, has_child, Has_child);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, symbol, Symbol);
	// ����ϵ��
	CC_SYNTHESIZE(double, factor, Factor);
	// ����
	CC_SYNTHESIZE(int, is_enabled, Is_enabled);
public:
	// ��JSONת������
	friend void from_json(const json& j, MeasurementFileDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, pname);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, symbol);
		BIND_FROM_TO_LD(j, t, factor);
		BIND_FROM_TO_I(j, t, has_child);
		BIND_FROM_TO_I(j, t, is_enabled);
	}
	MeasurementFileDTO() {
		is_enabled = -1;
		factor = -1.0;
		//has_child = 0;
	}
};
*/

//�޸�DTO
class MeasurementModifyDTO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, symbol, Symbol);
	// ����ϵ��
	CC_SYNTHESIZE(double, factor, Factor);
	// ����
	CC_SYNTHESIZE(string, is_enabled, Is_enabled);
public:
	// ��JSONת������
	friend void from_json(const json& j, MeasurementModifyDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, symbol);
		BIND_FROM_TO_LD(j, t, factor);
		BIND_FROM_TO_NORMAL(j, t, is_enabled);
	}
	MeasurementModifyDTO() {
		is_enabled = "��";
		factor = -1.0;
	}
};

//��ѯɾ��
class MeasurementDeleteDTO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
public:
	// ��JSONת������
	friend void from_json(const json& j, MeasurementDeleteDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, id);
	}

	BIND_TO_JSON(MeasurementDeleteDTO, id);
};

/*
//�����Ӽ��б�DTO
class MeasurementKidDTO
{
	// pname
	CC_SYNTHESIZE(string, pname, Pname);
	// id
	CC_SYNTHESIZE(string, id, Id);
	// has_child
	CC_SYNTHESIZE(string, has_child, Has_child);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, symbol, Symbol);
	// ����ϵ��
	CC_SYNTHESIZE(uint64_t, factor, Factor);
	// ����
	CC_SYNTHESIZE(string, is_enabled, Is_enabled);
public:
	// ��JSONת������
	friend void from_json(const json& j, MeasurementKidDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, pname);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, has_child);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, symbol);
		BIND_FROM_TO_I(j, t, factor);
		BIND_FROM_TO_NORMAL(j, t, is_enabled);
	}

	BIND_TO_JSON(MeasurementKidDTO, name, symbol, factor, is_enabled);
};
*/

/*
//�����ļ�DTO�б�
class MeasurementImportFileDTO : public FileDTO
{
protected:
	// �����ļ���Ϣ
	list<MeasurementFileDTO> import;
public:
	const list<MeasurementFileDTO>& getImport() const { return import; }
	void addImportItem(MeasurementFileDTO dtoObj) {
		import.push_back(dtoObj);
	};

	// ��JSONת������
	friend void from_json(const json& j, MeasurementImportFileDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, import);
	}
};
*/

#endif // !_MEASUREMENT_DTO_
