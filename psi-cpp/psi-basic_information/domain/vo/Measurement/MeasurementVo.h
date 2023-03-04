#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _MEASUREMNET_VO_
#define _MEASUREMENT_VO_

#include "../../GlobalInclude.h"
#include <string>

/**
 * ��ʾ����
 */
class MeasurementVO
{
	//����ID
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, symbol, Symbol);
	// ����ϵ��
	CC_SYNTHESIZE(double, factor, Factor);
	// ����
	CC_SYNTHESIZE(string, is_enabled, Is_enabled);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	// �޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
public:
	// ��JSONת������
	BIND_TO_JSON(MeasurementVO, id, name, symbol, factor, is_enabled, create_time, create_by, update_time, update_by);
};

#endif // !_MEASUREMENT_VO_
