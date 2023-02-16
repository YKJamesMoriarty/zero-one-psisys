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
class MaterialClassificationBaseVO{

	//����
	CC_SYNTHESIZE(string, name, Name);

	//����
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

	MaterialClassificationBaseVO() : name("nanan"), code(11) {}
	

	// ��JSONת������
	BIND_TO_JSON(MaterialClassificationBaseVO, name,code, 
								fullname, is_enabled, create_time, create_by, update_time, update_by);
};


//��ѯָ�������Ӽ��б����
class MaterialClassificationChildVO {

	//���ڵ�
	CC_SYNTHESIZE(uint64_t, pid, Pid);

	//����
	CC_SYNTHESIZE(string, name, Name);

	//����
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
	// ��JSONת������
	BIND_TO_JSON(MaterialClassificationChildVO, pid, name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};

//��ѯָ��������ϸ��Ϣ����
class MaterialClassificationDetailVO {

	
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
	// ��JSONת������
	BIND_TO_JSON(MaterialClassificationDetailVO, create_time, create_by, update_time, update_by);
};


//�½�����
class AddMaterialClassificationVO {

	//���ڵ�
	CC_SYNTHESIZE(uint64_t, pid, Pid);

	//����
	CC_SYNTHESIZE(string, name, Name);

	//����
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

	// ��JSONת������
	BIND_TO_JSON(AddMaterialClassificationVO, pid,name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};

#endif


