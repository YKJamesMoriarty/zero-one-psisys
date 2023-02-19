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
#ifndef _Measuremnet_VO_
#define _Measurement_VO_

#include "../../GlobalInclude.h"

/**
 * ��ʾ����
 */
class MeasurementVO
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
	BIND_TO_JSON(MeasurementVO, name, sign, scale, enable, ctime, creater, rtime, riviser);
};

class MeasurementDetailVO
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, sign, Sign);
	// ����ϵ��
	CC_SYNTHESIZE(uint64_t, scale, Scale);
	// ����
	CC_SYNTHESIZE(string, enable, Enable);
public:
	// ��JSONת������
	BIND_TO_JSON(MeasurementDetailVO, name, sign, scale, enable);
};

class MeasurementActionInfoVO
{
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
	BIND_TO_JSON(MeasurementActionInfoVO, ctime, creater, rtime, riviser);
};

#endif // !_MEASUREMENT_VO_
