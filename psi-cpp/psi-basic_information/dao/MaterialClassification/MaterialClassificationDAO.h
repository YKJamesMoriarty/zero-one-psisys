#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _MATERIALCLASSIFICATION_DAO_
#define _MATERIALCLASSIFICATION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/MaterialClassification/MaterialClassificationDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
 /**
  * ʾ�������ݿ����ʵ��
  */
class MaterialClassificationDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MaterialClassificationDO& iObj);
	// ��ҳ��ѯ����
	list<MaterialClassificationDO> selectWithPage(const string& pid, uint64_t pageIndex, uint64_t pageSize);
	// ͨ��������ѯ����
	list<MaterialClassificationDO> selectByName(const string& name);

	// ͨ�������ѯ���� #�����ټ�
	list<MaterialClassificationDO> selectByCode(const string& code);

	// ͨ�����ڵ��ѯ����,����������ѯ�Ӽ��б�
	list<MaterialClassificationDO> selectByPid(const string& pid);

	//ͨ��id��ѯ����
	list<MaterialClassificationDO> selectById(const string& id);

	// ��������
	uint64_t insert(const MaterialClassificationDO& iObj);
	// �޸�����
	int update(const MaterialClassificationDO& uObj);
	//ͨ��id�޸��Ƿ����������
	int updateHasChildById(const string& id, const string child);
	// ͨ��IDɾ������
	int deleteById(string id);
	//ͨ��pidɾ������
	int deleteByPid(string pid);
	//Ӧ�û��и���������
};
#endif 
