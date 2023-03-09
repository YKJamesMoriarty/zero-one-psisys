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

#ifndef _MEASUREMENT_QUERY_
#define _MEASUREMENT_QUERY_

#include "../PageQuery.h"
#include <string>

/**
 * ��ҳ��ѯ����
 */
class MeasurementQuery : public PageQuery
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��from_json
	friend void from_json(const json& j, MeasurementQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
	}
};

//ָ�����㵥λ��ѯ����
class MeasurementAppQuery
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
public:
	// ��from_json
	friend void from_json(const json& j, MeasurementAppQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};

//ָ�����㵥λ�Ӽ��б��ѯ
class MeasurementKidQuery
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
public:
	// ��from_json
	friend void from_json(const json& j, MeasurementKidQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};

//�ļ������ѯ
class MeasurementFileQuery
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
public:
	// ��from_json
	friend void from_json(const json& j, MeasurementFileQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};

/*
//�����ļ���ѯ
class MeasurementExportFileQuery
{
protected:
	// �����ļ���Ϣ
	list<MeasurementFileQuery> import;
	MeasurementFileQuery query;
public:
	const list<MeasurementFileQuery>& getImport() const { return import; }
	void addImportItem(MeasurementFileQuery query) {
		import.push_back(query);
	};

	// ��JSONת������
	friend void from_json(const json& j, MeasurementExportFileQuery& t)
	{
		BIND_FROM_TO_OBJ(j, t, import.);
	}
};
*/

#endif // !_MEASUREMENT_QUERY_
