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
	CC_SYNTHESIZE(string, id, Id);
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
	CC_SYNTHESIZE(int, salePrice, SalePrice);
	//˰�ر���
	CC_SYNTHESIZE(string, taxCode, TaxCode);

	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	// ��JSONת������
	friend void from_json(const json& j, BasMaterialDTO& t) {// NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	// ����
		BIND_FROM_TO_NORMAL(j, t, code);
		// ����
		BIND_FROM_TO_NORMAL(j, t, name);
		// ������
		BIND_FROM_TO_NORMAL(j, t, auxName);

		// ���� ��Ҫ����һ����
		BIND_FROM_TO_NORMAL(j, t, categoryId);
		//����ͺ�
		BIND_FROM_TO_NORMAL(j, t, model);
		//����λ ��Ҫ����һ����
		BIND_FROM_TO_NORMAL(j, t, unitId);
		//���ۼ۸�
		BIND_FROM_TO_I(j, t, salePrice);
		//˰�ر���
		BIND_FROM_TO_NORMAL(j, t, taxCode);


		// ����
		BIND_FROM_TO_I(j, t, isEnabled);
		// ��ע
		BIND_FROM_TO_NORMAL(j, t, remark);
		// ����ʱ��
		BIND_FROM_TO_NORMAL(j, t, createTime);
		// ������
		BIND_FROM_TO_NORMAL(j, t, createBy);
		// �޸�ʱ��
		BIND_FROM_TO_NORMAL(j, t, updateTime);
		// �޸���
		BIND_FROM_TO_NORMAL(j, t, updateBy);
	}
	BIND_TO_JSON(BasMaterialDTO,id, code, name, auxName, categoryId, model, unitId, salePrice, taxCode, isEnabled, remark, createTime, createBy, updateTime, updateBy);
};

#endif // !_BASMATERIAL_DTO_