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


	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ���ڵ�
	CC_SYNTHESIZE(string, pid, Pid);
	// �Ƿ����ӽڵ�
	CC_SYNTHESIZE(string, has_child, HasChild);
	// ����
	CC_SYNTHESIZE(string, code, Code);
	//����
	CC_SYNTHESIZE(string, name, Name);
	//ȫ��
	CC_SYNTHESIZE(string, fullname, Fullname);

	//�Ƿ�����
	CC_SYNTHESIZE(int, is_enabled, IsEnabled);

	//����Ϊ������Ϣ���Զ����ɣ������ֶ��޸�
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);

	//������
	CC_SYNTHESIZE(string, create_by, CreateBy);

	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, UpdateTime);

	//�޸���
	CC_SYNTHESIZE(string, update_by, UpdateBy);

	//�汾 #�����ݿ����ǿյģ���֪����ʲô����
	CC_SYNTHESIZE(int, version, Version);
	

	//�Ӽ��ڵ�,���ݿ���û�У������ÿ���
	CC_SYNTHESIZE(list<MaterialClassificationDTO>, children, Children);

	
public:
	

	friend void from_json(const json& j, MaterialClassificationDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, pid);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_OBJ(j, t, children, list<MaterialClassificationDTO>);
		BIND_FROM_TO_NORMAL(j, t, has_child);
		BIND_FROM_TO_NORMAL(j, t, name);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, fullname);
		BIND_FROM_TO_I(j, t, is_enabled);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, create_by);
		BIND_FROM_TO_NORMAL(j, t, update_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);
		BIND_FROM_TO_I(j, t, version);
	}

	BIND_TO_JSON(MaterialClassificationDTO,id, pid, has_child, name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};




#endif

