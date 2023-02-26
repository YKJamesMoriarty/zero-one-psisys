#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/2/19 16:41:00

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
#ifndef _PUR_COM_DAO_
#define _PUR_COM_DAO_

#include "BaseDAO.h"
#include "../../domain/do/PurCom/PurComDO.h"

/*
*	���ݿ����ʵ�� 
*/


class PurComDAO : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const PurComDO& obj);
	// ��ҳ��ѯ����
	list<PurComDO> selectPurCom(const PurComDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ָ��������ϸ
	
};

#endif // ! _PUR_COM_DAO_