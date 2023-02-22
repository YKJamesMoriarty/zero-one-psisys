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

#ifndef _MATERIALCLASSIFICATION_VO_
#define _MATERIALCLASSIFICATION_VO_
#include "../../GlobalInclude.h"

/*
* �����������Ϸ���ģ��
*/

//��ͨ��ѯ�����ڵ��б�����
class MaterialClassificationBaseVO{

	
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

public:

	
	

	// ��JSONת������
	BIND_TO_JSON(MaterialClassificationBaseVO, name,code, 
								fullname, is_enabled, create_time, create_by, update_time, update_by);
};


//��ѯָ�������Ӽ��б����
class MaterialClassificationChildVO {



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



public:
	// ��JSONת������
	BIND_TO_JSON(MaterialClassificationChildVO, name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};

//��ѯָ��������ϸ��Ϣ����
class MaterialClassificationDetailVO {

	
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


public:
	// ��JSONת������
	BIND_TO_JSON(MaterialClassificationDetailVO, pid,has_child,code,name,fullname,is_enabled,create_time, create_by, update_time, update_by);
};


//�½�����
class AddMaterialClassificationVO {


	// ���ڵ� #����¼�ʱ���ܻ��õ�
	CC_SYNTHESIZE(string, pid, Pid);
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


public:

	// ��JSONת������
	BIND_TO_JSON(AddMaterialClassificationVO, pid,name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};


//�޸ķ���
class ModifyMaterialClassificationVO {


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

public:

	// ��JSONת������
	BIND_TO_JSON(ModifyMaterialClassificationVO, name, code,
		fullname, is_enabled, create_time, create_by, update_time, update_by);

};

//ɾ������


#endif


