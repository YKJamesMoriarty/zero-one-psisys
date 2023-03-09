#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/21 20:33

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
#ifndef _MATERIALRETURNDO_H_
#define _MATERIALRETURNDO_H_

#include "../../GlobalInclude.h"

class MaterialReturnDO
{
	//���ϵ�id
	CC_SYNTHESIZE(std::string, id, Id);
	//���ϵı���
	CC_SYNTHESIZE(std::string, code, Code);
	//���ϵ�����
	CC_SYNTHESIZE(std::string, name, Name);
	//���ϵ�������
	CC_SYNTHESIZE(std::string, auxName, AuxName);
	//���Ϸ����id
	CC_SYNTHESIZE(std::string, categoryId, CategoryId);
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
	CC_SYNTHESIZE(std::string, remark, Remark);
	//����ʱ��
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	//������
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	//�޸���
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
public:
	MaterialReturnDO()
	{
		id = "";
		code = "";
		name = "";
		auxName = "";
		categoryId = "";
		model = "";
		unitIdDictText = "";
		price = 0;
		taxCode = "";
		isEnabledDictText = "";
		remark = "";
		createBy = "";
	}
};

#endif // _MATERIALRETURNDO_H_