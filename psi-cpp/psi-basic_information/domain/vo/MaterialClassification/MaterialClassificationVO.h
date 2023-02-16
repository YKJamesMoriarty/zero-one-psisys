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

#ifndef _MaterialClassification_VO_
#define _MaterialClassification_VO_
#include "../../GlobalInclude.h"

/*
* �����������Ϸ���ģ��
*/

//��ͨ��ѯ�����ڵ��б�����
class MaterialClassificationVO{
	

	//����
	CC_SYNTHESIZE(string, name, Name);

	//����
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

	MaterialClassificationVO() : name("nanan"), id(11) {}
	

	// ��JSONת������
	BIND_TO_JSON(MaterialClassificationVO, name,id, 
								fullName, enable, creationTime, creatorName, modifyTime, modifyName);
};


//��ѯָ�������Ӽ��б����
class MaterialClassificationNextListVO {

	//���ڵ�
	CC_SYNTHESIZE(string, base, Base);

	//�Ƿ����¼�
	CC_SYNTHESIZE(bool, hasChild, HasChild);

	//����
	CC_SYNTHESIZE(string, name, Name);

	//����
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
	BIND_TO_JSON(MaterialClassificationNextListVO,base,hasChild, name, id,
		fullName, enable, creationTime, creatorName, modifyTime, modifyName);
};

//��ѯָ��������ϸ��Ϣ����
class MaterialClassificationDetailVO {

	
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
	BIND_TO_JSON(MaterialClassificationDetailVO,creationTime, creatorName, modifyTime, modifyName);
};
#endif
