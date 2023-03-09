#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/20 20:45

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
#ifndef _USERCHOICEDAO_H_
#define _USERCHOICEDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/public-interface/UserChoiceQueryDO.h"
#include "../../domain/do/public-interface/UserChoiceReturnDO.h"


class UserChoiceDAO :public BaseDAO
{
public:
	//��ѯ�û���Ϣ
	list<UserChoiceReturnDO>selecUserWithPage(const UserChoiceQueryDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//����ͳ��һ����ѯ����Է��صı�������
	uint64_t count(const UserChoiceQueryDO& iObj);
};

#endif // _USERCHOICEDAO_H_