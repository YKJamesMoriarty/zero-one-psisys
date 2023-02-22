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


#ifndef _MATERIALCLASSIFICATION_DO_
#define _MATERIALCLASSIFICATION_DO_
#include "../DoInclude.h"

/**
 * ���Ϸ������ݿ�ʵ����
 */
class MaterialClassificationDO  {

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

	//�汾
	CC_SYNTHESIZE(int, version, Version);
public:
	
};

#endif 


