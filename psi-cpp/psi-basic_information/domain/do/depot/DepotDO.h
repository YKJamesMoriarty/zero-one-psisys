#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _DEPOT_DO_
#define _DEPOT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class DepotDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// Pid
	CC_SYNTHESIZE(string, pid, Pid);
	// �Ӽ�
	CC_SYNTHESIZE(string, hasChild, HasChild);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ���
	CC_SYNTHESIZE(string, code, Code);
	// ������
	CC_SYNTHESIZE(string, auxName, AuxName);
	// �绰
	CC_SYNTHESIZE(int, phone, Phone);
	// ����
	CC_SYNTHESIZE(string, start, Start);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	// ����ʱ��
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	// ������
	CC_SYNTHESIZE(string, creationPeo, CreationPeo);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, modiTime, ModiTime);
	// �޸���
	CC_SYNTHESIZE(string, modiPeo, ModiPeo);
public:
	DepotDO() {
		id = "";
		pid = "";
		name = "Depot";
		code = "12345678910";
	}
};

#endif // !_DEPOT_DO_
