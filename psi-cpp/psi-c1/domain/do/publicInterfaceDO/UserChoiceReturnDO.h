#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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

#ifndef _USERCHOICERETURNDO_H_
#define _USERCHOICERETURNDO_H_

#include "../../GlobalInclude.h"

class UserChoiceReturnDO
{
	//�û�id
	CC_SYNTHESIZE(std::string, id, Id);
	//�û��˺�����
	CC_SYNTHESIZE(std::string, username, UserName);
	//�û���ʵ����
	CC_SYNTHESIZE(std::string, realname, RealName);
	//�û��Ա�
	CC_SYNTHESIZE(std::string, sex, Sex);
	//�û��绰
	CC_SYNTHESIZE(std::string, phone, Phone);
	//�û���������
	CC_SYNTHESIZE(std::string, department, DepartMent);
public:
	UserChoiceReturnDO()
	{
		id = "";
		username = "";
		realname = "";
		sex = "";
		phone = "";
		department = "";
	}
};

#endif // _USERCHOICERETURNDO_H_
