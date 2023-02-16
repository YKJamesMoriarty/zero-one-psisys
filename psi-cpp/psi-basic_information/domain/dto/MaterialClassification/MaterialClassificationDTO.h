#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyi
 @Date: 2023/2/13 15:40:04

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



#ifndef _MATERIALCLASSIFICATION_DTO_
#define _MATERIALCLASSIFICATION_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
/*
* �����������Ϸ���ģ��
*/

class MaterialClassificationDTO :public FileDTO {


	//���ݿ����У�������
	CC_SYNTHESIZE(uint64_t, id, Id);

	//���ڵ㣬�ñ����ʾ
	CC_SYNTHESIZE(uint64_t, pid, pid);
	

	//�Ӽ��ڵ�,���ݿ���û�У������ÿ���
	CC_SYNTHESIZE(list<MaterialClassificationDTO>, children, Children);

	//�Ƿ����ӽڵ�
	CC_SYNTHESIZE(bool, has_child, HasChild);

	//����
	CC_SYNTHESIZE(string, name, Name);

	//���
	CC_SYNTHESIZE(uint64_t, code, Code);

	//ȫ��
	CC_SYNTHESIZE(string, fullname, FuLLname);

	//�Ƿ�����
	CC_SYNTHESIZE(bool, is_enabled, IsEnabled);


	//����Ϊ������Ϣ���Զ����ɣ������ֶ��޸�
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);

	//������
	CC_SYNTHESIZE(string, create_by, CreateBy);

	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, updateTime);

	//�޸���
	CC_SYNTHESIZE(string, update_by, updateBy);

public:
	

	friend void from_json(const json& j, MaterialClassificationDTO& t) { // NOLINT
		BIND_FROM_TO_LL(j, t, pid);
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_OBJ(j, t, children, list<MaterialClassificationDTO>);
		BIND_FROM_TO_B(j, t, has_child);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, fullname);
		BIND_FROM_TO_B(j, t, is_enabled);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, create_by);
		BIND_FROM_TO_NORMAL(j, t, update_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);

	}

	BIND_TO_JSON(MaterialClassificationDTO,id, pid, has_child, name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};


/*class MaterialClassificationDTO {
	
	//��/���ڵ㣬�ñ����ʾ
	CC_SYNTHESIZE(long long, base, Base);

	//�Ӽ��ڵ㣬�ñ����ʾ�Ӽ�ʵ��
	CC_SYNTHESIZE(list<MaterialClassification1DTO>, children, Children);

	//�Ƿ����ӽڵ�
	CC_SYNTHESIZE(bool, hasChild, HasChild);

	//����
	CC_SYNTHESIZE(string, name, Name);

	//���
	CC_SYNTHESIZE(uint64_t, id, Id);

	//ȫ��
	CC_SYNTHESIZE(string, fullName, FuLLName);

	//�Ƿ�����
	CC_SYNTHESIZE(bool, enable, Enable);


	//����Ϊ������Ϣ���Զ����ɣ������ֶ��޸�
	//����ʱ��
	CC_SYNTHESIZE(string, creationTime, CreationTime);

	//������
	CC_SYNTHESIZE(string, creatorName, CreatorName);

	//�޸�ʱ��
	CC_SYNTHESIZE(string, modifyTime, ModifyTime);

	//�޸���
	CC_SYNTHESIZE(string, modifyName, ModifyName);

public:
	// ��JSONת������
	friend void from_json(const json& j, MaterialClassificationDTO& t) { // NOLINT

		BIND_FROM_TO_LL(j, t, base);
		BIND_FROM_TO_OBJ(j, t, children, list<MaterialClassificationDTO>)
		BIND_FROM_TO_B(j, t, hasChild);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_ULL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, fullName);
		BIND_FROM_TO_B(j, t, enable);
		BIND_FROM_TO_NORMAL(j, t, creationTime);
		BIND_FROM_TO_NORMAL(j, t, creatorName);
		BIND_FROM_TO_NORMAL(j, t, modifyTime);
		BIND_FROM_TO_NORMAL(j, t, modifyName);

	}

	BIND_TO_JSON(MaterialClassificationDTO, base,hasChild, name, id,
						fullName, enable, creationTime, creatorName, modifyTime, modifyName);
};
*/

#endif

