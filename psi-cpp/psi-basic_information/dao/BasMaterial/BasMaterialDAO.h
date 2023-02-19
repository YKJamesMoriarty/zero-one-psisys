#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/19 12:23:49

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
#ifndef _BASMATERIAL_DAO_
#define _BASMATERIAL_DAO_
#include "BaseDAO.h"
#include "../../psi-basic_information/domain/do/BasMaterial/BasMaterialDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class BasMaterialDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const BasMaterialDO& iObj);
	// ��ҳ��ѯ����
	list<BasMaterialDO> selectWithPage(const BasMaterialDO& obj, uint64_t pageIndex, uint64_t pageSize);
	
	// ͨ�����Ʋ�ѯ����
	list<BasMaterialDO> selectByName(const string& name);
	// ͨ�������ѯ����
	list<BasMaterialDO> selectByCode(const string& code);
	// ͨ�����Ϸ����ѯ����
	list<BasMaterialDO> selectByCategoryId(const string& categoryId);

	// �½�����
	uint64_t insert(const BasMaterialDO& iObj);
	// �޸�����
	int update(const BasMaterialDO& uObj);
	// ͨ��code����ɾ������
	int deleteById(string id);
};
#endif // !_BASMATERIAL_DAO_
