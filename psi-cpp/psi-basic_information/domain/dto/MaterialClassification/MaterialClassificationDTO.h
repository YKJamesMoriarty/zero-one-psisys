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

#include "../../GlobalInclude.h"


#ifndef _MATERIALCLASSIFICATION_DTO_
#define _MATERIALCLASSIFICATION_DTO_

/*
* �����������Ϸ���ģ��
*/
class MaterialClassificationDTO {
	
	//��/���ڵ㣬�ñ����ʾ
	CC_SYNTHESIZE(long long, base, Base);

	//�Ӽ��ڵ㣬�ñ����ʾ�Ӽ�ʵ��
	CC_SYNTHESIZE(list<uint64_t>, children, Children);

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
	void from_json(const json& j, MaterialClassificationDTO& t) { // NOLINT

		BIND_FROM_TO_LL(j, t, base);
		BIND_FROM_TO_OBJ(j, t, children, list<uint64_t>);
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

	BIND_TO_JSON(MaterialClassificationDTO, base, children,hasChild, name, id,
						fullName, enable, creationTime, creatorName, modifyTime, modifyName);
};


#endif

