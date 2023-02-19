#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Linsky
 @Date: 2023/2/13 20:31:04

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
#ifndef _DEPOT_VO_
#define _DEPOT_VO_

#include "../../GlobalInclude.h"

/**
 * �������ϲֿ�ģ��
 */
class DepotVO
{
	// Ψһֵ��id
	CC_SYNTHESIZE(string, id, Id);
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
	// ��JSONת������
	BIND_TO_JSON(DepotVO, id, name, code, auxName, phone,start,remarks,creationTime, creationPeo, modiTime, modiPeo);
};

class DepotDetailVO
{
	// �ϼ�
	CC_SYNTHESIZE(string, pid, Pid);
	// �¼�
	CC_SYNTHESIZE(string, next, Next);
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
public:
	// ��JSONת������
	BIND_TO_JSON(DepotDetailVO, pid, next, name, auxName, phone, start, remarks);
};

class DepotActionInfoVO
{
	// ����ʱ��
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	// ������
	CC_SYNTHESIZE(string, creationPeo, CreationPeo);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, modiTime, ModiTime);
	// �޸���
	CC_SYNTHESIZE(string, modiPeo, ModiPeo);
public:
	// ��JSONת������
	BIND_TO_JSON(DepotActionInfoVO, creationTime, creationPeo, modiTime, modiPeo);
};

#endif // !_DEPOT_VO_
