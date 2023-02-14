#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/13 15:13

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
#ifndef _MATERIALVO_
#define _MATERIALVO

#include "../GlobalInclude.h"


class MaterialVO
{
	//���ϵ�id
	CC_SYNTHESIZE(uint64_t, id, Id);
	//���ϵı���
	CC_SYNTHESIZE(uint64_t, code, Code);
	//���ϵ�����
	CC_SYNTHESIZE(std::string, name, Name);
	//���ϵ�������
	CC_SYNTHESIZE(std::string, auxName, AuName);
	//���Ϸ����id
	CC_SYNTHESIZE(uint64_t, categoryId, CategoryId);
	//���Ϸ��������
	CC_SYNTHESIZE(std::string, categoryIdDictText, CategoryIdDictText);
	//����ͺ�
	CC_SYNTHESIZE(std::string, model, Model);
	//����λ
	CC_SYNTHESIZE(std::string, unitIdDictText, UnitIdDictText);
	//�۸�
	CC_SYNTHESIZE(uint64_t, price, Price);
	//˰�ر���
	CC_SYNTHESIZE(std::string, taxCode, TaxCode);
	//�Ƿ�����
	CC_SYNTHESIZE(std::string, isEnabledDictText, IsEnabledDictText);
	//��ע
	CC_SYNTHESIZE(std::string, remake, Remake);
	//����ʱ��
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	//������
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
public:
	BIND_TO_JSON(MaterialVO, id,code,name,auxName, categoryId, categoryIdDictText, model, unitIdDictText, 
		price, taxCode, isEnabledDictText, remake, createTime, createBy, updateTime, updateBy);

};

#endif //!_MATERIALVO_