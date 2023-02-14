#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:48:00

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
#ifndef _UPDATE_DEPART_DTO_
#define _UPDATE_DEPART_DTO_

#include "../../../GlobalInclude.h"

/**
 * ʾ����Ӳ������ݴ������
 */
class AddDepartDTO
{
	// ����
	CC_SYNTHESIZE(string, departName, DepartName);
	// �绰
	CC_SYNTHESIZE(string, phone, Phone);
	// ����
	CC_SYNTHESIZE(string, mail, Mail);
public:
	// ��JSONת������
	friend void from_json(const json& j, AddDepartDTO& t); // NOLINT

};

#endif // !_UPDATE_DEPART_DTO_