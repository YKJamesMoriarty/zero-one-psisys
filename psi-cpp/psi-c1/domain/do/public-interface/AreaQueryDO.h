#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/11 17:51

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
#ifndef _AREADO_H_
#define _AREADO_H_
#include "../DoInclude.h"
#include "string"
class AreaQueryDO
{
	//����Ҫ��ѯ����������
	CC_SYNTHESIZE(std::string, areaname, AreaName);
	//��Ҫ��ѯ��Ͻ��������id
	CC_SYNTHESIZE(int, type, Type);
public:
	AreaQueryDO()
	{
		areaname = "";
		type = 0;
	}
	//���ڷ��������ѯ������������
	std::string getTypeStr() const
	{
		if (type == 1)return std::string("province");
		else if (type == 2)return std::string("city");
		else if (type == 3)return std::string("area");
		return "";
	}
	//���ڷ��ز�ѯ����������
	std::string getReturnTypeStr()const
	{
		if (type == 1)return std::string("city");
		else if (type == 2)return std::string("area");
		else if (type == 3)return std::string("area");
		return "";
	}
};
#endif // _AREADO_H_
