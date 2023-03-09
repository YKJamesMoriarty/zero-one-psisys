#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/20 19:32

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

#ifndef _USERCHOICEQUERYDO_H_
#define _USERCHOICEQUERYDO_H_

#include "../../GlobalInclude.h"

class UserChoiceQueryDO
{
	//查询用户数据时用的用户账号名称
	CC_SYNTHESIZE(std::string, username, UserName);
public:
	UserChoiceQueryDO()
	{
		username = "";
	}
};

#endif // _USERCHOICEQUERYDO_H_
