#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/15 21:00

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
#ifndef _BASMATERIAL_DTO_
#define _BASMATERIAL_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * ������������ģ�鴫�����
 */
class BasMaterialDTO : public FileDTO
{
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���� ��Ҫ����һ����
	CC_SYNTHESIZE(string, categoryId, CategoryId);
	// ����
	CC_SYNTHESIZE(string, code, Code);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ������
	CC_SYNTHESIZE(string, auxName, AuxName);
	// ����
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);

	//����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	//����λ ��Ҫ����һ����
	CC_SYNTHESIZE(string, unitId, UnitId);

	//���ۼ۸�
	CC_SYNTHESIZE(double, salePrice, SalePrice);
	//˰�ر���
	CC_SYNTHESIZE(string, taxCode, TaxCode);

	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//// ����ʱ��
	//CC_SYNTHESIZE(string, createTime, CreateTime);
	//// ������
	//CC_SYNTHESIZE(string, createBy, CreateBy);
	//// �޸���
	//CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//// �޸�ʱ��
	//CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	// ��JSONת������
	friend void from_json(const json& j, BasMaterialDTO& t);// NOLINT
	BIND_TO_JSON(BasMaterialDTO, id, categoryId, code, name, auxName, isEnabled, model, unitId, salePrice, taxCode, isEnabled, remark);
};

#endif // !_BASMATERIAL_DTO_