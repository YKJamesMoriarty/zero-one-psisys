/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/2/19 20:46:24

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
#include "stdafx.h"
#include "BasMaterialDTO.h"
void from_json(const json& j, BasMaterialDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, id);
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
	//���ۼ۸�,double
	BIND_FROM_TO_D(j, t, salePrice);
	//˰�ر���
	BIND_FROM_TO_NORMAL(j, t, taxCode);


	// ����,1/0
	BIND_FROM_TO_I(j, t, isEnabled);
	// ��ע
	BIND_FROM_TO_NORMAL(j, t, remark);
	//// ����ʱ��
	//BIND_FROM_TO_NORMAL(j, t, createTime);
	//// ������
	//BIND_FROM_TO_NORMAL(j, t, createBy);
	//// �޸�ʱ��
	//BIND_FROM_TO_NORMAL(j, t, updateTime);
	//// �޸���
	//BIND_FROM_TO_NORMAL(j, t, updateBy);
}