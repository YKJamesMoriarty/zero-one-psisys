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
#ifndef _Measurement_DTO_
#define _Measurement_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * �������
 */
class MeasurementDTO : public FileDTO
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, sign, Sign);
	// ����ϵ��
	CC_SYNTHESIZE(uint64_t, scale, Scale);
	// ����
	CC_SYNTHESIZE(string, enable, Enable);
	// ����ʱ��
	CC_SYNTHESIZE(string, ctime, Ctime);
	// ������
	CC_SYNTHESIZE(string, creater, Creater);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, rtime, Rtime);
	// �޸���
	CC_SYNTHESIZE(string, riviser, Riviser);
public:
	// ��JSONת������
	friend void from_json(const json& j, MeasurementDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, sign);
		BIND_FROM_TO_I(j, t, scale);
		BIND_FROM_TO_NORMAL(j, t, enable);
		BIND_FROM_TO_NORMAL(j, t, ctime);
		BIND_FROM_TO_NORMAL(j, t, creater);
		BIND_FROM_TO_NORMAL(j, t, rtime);
		BIND_FROM_TO_NORMAL(j, t, riviser);
	}

	BIND_TO_JSON(MeasurementDTO, name, sign, scale, enable, ctime, creater, rtime, riviser);
};

class MeasurementQueryDelete
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	friend void from_json(const json& j, MeasurementQueryDelete& t)
	{
		BIND_FROM_TO_NORMAL(j, t, name);
	}

	BIND_TO_JSON(MeasurementQueryDelete, name);
};

#endif // !_Measurement_DTO_
