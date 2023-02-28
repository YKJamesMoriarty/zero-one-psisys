#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: akun,modify by QZP
 @Date: 2023/2/23 16:37:20
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
#ifndef _PUR_COM_EXPORT_QUERY_
#define _PUR_COM_EXPORT_QUERY_

#include "../PageQuery.h"

class PurComExportQuery {
	//ָ���ĵ��ݺ�
	CC_SYNTHESIZE(std::list<string>, billNo, BillNo);
public:
	// ��JSONת������
	friend void from_json(const json& j, PurComExportQuery& t) {
		BIND_FROM_TO_OBJ(j, t, billNo, std::list<string>);
	}
};

#endif // !
